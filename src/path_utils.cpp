#include "path_utils.hpp"

#include <filesystem>

OutputPaths buildOutputPaths(const std::string& input_path,
                             const std::string& output_dir)
{
    std::filesystem::path input_file(input_path);
    std::filesystem::path output_folder(output_dir);

    std::string base_name = input_file.stem().string();

    OutputPaths paths;
    paths.gray = (output_folder / (base_name + "_gray.jpg")).string();
    paths.edges = (output_folder / (base_name + "_edges.jpg")).string();

    return paths;
}