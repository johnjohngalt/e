#ifndef DETECTOR_HPP
#define DETECTOR_HPP

#include <opencv2/opencv.hpp>
#include <vector>

class Detector {
private:
  cv::Mat img;//用于储存图像数据
  std::vector<cv::Point> points;//用于储存点的集合

public:
  void set_img(cv::Mat& image);//接受图像数据
  std::vector<cv::Point> detect();//检测坐标函数
  void print();//打印坐标结果
};

#endif
