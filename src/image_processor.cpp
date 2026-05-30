#include "image_processor.hpp"
#include <iostream>

cv::Mat loadImage(const std::string& input_path)
{
    cv::Mat image = cv::imread(input_path);
    
    if (image.empty())
    {
        std::cout << "Failed to load image: " << input_path << std::endl;
    }

    return image;
}

void printImageInfo(const cv::Mat& image)
{
    std::cout << "Image loaded successfully!" << std::endl;
    std::cout << "Width: " << image.cols << std::endl;
    std::cout << "Height: " << image.rows << std::endl;
    std::cout << "Channels: " << image.channels() << std::endl;
}

cv::Mat convertToGray(const cv::Mat& image)
{
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    return gray;
}

bool saveImage(const std::string& output_path, const cv:: Mat& image)
{
    return cv::imwrite(output_path, image);
}