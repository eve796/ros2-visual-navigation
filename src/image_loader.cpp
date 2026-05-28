#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string input_path = "assets/test.jpg";
    std::string output_path = "outputs/test_gray.jpg";

    // Load image from disk
    cv::Mat image = cv::imread(input_path);

    // Check whether loading failed
    if (image.empty())
    {
        std::cout << "Failed to load image." << input_path << std::endl;
        return -1;
    }
    std::cout << "Image loaded successfully!" << std::endl;
    
    // Print image information
    std::cout << "Width: " << image.cols << std::endl;
    std::cout << "Height: " << image.rows << std::endl;
    std::cout << "Channels: " << image.channels() << std::endl;

    // Convert color image to grayscale
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // Save grayscale image to disk
    bool saved = cv::imwrite(output_path, gray);

    if (!saved)
    {
        std::cout << "Failed to save grayscale image: " << std::endl;
        return -1;
    }

     std::cout << "Grayscale image saved to: " << output_path << std::endl;

    return 0;
}