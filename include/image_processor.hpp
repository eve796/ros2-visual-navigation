// during one compilation, include this header file only once
#pragma once

#include <opencv2/opencv.hpp>
#include <string>

// loads an image from the given file path
cv::Mat loadImage(const std::string& input_path);

// print basic information about the image
void printImageInfo(const cv::Mat& image);

// convert a color image from BGR to grayscale
cv::Mat convertToGray(const cv::Mat& image);

// save an image to the given file path
bool saveImage(const std::string& output_path, const cv::Mat& image);

// detect edges from a grayscale image
cv::Mat detectEdges(const cv::Mat& gray_image);