#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>
#include<stdio.h>
#include<iostream>
#include"ImageSmoothing.h"
#include"ImageMorphology.h"

void testCopyMakeBorder(int type);
void resizeBrightnessAndContrast(int a, int b);
void smoothOperator();
void addSaltNoise(Mat &image, int n);

using namespace cv;
using namespace std;

ImageSmoothing smooth;
ImageMorphology morphology;

int main() {
	// BORDER_DEFAULT
	// BORDER_CONSTANT
	// BORDER_WRAP
//	testCopyMakeBorder(BORDER_REPLICATE);
	/*-------------------------------------------------------------
	*  �����ӣ��������ȺͶԱȶ�
	*-------------------------------------------------------------*/
	//resizeBrightnessAndContrast(1,100);
	/*-------------------------------------------------------------
	 *  ������ ���з����˲�������ģ������
	 *   ksizeԽ��ģ��Ч��Խ����
	 *-------------------------------------------------------------*/
	smoothOperator();

	/*-------------------------------------------------------------
	*  ������ ��̬ѧϵ�в���
	*-------------------------------------------------------------*/
//	imshow("��ʴ����", morphology.erodeImage(srcImage, 15));
//	imshow("���Ͳ���", morphology.dilateImage(srcImage, 15));
	waitKey(0);
	return 0;
}

void testCopyMakeBorder(int type) {
	Mat src, dst;
	src = imread("hashiqi.jpg");
	if (!src.data) {
		printf("����Դͼ��ʧ��");
	}
	namedWindow("Դͼ��");
	imshow("Դͼ��", src);
	// Ҫ�����Ե��������(�����ã����Զ���)
	int top = (int)(0.05*src.rows);
	int bottom = (int)(0.05*src.rows);
	int left = (int)(0.05*src.cols);
	int right = (int)(0.05*src.cols);
	// ��Ե�����̶������ɫΪ��ɫ(OpenCVĬ��ΪBGR)
	copyMakeBorder(src, dst, top, bottom, left, right, type, Scalar(255,0,0));

	imshow("BORDER_REPLICATEЧ��",dst);
}

void resizeBrightnessAndContrast(int a, int b) {
	Mat src, dst;
	src = imread("yuwenwen.jpg");
	if (!src.data) {
		printf("����Դͼ��ʧ��");
	}
	namedWindow("Դͼ��");
	imshow("Դͼ��", src);
	// dst����ߴ硢����������Դͼ��һ�£�����ʼ������
	dst = Mat::zeros(src.size(), src.type());
	// �����������أ�ʹ�õ����Ӵ���
	// g(i,j) = a*f(i,j) + b;
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			if (src.channels() == 1) {
				// �Ҷ�ͼ��
				dst.at<uchar>(i, j) = saturate_cast<uchar>(a*src.at<uchar>(i, j) + b);
			}
			else {
				// ��ɫͼ��
				for (int channel = 0; channel < src.channels(); channel++) {
					dst.at<Vec3b>(i, j)[channel] = saturate_cast<uchar>(a*src.at<Vec3b>(i, j)[channel] + b);
				}
			}
		}
	}
	imshow("a=1,b=100Ч��ͼ", dst);
}

void smoothOperator() {
	Mat dstBox, dstBlur, dstGussian, dstMedia, dstBilateral;
	Mat saltNoise,gussianNoise;
	Mat srcImage = imread("yuwenwen.jpg");
	namedWindow("ԭʼͼƬ");
	imshow("ԭʼͼƬ", srcImage);
//	smooth.boxFilterImage(srcImage, dstBox, 5);
//	smooth.blurImage(srcImage, dstBlur, 5);
//	smooth.gaussianBlurImage(srcImage, dstGussian, 5);
//	imshow("�����˲�����", dstBox);
//	imshow("��ֵ�˲�����", dstBlur);
//	imshow("��˹�˲�����", dstGussian);
	smooth.bilateralFilterImage(srcImage, dstBilateral, 25, 25 * 2, 25 / 2);
	imshow("˫���˲�����", dstBilateral);
/* ��ֵ�˲�����������
	srcImage.copyTo(saltNoise);
	addSaltNoise(saltNoise, 250);
	smooth.mediaBlurImage(saltNoise, dstMedia, 3);
	imshow("��ӽ�������", saltNoise);
	imshow("��˹�˲�����", dstMedia);
*/
}

// ��ӽ���������nΪ����������
void addSaltNoise(Mat &image, int n){
	// ��Ӱ׵�
	for (int k = 0; k<n; k++)
	{
		int i = rand() % image.cols;
		int j = rand() % image.rows;
		if (image.channels() == 1){
			image.at<uchar>(j, i) = 255;
		}
		else if (image.channels() == 3){
			image.at<Vec3b>(j, i)[0] = 255;
			image.at<Vec3b>(j, i)[1] = 255;
			image.at<Vec3b>(j, i)[2] = 255;
		}
	}
	// ��Ӻڵ�
	for (int k = 0; k<n; k++)
	{
		int i = rand() % image.cols;
		int j = rand() % image.rows;
		if (image.channels() == 1) {
			image.at<uchar>(j, i) = 0;
		}
		else if (image.channels() == 3) {
			image.at<Vec3b>(j, i)[0] = 0;
			image.at<Vec3b>(j, i)[1] = 0;
			image.at<Vec3b>(j, i)[2] = 0;
		}
	}
}