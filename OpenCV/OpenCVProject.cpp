--메인 코드--
//#include "opencv2/opencv.hpp"
extern void show1();
#include <iostream>

int main()
{
    std::cout << "Open CV\n"; 
    show1();
}

--code1.cpp코드(소스 파일)--
#include "opencv2/opencv.hpp"

void show1()
{
	cv::Mat image1 = cv::imread("lenna.png");
	cv::Mat image2 = cv::imread("dog.jpg");
	if (image1.empty() or image2.empty()) {
		std::cerr << "파일이 없습니다." << std::endl;
		return;
	}
	std::cout << "몇 차원? : " << image1.dims << std::endl;
	std::cout << "열(column) ? : " << image1.cols << std::endl;
	std::cout << "행(row) ? : " << image1.rows << std::endl;
	cv::namedWindow("LENNA");
	cv::imshow("LENNA", image1);
	std::cout << "몇 차원? : " << image2.dims << std::endl;
	std::cout << "열(column) ? : " << image2.cols << std::endl;
	std::cout << "행(row) ? : " << image2.rows << std::endl;
	cv::namedWindow("DOG");
	cv::imshow("DOG", image2);
	cv::waitKey();
	cv::destroyAllWindows();
}
