#include"ImageMorphology.h"

// ��̬ѧ��ʴ����
Mat ImageMorphology::erodeImage(Mat srcImage, int ksize) {
	Mat dstImage;
	Mat element = getStructuringElement(MORPH_RECT, Size(ksize, ksize));
	erode(srcImage, dstImage, element);
	return dstImage;
}

// ��̬ѧ���Ͳ���
Mat ImageMorphology::dilateImage(Mat srcImage, int ksize) {
	Mat dstImage;
	Mat element = getStructuringElement(MORPH_RECT, Size(ksize, ksize));
	dilate(srcImage, dstImage, element);
	return dstImage;
}