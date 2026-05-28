#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat image = cv::imread("assets/test.jpg"); // Load image from disk
    // Check whether loading failed
    if (image.empty())
    {
        std::cout << "Failed to load image." << std::endl;
        return -1;
    }
    std::cout << "Image loaded successfully!" << std::endl;
    // Print image dimensions
    std::cout << "Width: " << image.cols << std::endl;
    std::cout << "Height: " << image.rows << std::endl;

    return 0;
}