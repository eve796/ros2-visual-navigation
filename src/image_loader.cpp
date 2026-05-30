#include "image_processor.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string input_path = "assets/test.jpg";
    std::string output_path = "outputs/test_gray.jpg";

    // Load image from disk
    cv::Mat image = loadImage(input_path);

    // Check whether loading failed
    if (image.empty())
    {
        return -1;
    }
    
    // Print image information
    printImageInfo(image);

    // Convert color image to grayscale
    cv::Mat gray = convertToGray(image);

    // Save grayscale image to disk
    bool saved = saveImage(output_path, gray);

    if (!saved)
    {
        std::cout << "Failed to save grayscale image: " << std::endl;
        return -1;
    }

    std::cout << "Grayscale image saved to: " << output_path << std::endl;

    return 0;
}