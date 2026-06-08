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

    // extract the base filename from the input path
    std::filesystem::path input_file(input_path);
    std::string base_name = input_file.stem().string();
    
    // generate output paths based on the input image name
    std::string gray_output_path = "outputs/" + base_name + "_gray.jpg";
    std::string edges_output_path = "outputs/" + base_name + "_edges.jpg";

    // print paths for easier debugging
    std::cout << "Input image: " << input_path << std::endl;
    std::cout << "Grayscale output: " << gray_output_path << std::endl;
    std::cout << "Edge output: " << edges_output_path << std::endl;

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
    bool edges_saved = saveImage(edges_output_path, edges);
    
    // check whether saving failed
    if (!edges_saved)
    {
    std::cout << "Failed to save edge image." << std::endl;
    return -1;
    }

    std::cout << "Edge image saved to: " << edges_output_path << std::endl;

    return 0;
}