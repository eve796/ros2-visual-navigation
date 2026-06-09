# OpenCV Module Notes

## Current Purpose

The current OpenCV module is a standalone C++ image-processing pipeline. It is used to practice C++, CMake, OpenCV, file paths, and basic visual perception before connecting the project to ROS2.

## Current Pipeline

```text
input image path
→ load image
→ print image information
→ convert to grayscale
→ blur grayscale image
→ detect edges
→ save generated outputs
```

## Current Error Handling

The image loader now checks basic command-line usage and verifies that the input image path exists before attempting to load it with OpenCV.