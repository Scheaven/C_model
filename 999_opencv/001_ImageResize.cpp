#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void imageResize(Mat image, Mat* dst, int width, int height, int inter = CV_INTER_AREA)
{

	int w = image.cols;
	int h = image.rows;
	int newW = width;
	int newH = height;
	if (width == 0 && height == 0) {
		return;
	}
	if (width == 0) {
		float re = h / (float)height;
		newW = (int)w * re;
	}
	else {
		float re = w / (float)width;
		newH = (int)h * re;;
	}

	resize(image, *dst, Size(newW, newH), inter);


}

int main()
{
	const char* filename = "111.png";
	Mat image, dst;
	//image = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
	image = imread(filename, CV_LOAD_IMAGE_COLOR);
	if (image.empty()) {
		std::cout << "Faild open file.";
	}
	//imshow("image", image);
	//image.cols为图像的宽度 image.cols为图像的高度
	int w = image.cols;
	int h = image.rows;
	std::cout << "Image size:" << w << " * " << h << std::endl;
	imageResize(image, &dst, w * 2, h * 2);

	std::cout << "new Image size:" << dst.cols << " * " << dst.rows << std::endl;
	vector<int> compression_params;
	//JPEG，参数为CV_IMWRITE_JPEG_QUALITY，值是从0到100，值越小压缩的越多
	compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
	compression_params.push_back(100);
	//imshow("dstImage", dst);
	imwrite("dstImage.jpg", dst, compression_params);


	return 0;
}
