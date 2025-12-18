--메인 코드--
//#include "opencv2/opencv.hpp"
extern void show2();
#include <iostream>

int main()
{
    std::cout << "Open CV\n";
    show2();
}

--code1.cpp코드(소스파일)--
#include "opencv2/opencv.hpp"
void show2()
{
	cv::namedWindow("Color");
	for (int i = 255; i >= 0; --i) {
		cv::Mat image(512, 512, CV_8UC3, cv::Scalar(i, i, i)); //Scalar(파랑, 초록, 빨강)
		cv::imshow("Color", image);
		cv::waitKey(10);
	}
	cv::waitKey(0);
}
