#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>
#include"ImageSmoothing.h"
#include"ImageMorphology.h"

using namespace cv;

int main() {
	ImageSmoothing smooth;
	ImageMorphology morphology;
	
	// ����ԭͼ
	Mat srcImage = imread("hashiqi.jpg");
	namedWindow("ԭʼͼƬ");
	imshow("ԭʼͼƬ", srcImage);

	/*-------------------------------------------------------------
	 *  ������ ���з����˲�������ģ������
	 *   ksizeԽ��ģ��Ч��Խ����
	 *-------------------------------------------------------------*/
//	imshow("�����˲�����", smooth.boxFilterImage(srcImage,5));
//	imshow("��ֵ�˲�����", smooth.blurImage(srcImage, 7));
//	imshow("��˹�˲�����", smooth.gaussianBlurImage(srcImage, 5));
//	imshow("��ֵ�˲�����", smooth.mediaBlurImage(srcImage, 7));
//	imshow("˫���˲�����",smooth.bilateralFilterImage(srcImage,25,25*2,25/2));

	/*-------------------------------------------------------------
	*  ������ ��̬ѧϵ�в���
	*-------------------------------------------------------------*/
	imshow("��ʴ����", morphology.erodeImage(srcImage, 15));
	imshow("���Ͳ���", morphology.dilateImage(srcImage, 15));
	waitKey(0);
	return 0;
}