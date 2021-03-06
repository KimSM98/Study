//Image Processing_Histogram Equalization
//Somin Kim
//opnecv version 4.1.0
#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace cv;

Mat imageF;
Mat image3;

int gain = 100;
int bias = 100;

void Apply(int, void*, Mat image) {
	int histogram[256] = { 0, }, cumhist[256] = { 0, };

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			int value = image.at<uchar>(y, x);
			histogram[value] += 1;
		}
	}
	
	int sum = 0;

	for (int i = 1; i < 256; i++) {
		sum += histogram[i];
		cumhist[i] = sum;
	}
	
	float normalCumhist[256] = { 0.0, };
	int imgSize = image.rows*image.cols;

	for (int i = 0; i < 256; i++) {
		normalCumhist[i] = cumhist[i] / float(imgSize);
	}

	Mat image1 = Mat(image.rows, image.cols, CV_8U);
	int hist2[256] = { 0, };
	
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			image1.at<uchar>(y, x) = normalCumhist[image.at<uchar>(y, x)] * 255;
			hist2[image1.at<uchar>(y, x)] += 1;
		}
	}
	
	imshow("Result", image1);
}

int main()
{
	Mat image = imread("C:/Users/Ksm/source/repos/OpenCV_HistogramEqualizationTest/450px-Unequalized_Hawkes_Bay_NZ.jpg", IMREAD_GRAYSCALE); //36:57
	
	imshow("NormalImage", image);

	Apply(100, nullptr, image);

	waitKey();
}
