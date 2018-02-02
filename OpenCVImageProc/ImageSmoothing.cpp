/*
* ������ͼ��ȥ��(ƽ��)����
* Created by Jiangdongguo on 2018.2.2
*/

#include "ImageSmoothing.h"

// ���Է����˲�
Mat ImageSmoothing::boxFilterImage(Mat srcImage, int ksize) {
	Mat dstImage;
	if (ksize >= 0) {
		boxFilter(srcImage, dstImage, -1, Size(ksize, ksize));
	}
	return dstImage;
}

// ���Ծ�ֵ�˲�
Mat ImageSmoothing::blurImage(Mat srcImage, int ksize) {
	Mat dstImage;
	blur(srcImage, dstImage, Size(ksize, ksize));
	return dstImage;
}

// ���Ը�˹�˲�
Mat ImageSmoothing::gaussianBlurImage(Mat srcImage, int ksize) {
	Mat dstImage;
	GaussianBlur(srcImage, dstImage, Size(ksize, ksize), 0, 0);
	return dstImage;
}

// ��������ֵ�˲�
Mat ImageSmoothing::mediaBlurImage(Mat srcImage, int ksize) {
	Mat dstImage;
	medianBlur(srcImage, dstImage, ksize);
	return dstImage;
}

// ������˫���˲�
Mat ImageSmoothing::bilateralFilterImage(Mat srcImage, int d, double sigmaColor, double sigmaSpace) {
	Mat dstImage;
	bilateralFilter(srcImage, dstImage, d, sigmaColor, sigmaSpace);
	return dstImage;
}