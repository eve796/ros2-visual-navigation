#pragma once

#include <string>

struct OutputPaths
{
    std::string gray;
    std::string edges;
};

OutputPaths buildOutputPaths(const std::string& input_path,
                             const std::string& output_dir);