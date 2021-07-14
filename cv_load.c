
#include "cv_load.h"


unsigned char* MatToImg(Mat imgtemp);

unsigned char* OpenCVLoad(string path, int & height, int & width)
{
	Mat img = imread(path);
	width = img.cols;
	height = img.rows;
	unsigned char* buffer = MatToImg(img);
	return buffer;
	
}


Mat ImgToMat(unsigned char* ubuff,int height,int width)
{
	int i, j;

	Mat imgtemp(width, height, CV_8UC3, Scalar::all(0));
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			int temp = i*width + j;
			imgtemp.at<Vec3b>(i, j)[0] = ubuff[3 * temp];     //R
			imgtemp.at<Vec3b>(i, j)[1] = ubuff[3 * temp + 1]; //G
			imgtemp.at<Vec3b>(i, j)[2] = ubuff[3 * temp + 2]; //B
		}
	}
	return imgtemp;	
}



unsigned char* MatToImg(Mat imgtemp)
{
	int i, j;

	int height = imgtemp.rows;
	int width = imgtemp.cols;
	unsigned char* ubuff = new unsigned char[height * width * 3];

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			int temp = i * width + j;
			ubuff[3 * temp] = imgtemp.at<Vec3b>(i, j)[0]; //R
			ubuff[3 * temp + 1] = imgtemp.at<Vec3b>(i, j)[1] ; //G
			ubuff[3 * temp + 2] = imgtemp.at<Vec3b>(i, j)[2]; //B
		}
	}
	return ubuff;
}


