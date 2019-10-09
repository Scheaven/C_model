#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
 
 
int main()
{
	Mat image = imread("rotate.jpg");
	Mat out ;	
	GaussianBlur(image,out,Size(3,3),4);	
	imshow("GaussianBlur",out);
	//imwrite("blur.jpg",out);
	waitKey();
	return 0;
}
