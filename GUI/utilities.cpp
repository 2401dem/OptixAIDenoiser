#include <opencv2/opencv.hpp>
#include "utilities.h"

int getBitDepth(const cv::Mat &src)
{
	int rtype = src.depth();
	switch (rtype)
	{
	case CV_8U:
		return 8;
		break;
	case CV_16U:
		return 16;
		break;
	case CV_32F:
		return 32;
		break;
	default:
		return 8;
		break;
	}
	return 1.0f;
}

float getAlphaTo32F(const cv::Mat &src)
{
	int rtype = src.depth();
	switch (rtype)
	{
	case CV_8U:
		return 1.0f / 255.0f;
		break;
	case CV_16U:
		return 1.0f / (256.0f * 256.0f - 1.0f);
		break;
	case CV_32F:
		return 1.0f;
		break;
	default:
		return 1.0f;
		break;
	}
	return 1.0f;
}

float getAlphaTo8U(const cv::Mat &src)
{
	int rtype = src.depth();
	switch (rtype)
	{
	case CV_8U:
		return 1.0f;
		break;
	case CV_16U:
		return 1.0f / 256.0f;
		break;
	case CV_32F:
		return 255.0f;
		break;
	default:
		return 1.0f;
		break;
	}
	return 1.0f;
}

void fillImageBox(const cv::Mat &src, cv::Mat &dst)
{
	//static float scale = 720 / float(std::max(src.cols, src.rows));
	//resize(dst, dst, cv::Size(720, 720));
	src.convertTo(dst, CV_8U, getAlphaTo8U(src));
	//resize(dst, dst, cv::Size(floor(scale * src.cols), floor(scale * src.rows)));
}
