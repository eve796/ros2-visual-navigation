#pragma once

#include <opencv2/opencv.hpp>
#include <string>

cv::Mat loadImage(const std::string& input_path);

void printImageInfo(const cv::Mat& image);

cv::Mat convertToGray(const cv::Mat& image);

bool saveImage(const std::string& output_path, const cv::Mat& image);