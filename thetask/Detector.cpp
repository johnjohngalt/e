#include "Detector.hpp"
#include <iostream>

//接受图像数据
void Detector::set_img(cv::Mat& image) {//接收图像地址
  img = image;
}





//检测坐标函数
std::vector<cv::Point> Detector::detect() {//返回坐标点 
  cv::Mat gray;//存储灰度图像 
  cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);//转化为灰度图像
  //cv::GaussianBlur(gray, gray, cv::Size(9, 9), 0);//高斯模糊 降噪平滑
  cv::Canny(gray, gray, 100, 200); // 使用Canny边缘检测

  std::vector<std::vector<cv::Point>> contours;//创建二维向量 用于存储轮廓
  cv::findContours(gray, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);//查找轮廓 外轮廓端点
  

  points.clear();//清空以便存储中心坐标


  for (const auto& contour : contours) {//遍历每一个找到的轮廓
    double area = cv::contourArea(contour);//计算轮廓面积 

    
    if (area > 100) {//除去较小轮廓
      cv::Moments mu = cv::moments(contour);//利用moments提取出轮廓的矩 放入mu结构体
      cv::Point center(mu.m10 / mu.m00, mu.m01 / mu.m00);//mu.m10 / mu.m00为中心x坐标  mu.m01 / mu.m00中心y坐标 储存于center变量
      points.push_back(center);//将中心坐标添加到point容器


    }
  }

  //检测为圆形
      
          cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2); // 高斯模糊
          std::vector<cv::Vec3f> circles;//存储圆形
          cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 8, 10, 30, 0, 0); //返回圆形信息

          for (const auto& circle : circles) {//遍历其中圆形轮廓
              cv::Point center(cvRound(circle[0]), cvRound(circle[1])); // 圆心坐标
              points.push_back(center);//存入容器
              
          }

          
    
  std::cout << "Number of contours: " << contours.size() << std::endl;

  return points;//返回整个容器
}





//打印坐标结果
void Detector::print() {
  for (const auto& point : points) {
    std::cout << "Center: (" << point.x << ", " << point.y << ")\n";
  }
}
