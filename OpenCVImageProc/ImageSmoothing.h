#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>

using namespace cv;

class ImageSmoothing {
public:
	// ���Է����˲�
	Mat boxFilterImage(Mat srcImage, int ksize);
	// ���Ծ�ֵ�˲�
	Mat blurImage(Mat srcImage,int ksize);
	// ���Ը�˹�˲�
	Mat gaussianBlurImage(Mat srcImage,int ksize);
	// ��������ֵ�˲�
	Mat mediaBlurImage(Mat srcImage,int ksize);
	// ������˫���˲�
	// dΪÿ�����������ֱ����sigmaColorΪ��ɫ�ռ��˲���sigma
	Mat bilateralFilterImage(Mat srcImage,int d, double sigmaColor,double sigmaSpace);
}; 
