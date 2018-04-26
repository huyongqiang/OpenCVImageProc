#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>

using namespace cv;

class ImageSmoothing {
public:
	// ���Է����˲�
	void boxFilterImage(Mat srcImage, Mat &dstImage, int ksize);
	// ���Ծ�ֵ�˲�
	void blurImage(Mat srcImage, Mat &dstImage,int ksize);
	// ���Ը�˹�˲�
	void gaussianBlurImage(Mat srcImage, Mat &dstImage,int ksize);
	// ��������ֵ�˲�
	void mediaBlurImage(Mat srcImage, Mat &dstImage,int ksize);
	// ������˫���˲�
	// dΪÿ�����������ֱ����sigmaColorΪ��ɫ�ռ��˲���sigma
	void bilateralFilterImage(Mat srcImage, Mat &dstImage,int d, double sigmaColor,double sigmaSpace);
}; 
