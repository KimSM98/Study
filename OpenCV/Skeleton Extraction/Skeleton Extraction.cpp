//Skeleton Extraction
//opnecv version 4.1.0
#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace cv;

Mat Skeletonization(Mat normalImg) {
	Mat A;
	bitwise_not(normalImg, A, noArray());
	Mat S(A.size(), CV_8UC1, Scalar(0));
	Mat T(A.size(), CV_8UC1);
	Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3));

	bool done;
	do {
		morphologyEx(A, T, MORPH_OPEN, element);
		bitwise_not(T, T);
		bitwise_and(A, T, T);
		bitwise_or(S, T, S);
		erode(A, A, element);

		double max;
		minMaxLoc(A, 0, &max);
		done = (max == 0);
	} while (!done);
	return S;
}

int main()
{
	Mat image1 = imread("C:/Users/Ksm/source/repos/openCV/sk1.png", IMREAD_GRAYSCALE); //36:57
	Mat image2 = imread("C:/Users/Ksm/source/repos/openCV/sk2.png", IMREAD_GRAYSCALE); //36:57
	Mat image3 = imread("C:/Users/Ksm/source/repos/openCV/sk3.png", IMREAD_GRAYSCALE); //36:57

	Mat resultImg1 = Skeletonization(image1);
	Mat resultImg2 = Skeletonization(image2);
	Mat resultImg3 = Skeletonization(image3);

	imshow("Normal Image1", image1);
	imshow("Normal Image2", image2);
	imshow("Normal Image3", image3);

	imshow("Result1", resultImg1);	
	imshow("Result2", resultImg2);	
	imshow("Result3", resultImg3);

	waitKey();
}

					

