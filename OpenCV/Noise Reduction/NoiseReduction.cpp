//영상처리 과제2 Noise Reduction 201721103김소민
//opnecv version 4.1.0
#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;


int main()
{
	Mat image_s = imread("C:/Users/Ksm/source/repos/openCV/NoiseReduction_TestImages/salt_0.15.png", IMREAD_GRAYSCALE);
	Mat image_p = imread("C:/Users/Ksm/source/repos/openCV/NoiseReduction_TestImages/pepper_0.15.png", IMREAD_GRAYSCALE);
	Mat image_g = imread("C:/Users/Ksm/source/repos/openCV/NoiseReduction_TestImages/Gaussian_0.20.png", IMREAD_GRAYSCALE);
	Mat image_sp = imread("C:/Users/Ksm/source/repos/openCV/NoiseReduction_TestImages/salt_pepper_0.15.png", IMREAD_GRAYSCALE); //36:57
	Mat image_u = imread("C:/Users/Ksm/source/repos/openCV/NoiseReduction_TestImages/uniform_0.20.png", IMREAD_GRAYSCALE);
	
	//Result
	//salt_noise
	medianBlur(image_s, image_s, 5);
	imshow("salt noise Result", image_s);
	//pepper_noise
	medianBlur(image_p, image_p, 5);
	imshow("pepper noise Result", image_p);
	//saltPepper_noise
	medianBlur(image_sp, image_sp, 5);
	imshow("salt-pepper noise Result", image_sp);
	//gaussian_noise
	GaussianBlur(image_g, image_g, Size(5, 5), 1.5);
	imshow("gaussian noise Result", image_g);
	//uniform_noise
	GaussianBlur(image_u, image_u, Size(5, 5), 1.5);
	imshow("uniform noise Result", image_u);

	waitKey();
}


