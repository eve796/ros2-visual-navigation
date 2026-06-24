# Project Architecture

## Current Stage
Standalone C++/OpenCV foundation before ROS2.

## Current Data Flow
command-line input
→ input path validation
→ output path generation
→ image loading
→ grayscale conversion
→ Gaussian blur
→ Canny edge detection
→ save output images

## Module Responsibilities
image_loader.cpp
image_processor.hpp / image_processor.cpp
path_utils.hpp / path_utils.cpp

## Current Error Handling
too many arguments
missing input file

## Manual Testing
link to manual-test-checklist.md

## Future ROS2 Transition
standalone image path input
→ ROS2 camera image topic

image_loader main flow
→ ROS2 node callback

OpenCV processing functions
→ reusable vision-processing module