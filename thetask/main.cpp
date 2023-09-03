#include "Detector.hpp"
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat image = cv::imread("/home/yang/code/vs/project4opencv/thetask/shapes.png");

  Detector detector;
  detector.set_img(image);//传递整个图像
  std::vector<cv::Point> detectedPoints = detector.detect();//检测中心坐标
  detector.print();//打印坐标

  cv::imshow("Image", image);//加载图像
  cv::waitKey(0);

  return 0;
}
