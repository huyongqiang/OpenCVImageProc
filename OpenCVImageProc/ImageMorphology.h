#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>

using namespace cv;

class ImageMorphology {
public:
	// ��̬ѧ��ʴ����
	Mat erodeImage(Mat srcImage,int ksize);
	// ��̬ѧ���Ͳ���
	Mat dilateImage(Mat srcImage, int ksize);
};
