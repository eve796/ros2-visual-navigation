#include "image_processor.hpp"
#include "path_utils.hpp"

#include <filesystem>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    // default input path
    std::string input_path = "assets/test.jpg";

    // check command-line usage
    if (argc > 2)
    {
        std::cout << "Usage: " << argv[0] << " [input_image_path]" << std::endl;
        return 1;
    }

    // if the user provides one extra command-line argument, use that argument as the input path
    if (argc > 1)
    {
        input_path = argv[1];
    }
    
    // check whether the input image path exists before loading it
    if (!std::filesystem::exists(input_path))
    {
        std::cout << "Error: input image does not exist: " << input_path << std::endl;
        return 1;
    }

    // make sure the outputs directory exists before saving images
    std::string output_dir = "outputs";
    std::filesystem::create_directories(output_dir);
    
    // build output paths based on the input image name
    OutputPaths output_paths = buildOutputPaths(input_path, output_dir);

    // print paths for easier debugging
    std::cout << "Input image: " << input_path << std::endl;
    std::cout << "Grayscale output: " << output_paths.gray << std::endl;
    std::cout << "Edge output: " << output_paths.edges << std::endl;

    // load image from disk
    cv::Mat image = loadImage(input_path);

    // check whether loading failed
    if (image.empty())
    {
        return 1;
    }
    
    // print image information
    printImageInfo(image);

    // convert color image to grayscale
    cv::Mat gray = convertToGray(image);

    // save grayscale image to disk
    bool gray_saved = saveImage(output_paths.gray, gray);

    // check whether saving failed
    if (!gray_saved)
    {
        std::cout << "Failed to save grayscale image." << std::endl;
        return 1;
    }

    std::cout << "Grayscale image saved to: " << output_paths.gray << std::endl;

    // detect edges from the grayscale image
    cv::Mat edges = detectEdges(gray);

    // save the edge-detection result to disk
    bool edges_saved = saveImage(output_paths.edges, edges);
    
    // check whether saving failed
    if (!edges_saved)
    {
        std::cout << "Failed to save edge image." << std::endl;
        return 1;
    }

    std::cout << "Edge image saved to: " << output_paths.edges << std::endl;

    return 0;
}