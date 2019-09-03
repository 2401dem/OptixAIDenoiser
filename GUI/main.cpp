#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <algorithm>
#include <string>

#define CVUI_IMPLEMENTATION

using namespace std;
using namespace cv;
#include "denoiser.h"

#define WINDOW_NAME "CVUI Test"

const int windowWidth = 1280;
const int windowHeight = 720;



/*int main()
{
	cvui::init(WINDOW_NAME);
	Mat frame = Mat(Size(windowWidth, windowHeight), CV_8UC3);
	Mat imageBox = Mat(Size(windowWidth, windowHeight), CV_8UC3);

	
	Mat img = imread("test.png", IMREAD_UNCHANGED);


	Mat abd = imread("albedo.png", IMREAD_UNCHANGED);
	Mat nml = imread("normal.png", IMREAD_UNCHANGED);
	fillImageBox(img, imageBox);
	
	while (cv::getWindowProperty(WINDOW_NAME, 0) >= 0) 
	{
		// your app logic here

		
		frame = cv::Scalar(49, 52, 49);		

		if (cvui::button(frame, 40, 40, "Button")) {
			// button was clicked
			
			img.convertTo(img, CV_32F, getAlphaTo32F(img));
			cvtColor(img, img, CV_BGR2RGBA);

			abd.convertTo(abd, CV_32F, getAlphaTo32F(abd));
			cvtColor(abd, abd, CV_BGR2RGBA);

			nml.convertTo(nml, CV_32F, getAlphaTo32F(nml));
			cvtColor(nml, nml, CV_BGR2RGBA);

			int depth = getBitDepth(img);

			cout << "depth: " << depth << endl;
			img = denoise_impl(img, abd, nml, 0, 1);

			cvtColor(img, img, CV_RGBA2BGR);
			fillImageBox(img, imageBox);

		}
		//cvGetWindowHandle
		
		cvui::image(frame, 520, (windowHeight - imageBox.rows) / 2, imageBox);
		cvui::update();
		cvui::imshow(WINDOW_NAME, frame);
		if (cv::waitKey(20) == 27) {
			break;
		}
	}



	
	
	//imwrite("test.png", img);
	
	return 0;
}*/

