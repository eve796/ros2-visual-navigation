#include "image_processor.hpp"
#include <iostream>

cv::Mat loadImage(const std::string& input_path)
{
    // cv::imread reads an image from disk
    cv::Mat image = cv::imread(input_path);
    
    // image.empty() is true if the image failed to load
    if (image.empty())
    {
        std::cout << "Failed to load image: " << input_path << std::endl;
    }

    return image;
}

void printImageInfo(const cv::Mat& image)
{
    std::cout << "Image loaded successfully!" << std::endl;
    std::cout << "Width: " << image.cols << std::endl; // image.cols = image width in pixels
    std::cout << "Height: " << image.rows << std::endl; // image.rows = image height in pixels
    std::cout << "Channels: " << image.channels() << std::endl; // image.channels() = number of color channels
}

cv::Mat convertToGray(const cv::Mat& image)
{
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY); // OpenCV usually stores color images in BGR order, not RGB order
    return gray;
}

bool saveImage(const std::string& output_path, const cv:: Mat& image)
{
    // cv::imwrite saves the image to disk
    return cv::imwrite(output_path, image);
}

cv::Mat detectEdges(const cv::Mat& gray_image)
{
    // create temporary images for the blur result and final edge result
    cv::Mat blurred;
    cv::Mat edges;

    // apply Gaussian blur before edge detection
    cv::GaussianBlur(gray_image, blurred, cv::Size(5, 5), 1.5);

    // apply Canny edge detection
    cv::Canny(blurred, edges, 100, 200);

    return edges;
}