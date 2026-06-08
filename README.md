# ros2-visual-navigation

Vision-based autonomous robot navigation using ROS2, OpenCV, and Gazebo simulation.

## Goal

Build a simulation-first robotics system that helps me learn ROS2, Linux-based engineering workflow, computer vision, and autonomous navigation.

This project starts with a standalone C++/OpenCV image-processing pipeline and will gradually evolve toward a ROS2-based visual navigation system.

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

## Current Project Status

The current stage focuses on building a clean C++/OpenCV foundation before moving into ROS2.

The project currently includes:

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

## Current File Structure

```text
include/
  image_processor.hpp

src/
  image_loader.cpp
  image_processor.cpp

assets/
  test.jpg

outputs/
  test_gray.jpg
  test_edges.jpg

docs/
  learning-log.md
```

## Current OpenCV + CMake Milestone

This project currently includes a minimal C++ OpenCV image-processing pipeline.

The program:

- uses `assets/test.jpg` as the default input image
- can accept a custom input image path from the command line
- loads an image with OpenCV
- prints width, height, and channel count
- converts the image to grayscale
- saves the grayscale image to `outputs/test_gray.jpg`
- applies Gaussian blur before edge detection
- detects edges using Canny edge detection
- saves the edge image to `outputs/test_edges.jpg`
- automatically creates the `outputs/` directory if it does not exist
- generates output filenames from the input image name

Current pipeline:

```text
input image path
→ load color image
→ convert to grayscale
→ blur grayscale image
→ detect edges
→ save grayscale and edge outputs
```

## Technical Notes

- [OpenCV Module Notes](docs/opencv-module-notes.md)

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

Example:

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

## C++ Module Structure

The current C++ code is separated into three main files:

```text
include/image_processor.hpp
```

Declares the image-processing functions.

```text
src/image_processor.cpp
```

Implements the image-processing functions.

```text
src/image_loader.cpp
```

Controls the main program flow, handles command-line input, creates the output directory, and runs the image-processing pipeline.

This structure keeps the program more modular and prepares the project for future ROS2 node organization.

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
- [x] Add command-line input path support
- [x] Automatically create output directory

### Milestone 2: ROS2 Basics
- [ ] Create a simple ROS2 package
- [ ] Run publisher/subscriber nodes
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

## Learning Log

See [`docs/learning-log.md`](docs/learning-log.md).

## Notes

This is my first owned robotics/systems project. The goal is not to build an advanced robot immediately, but to steadily build engineering fluency through Linux, C++, CMake, OpenCV, Git/GitHub, documentation, and later ROS2 simulation.
