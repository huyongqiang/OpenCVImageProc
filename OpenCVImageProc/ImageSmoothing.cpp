/*
* ������ͼ��ȥ��(ƽ��)����
* Created by Jiangdongguo on 2018.2.2
*/

#include "ImageSmoothing.h"

// ���Է����˲�
void ImageSmoothing::boxFilterImage(Mat srcImage, Mat &dstImage,int ksize) {
	if (ksize <= 0) {
		printf("ksize should be > 0, and the best to be odd number like 1,3,5,7...\n");
		return;
	}
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	boxFilter(srcImage, dstImage, -1, Size(ksize, ksize));
}

// ���Ծ�ֵ�˲�
void ImageSmoothing::blurImage(Mat srcImage, Mat &dstImage, int ksize) {
	if (ksize <= 0) {
		printf("ksize should be > 0, and the best to be odd number like 1,3,5,7...\n");
		return;
	}
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	blur(srcImage, dstImage, Size(ksize, ksize));;
}

// ���Ը�˹�˲�
void ImageSmoothing::gaussianBlurImage(Mat srcImage, Mat &dstImage, int ksize) {
	if (ksize <= 0) {
		printf("ksize should be > 0, and the best to be odd number like 1,3,5,7...\n");
		return;
	}
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	GaussianBlur(srcImage, dstImage, Size(ksize, ksize), 0, 0);
}

// ��������ֵ�˲�
void ImageSmoothing::mediaBlurImage(Mat srcImage, Mat &dstImage, int ksize) {
	if (ksize <= 0) {
		printf("ksize should be > 0, and the best to be odd number like 1,3,5,7...\n");
		return;
	}
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	medianBlur(srcImage, dstImage, ksize);
}

// ������˫���˲�
void ImageSmoothing::bilateralFilterImage(Mat srcImage, Mat &dstImage, int d, double sigmaColor, double sigmaSpace) {
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	bilateralFilter(srcImage, dstImage, d, sigmaColor, sigmaSpace);
}