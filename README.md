# ros2-visual-navigation

Vision-based autonomous robot navigation using ROS2, OpenCV, and Gazebo simulation.

## Goal

Build a simulation-first robotics system that helps me learn ROS2, Linux-based engineering workflow, computer vision, and autonomous navigation.

This project starts with a standalone C++/OpenCV image-processing pipeline and will gradually evolve toward a ROS2-based visual navigation system.

## Current Stage

The project is currently in the standalone C++/OpenCV foundation stage.

The current program includes:
- a CMake-based C++ build workflow
- a modular C++ file structure
- image loading with OpenCV
- image information printing
- grayscale conversion
- Gaussian blur preprocessing
- Canny edge detection
- automatic output-directory creation
- command-line input image path support
- generated grayscale and edge-detection output images

## Planned Features

- ROS2 workspace setup
- Gazebo simulation environment
- Robot model visualization in RViz
- Camera-based perception pipeline
- Basic obstacle detection
- Simple navigation behavior

## Tech Stack

- ROS2
- Gazebo
- RViz
- OpenCV
- C++
- Python
- Linux
- CMake
- Git / GitHub

## Current File Structure

```text
include/
  image_processor.hpp
  path_utils.hpp

src/
  image_loader.cpp
  image_processor.cpp
  path_utils.cpp

docs/
  learning-log.md
  opencv-module-notes.md
  manual-test-checklist.md

CMakeLists.txt
README.md
```

## Build and Run

From the project root:
```bash
cmake -S . -B build
cmake --build build
```

Run with the default test image:
```bash
./build/image_loader
```

Run with a custom input image:
```bash
./build/image_loader path/to/image.jpg
```

If too many arguments are provided, the program prints a usage message:
```text
Usage: ./build/image_loader [input_image_path]
```

If the input image path does not exist, the program prints an error message:
```text
Error: input image does not exist: assets/not_exist.jpg
```

## Expected Output

Example command:
```bash
./build/image_loader assets/test.jpg
```

Expected terminal output:
```text
Image loaded successfully!
Width: 750
Height: 748
Channels: 3
Grayscale image saved to: outputs/test_gray.jpg
Edge image saved to: outputs/test_edges.jpg
```

## Current Architecture Overview

Current standalone OpenCV pipeline:
```text
command-line input
→ input path validation
→ output path generation
→ image loading
→ grayscale conversion
→ Gaussian blur
→ Canny edge detection
→ save output images
```

Current module responsibilities:
```text
src/image_loader.cpp
→ controls main program flow

include/image_processor.hpp
src/image_processor.cpp
→ handle OpenCV image-processing operations

include/path_utils.hpp
src/path_utils.cpp
→ handle output path generation

docs/manual-test-checklist.md
→ documents repeatable manual test cases
```

## Documentation

- [Architecture](docs/architecture.md)
- [Manual Test Checklist](docs/manual-test-checklist.md)
- [Learning Log](docs/learning-log.md)
- [Setup Notes](docs/setup.md)


## Milestones

### Milestone 0: Project Setup
- [x] Create repository structure
- [x] Document setup process
- [x] Create learning log
- [x] Set up basic CMake build workflow
- [x] Create modular C++ source/header structure

### Milestone 1: OpenCV Foundation

- [x] Load an image with OpenCV
- [x] Print image width and height
- [x] Print image channel count
- [x] Convert image to grayscale
- [x] Add Canny edge detection
- [x] Save edge-detection output image
- [x] Generate output filenames from input image name
- [x] Add basic CLI validation

### Milestone 2: ROS2 Basics
- [ ] Create a simple ROS2 workspace
- [ ] Create a simple ROS2 package
- [ ] Run publisher/subscriber nodes
- [ ] Understand node, topic, message, and callback concepts
- [ ] Visualize data flow

### Milestone 3: Simulation
- [ ] Launch Gazebo world
- [ ] Spawn robot model
- [ ] View robot in RViz

### Milestone 4: Vision
- [ ] Add camera sensor
- [ ] Read image stream
- [ ] Process frames with OpenCV
- [ ] Connect image-processing logic to ROS2 nodes

### Milestone 5: Navigation
- [ ] Implement simple obstacle detection
- [ ] Make robot respond to visual input
- [ ] Visualize basic navigation behavior

## Notes

This is my first owned robotics/systems project. The goal is not to build an advanced robot immediately, but to steadily build engineering fluency through Linux, C++, CMake, OpenCV, Git/GitHub, documentation, and later ROS2 simulation.
