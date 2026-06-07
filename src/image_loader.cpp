#include "image_processor.hpp"

#include <filesystem>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    // default input path
    std::string input_path = "assets/test.jpg";

    // if the user provides one extra command-line argument, use that argument as the input path
    if (argc > 1)
    {
        input_path = argv[1];
    }

    // make sure the outputs directory exists before saving images
    std::filesystem::create_directories("outputs");

    // default output paths
    std::string gray_output_path = "outputs/test_gray.jpg";
    std::string edge_output_path = "outputs/test_edges.jpg";

    // load image from disk
    cv::Mat image = loadImage(input_path);

    // check whether loading failed
    if (image.empty())
    {
        return -1;
    }
    
    // print image information
    printImageInfo(image);

    // convert color image to grayscale
    cv::Mat gray = convertToGray(image);

    // save grayscale image to disk
    bool gray_saved = saveImage(gray_output_path, gray);

    // check whether saving failed
    if (!gray_saved)
    {
        std::cout << "Failed to save grayscale image: " << std::endl;
        return -1;
    }

    std::cout << "Grayscale image saved to: " << gray_output_path << std::endl;

    // detect edges from the grayscale image
    cv::Mat edges = detectEdges(gray);

    // save the edge-detection result to disk
    bool edges_saved = saveImage(edge_output_path, edges);
    
    // check whether saving failed
    if (!edges_saved)
    {
    std::cout << "Failed to save edge image." << std::endl;
    return -1;
    }

    std::cout << "Edge image saved to: " << edge_output_path << std::endl;

    return 0;
}