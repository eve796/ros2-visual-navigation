# ros2-visual-navigation
Vision-based autonomous robot navigation using ROS2, OpenCV, and Gazebo simulation.

## Goal

Build a simulation-first robotics system that helps me learn ROS2, Linux-based engineering workflow, computer vision, and autonomous navigation.

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

## Milestones

### Milestone 0: Project Setup
- [ ] Create repository structure
- [ ] Document setup process
- [ ] Create learning log

### Milestone 1: ROS2 Basics
- [ ] Create a simple ROS2 package
- [ ] Run publisher/subscriber nodes
- [ ] Visualize data flow

### Milestone 2: Simulation
- [ ] Launch Gazebo world
- [ ] Spawn robot model
- [ ] View robot in RViz

### Milestone 3: Vision
- [ ] Add camera sensor
- [ ] Read image stream
- [ ] Process frames with OpenCV

### Milestone 4: Navigation
- [ ] Implement simple obstacle detection
- [ ] Make robot respond to visual input

## Learning Log

See [`docs/learning-log.md`](docs/learning-log.md).


## Current OpenCV + CMake Milestone

This project currently includes a minimal C++ OpenCV image-processing example.

The program:
- loads an image from `assets/test.jpg`
- prints width, height, and channel count
- converts the image to grayscale
- saves the result to `outputs/test_gray.jpg`

Build with CMake:

```bash
cmake -S . -B build
cmake --build build
./build/image_loader
```