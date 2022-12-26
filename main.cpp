#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("D:\\OpenCv4.1.1\\packages\\img\\RM.png");    // 这边修改成自己的图片路径，注意双斜杠

    //输出原始图像
    if(img.empty())
    {
        cout << "can't read this image!" << endl;
        return 0;
    }
    namedWindow("原图像");
    imshow("原图像", img);

    //颜色转换并输出（RGB转灰度图）
    Mat grayimg;
    cvtColor(img,grayimg,COLOR_BGR2GRAY);
    namedWindow("灰度图像");
    imshow("灰度图像",grayimg);

    //输出高斯滤波图像，大小3x3
    Mat gauss;
    GaussianBlur(img,gauss,Size(3,3),10,20);
    namedWindow("高斯滤波图像");
    imshow("高斯滤波图像",gauss);

    //将得到的转换图二值化并显示
    Mat dst_g,dst_Gao;
    threshold(grayimg,dst_g,125,255,THRESH_BINARY);
    namedWindow("灰度图像二值化");
    imshow("灰度图像二值化",dst_g);
    threshold(gauss,dst_Gao,125,255,THRESH_BINARY);
    namedWindow("高斯滤波图像二值化");
    imshow("高斯滤波图像二值化",dst_Gao);

    waitKey(0);
    return 0;
}

