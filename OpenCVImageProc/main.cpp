#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>
#include<stdio.h>
#include<iostream>
#include"ImageSmoothing.h"
#include"ImageMorphology.h"

void smoothOperator();

using namespace cv;
using namespace std;

ImageSmoothing smooth;
ImageMorphology morphology;

int main() {
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

void smoothOperator() {
	Mat dstBox, dstBlur, dstGussian, dstMedia, dstBilateral;
	Mat srcImage = imread("yuwenwen.jpg");
	namedWindow("ԭʼͼƬ");
	imshow("ԭʼͼƬ", srcImage);
	smooth.boxFilterImage(srcImage, dstBox, 3);
	smooth.blurImage(srcImage, dstBlur, 3);
	smooth.gaussianBlurImage(srcImage, dstGussian, 3);
	smooth.mediaBlurImage(srcImage, dstMedia,3);
	smooth.bilateralFilterImage(srcImage, dstBilateral, 25, 25 * 2, 25 / 2);
	imshow("�����˲�����", dstBox);
	imshow("��ֵ�˲�����", dstBlur);
	imshow("��˹�˲�����", dstGussian);
	imshow("��ֵ�˲�����", dstMedia);
	imshow("˫���˲�����", dstBilateral);
}