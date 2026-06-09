# Learning Log

## 2026-05-25

### What I did

- Started Day 1 of the `ros2-visual-navigation` project.
- Installed Homebrew
- Configured Git and GitHub CLI authentication
- Created my first engineering repository
- Learned basic terminal workflow
- Structured the repository for robotics systems development
- Opened project in VSCode

### Problems Encountered

- Terminal quotation syntax
- GitHub password authentication failed
- `code .` command not recognized initially

### What I Learned

- GitHub no longer supports password authentication for git push
- Engineering environments require configuration/debugging
- Terminal commands are extremely literal
- Git workflow is central to systems engineering
- Repository structure matters for large engineering projects

### Next Steps

- Configure Rutgers iLab access
- Verify ROS2 installation on Rutgers systems
- Learn ROS2 publisher/subscriber basics
- Begin understanding ROS2 node architecture

## 2026-05-26

### What I did

- Started Day 2 of the `ros2-visual-navigation` project.
- Successfully connected to Rutgers iLab using SSH
- Logged into a remote Ubuntu 24.04 Linux machine
- Learned how remote Linux infrastructure works through terminal access
- Tested multiple Linux commands:
  - `ssh`
  - `which`
  - `find`
  - `ls`
- Investigated possible ROS2 installation paths such as '/opt/ros'
- Read Rutgers infrastructure documentation regarding:
  - virtual machines
  - Docker containers
  - user-managed environments
  - Linux compute systems

### Problems Encountered

- Initially misunderstood SSH command syntax
- Confused infrastructure/network access with software availability
- Large filesystem search commands ('find /') appeared to freeze terminal
- ROS2 command was unavailable:
```bash
ros2: command not found
```

### Next Steps

- Continue improving terminal/Linux familiarity
- Learn basic Docker concepts
- Build stronger understanding of Linux filesystem structure
- Continue ROS2 conceptual learning before large-scale deployment
- Begin lightweight OpenCV/C++ systems practice locally

## 2026-05-27

### What I did

- Started Day 3 of the `ros2-visual-navigation` project.
- Practiced basic Linux/macOS terminal commands:
  - `pwd`
  - `ls`
  - `ls -la`
  - `cd`
  - `cd ..`
  - `cd ~`
  - `mkdir`
  - `touch`
  - `cp`
  - `mv`
  - `rm`
  - `rm -r`
  - `rm -rf`
- Practiced directory navigation and path usage.
- Learned the difference between:
  - files
  - folders/directories
  - hidden files
  - current directory `.`
  - parent directory `..`
- Practiced creating nested folders and moving/copying files between them.
- Learned the basic idea of processes:
  - a process is a running program
  - `ps` shows a process snapshot
  - `top` shows live system activity
  - each running program has a process ID/PID
- Installed and verified OpenCV on macOS.
- Created `src/image_loader.cpp`.
- Wrote a simple C++ OpenCV program to load an image.
- Compiled the C++ source file with `g++`.
- Successfully ran the executable program `image_loader`.
- Confirmed that the program loaded `test.jpg` and printed its width and height.
- Understood the basic C++ compilation pipeline:
  - source code
  - compiler
  - executable
  - runtime output
- Learned that compiled executables are generated files and should usually not be committed to Git.
- Encountered and fixed a C++ syntax error caused by a missing semicolon.
- Encountered and fixed a Git repository hygiene issue:
  - accidentally added `.DS_Store`
  - accidentally added the compiled executable `image_loader`
  - accidentally added a nested Git repository
- Created a `.gitignore` file to ignore macOS metadata and build outputs.
- Used `git rm --cached` to remove unwanted files from Git tracking.
- Committed the cleanup and successfully pushed the project to GitHub.

### Problems Encountered

- I was confused about when to use `rm`, `rmdir`, `rm -r`, and `rm -rf`.
- I did not fully understand hidden files beginning with `.`.
- I needed clarification on `ps`, `top`, CPU usage, memory usage, and process IDs.
- I made a C++ syntax mistake by forgetting the semicolon after `return 0`.
- I was confused about what an executable file is and how it differs from source code.
- I accidentally staged generated/local files with `git add .`.
- I accidentally had a nested `ros2-visual-navigation` repository inside the main repository.
- `git push` was rejected because the remote GitHub repository had changes that were not yet integrated locally.
- I needed help understanding:
  - `.gitignore`
  - `git add`
  - `git commit`
  - `git pull --rebase`
  - `git push`

### What I Learned

- `cd` changes the terminal's current directory; it cannot enter normal files.
- Relative paths depend on the current working directory.
- `rm` deletes files, while `rm -r` is needed for non-empty directories.
- `rm -rf` should be used carefully because it recursively and forcefully deletes files/folders.
- Hidden files often store configuration or system/tool metadata.
- A C++ source file is not directly run; it must be compiled into an executable.
- `g++` compiles C++ source code into a runnable program.
- OpenCV stores images using `cv::Mat`.
- `cv::imread()` loads an image from a file path.
- `image.cols` and `image.rows` represent image width and height.
- Git should track source code, documentation, and useful project assets.
- Git should usually not track generated files such as executables, object files, build folders, or `.DS_Store`.
- `.gitignore` helps prevent generated/local files from being accidentally committed.
- `git add` stages changes for the next commit, and Git’s documentation calls this staging area the “index”.
- `.gitignore` tells Git which files or directories to ignore, and already-tracked files must be untracked first with `git rm --cached`.

### Next Steps

- Extend the OpenCV example slightly:
  - print image width
  - print image height
  - print number of channels
  - convert the image to grayscale
  - save the grayscale result as an output image
- Practice the clean Git workflow:
  - `git status`
  - `git add .`
  - `git commit -m "..."`
  - `git push`
- Before every commit, check whether Git is tracking only source code, documentation, and useful assets.
- Continue treating the GitHub repository as an engineering notebook.

## 2026-05-28

### What I did

- Started Day 4 of the `ros2-visual-navigation` project.
- Checked the project status with `git status`.
- Learned why `git pull --rebase` cannot run when there are unstaged local changes.
- Reviewed the importance of having a clean working tree before synchronizing with GitHub.
- Created an `outputs/` directory for generated program results.
- Learned the difference between:
  - `mkdir outputs`
  - `mkdir -p outputs`
- Accidentally typed `.gitigonore` instead of `.gitignore`.
- Fixed the typo by appending the mistaken file’s contents into `.gitignore` and deleting the wrong file.
- Learned what `cat` does:
  - display file contents
  - read one file and redirect/append its contents into another file
- Updated `.gitignore` to ignore generated program outputs:
  - `outputs/`
- Extended `src/image_loader.cpp` from a simple image loader into a small image-processing pipeline.
- Modified the program to:
  - load `assets/test.jpg`
  - print image width
  - print image height
  - print number of channels
  - convert the image to grayscale
  - save the grayscale image to `outputs/test_gray.jpg`
- Recompiled the C++ program with `g++`.
- Successfully ran the updated executable.
- Confirmed that `outputs/test_gray.jpg` was generated.
- Learned the basic idea of image channels and BGR/RGB channel order.
- Committed the OpenCV pipeline update with Git.
- Pushed the commit successfully to GitHub.

### Problems Encountered

- `git pull --rebase` initially failed because there were unstaged local changes in:
  - `docs/learning-log.md`
  - `src/image_loader.cpp`
- I accidentally created `.gitigonore` due to a filename typo.
- I needed clarification on what `cat` means and how output redirection works.
- I needed clarification on BGR/RGB channel order.
- I had to make sure generated output files should not be tracked by Git.
- I needed to confirm that the final Git state was clean after committing and pushing.

### What I Learned

- `git pull --rebase` should usually be run when the working tree is clean.
- `git status` helps check whether there are modified, staged, untracked, or clean files.
- `mkdir outputs` creates a folder, but fails if it already exists.
- `mkdir -p outputs` creates the folder if needed and does not complain if it already exists.
- `cat file` prints a file’s contents to the terminal.
- `cat file1 >> file2` appends the contents of `file1` to the end of `file2`.
- `.gitignore` should include generated local outputs such as:
  - compiled executables
  - build artifacts
  - output images
  - macOS metadata files
- A clean repository should track source code, documentation, configuration, and useful assets, not generated outputs.
- `cv::imread()` loads an image from disk.
- `image.cols` gives image width.
- `image.rows` gives image height.
- `image.channels()` gives the number of channels in an image.
- OpenCV commonly uses BGR channel order for color images.
- `cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY)` converts a color image to grayscale.
- `cv::imwrite()` saves an image to disk.
- The program has now become a minimal image-processing pipeline.

### Next Steps

- Update the README with the current OpenCV milestone:
  - input image
  - grayscale conversion
  - output image generation
- Continue practicing clean Git workflow:
  - `git status`
  - `git add`
  - `git commit`
  - `git push`
- Begin preparing for the next build-system step: understanding why larger C++/ROS2 projects usually use CMake instead of long manual `g++` commands.
- Keep the project focused on systems fluency rather than rushing into advanced ROS2 features too early.

## 2026-05-29

### What I did

- Started Day 5 of the `ros2-visual-navigation` project.
- Confirmed that CMake is installed on my Mac:
  - `cmake --version`
- Created a new `CMakeLists.txt` file in the project root.
- Wrote a basic CMake build configuration for the OpenCV image loader.
- Learned the purpose of the main CMake commands:
  - `cmake_minimum_required`
  - `project`
  - `set(CMAKE_CXX_STANDARD 17)`
  - `find_package(OpenCV REQUIRED)`
  - `add_executable`
  - `target_link_libraries`
- Configured the project using:
```bash
cmake -S . -B build
```
- Built the project using:
```bash
cmake --build build
```
- Successfully ran the CMake-built executable:
```bash
./build/image_loader
```
- Confirmed that the program still:
  - loads `assets/test.jpg`
  - prints image width
  - prints image height
  - prints channel count
  - converts the image to grayscale
  - saves the result to `outputs/test_gray.jpg`
- Updated the README with a new “Current OpenCV + CMake Milestone” section.
- Practiced Git workflow again:
  - checked `git status`
  - staged files with `git add`
  - committed with `git commit`
  - pushed with `git push`
- Fixed a Git mistake where I tried to commit before staging files.
- Successfully committed and pushed the CMake milestone to GitHub.

### Problems Encountered

- I had to understand why CMake uses a separate `build/` directory.
- I needed clarification on the difference between:
  - configuring/generating build files
  - actually compiling/building the executable
- I forgot that `git commit` only commits staged changes.
- I ran `git commit` before `git add`, so Git reported that no changes were added to commit.
- I needed to fix the workflow by staging:
  - `CMakeLists.txt`
  - `README.md`
  - `docs/learning-log.md`

### What I Learned

- CMake does not replace the compiler; it manages the build process and uses the compiler underneath.
- `CMakeLists.txt` describes how the project should be built.
- `cmake -S . -B build` means:
  - source directory is the current directory
  - generated build files should go into build/
- `cmake --build build` compiles the project using the generated build files.
- The `build/` directory contains generated build artifacts and should usually not be committed.
- `add_executable(image_loader src/image_loader.cpp)` tells CMake to build an executable target named `image_loader`.
- `target_link_libraries(image_loader ${OpenCV_LIBS})` links the executable with OpenCV.
- `find_package(OpenCV REQUIRED)` tells CMake to locate OpenCV and fail if it cannot be found.
- The CMake workflow is more scalable than manually typing a long `g++` command every time.
- `git add` stages changes.
- `git commit` records only staged changes.
- `git push` uploads committed changes to GitHub.
- A clean engineering workflow usually means:
  - build locally
  - verify the program runs
  - update documentation
  - check Git status
  - commit meaningful source/documentation changes
  - push to GitHub

### Next Steps
- Run the CMake workflow again from a clean state:
  - `cmake -S . -B build`
  - `cmake --build build`
  - `./build/image_loader`
- Begin preparing for a cleaner C++ project structure, such as separating reusable image-processing logic from `main()`.

## 2026-05-30

### What I did

- Started Day 6 of the `ros2-visual-navigation` project.
- Confirmed that the repository was clean and up to date:
  - `git pull --rebase`
  - `git status`
- Rebuilt and reran the existing CMake-based OpenCV program before refactoring:
  - `cmake -S . -B build`
  - `cmake --build build`
  - `./build/image_loader`
- Created a new `include/` directory.
- Created a new C++ header file:
  - `include/image_processor.hpp`
- Created a new C++ implementation file:
  - `src/image_processor.cpp`
- Refactored the OpenCV image-processing logic out of `src/image_loader.cpp`.
- Separated the project into:
  - `include/image_processor.hpp` for function declarations
  - `src/image_processor.cpp` for function definitions
  - `src/image_loader.cpp` for the main program flow
- Learned the purpose of a `.hpp` header file.
- Learned the difference between function declarations and function definitions.
- Learned why `include/` should be committed to Git because it contains source code, not generated output.
- Learned the meaning of:
  - `const`
  - `&`
  - `const std::string&`
  - `const cv::Mat&`
- Updated `CMakeLists.txt` so the executable builds from multiple source files:
  - `src/image_loader.cpp`
  - `src/image_processor.cpp`
- Added the include directory to the CMake target using:
  - `target_include_directories(image_loader PRIVATE include)`
- Rebuilt the project successfully with CMake after the refactor.
- Confirmed that the refactored program still:
  - loads `assets/test.jpg`
  - prints width, height, and channel count
  - converts the image to grayscale
  - saves the result to `outputs/test_gray.jpg`
- Committed and pushed the refactor to GitHub.

### Problems Encountered

- I was confused about the role of `include/image_processor.hpp` and `src/image_processor.cpp`.
- I needed clarification on what a `.hpp` file is.
- I wondered whether the `include/` directory should be ignored by Git.
- I needed clarification on the meaning of `const` and `&` in C++ function parameters.
- I needed clarification on what `PRIVATE` means in `target_include_directories`.
- I had to update CMake correctly so that multiple `.cpp` files could be compiled together.

### What I Learned

- A `.hpp` file is a C++ header file.
- Header files usually declare functions, classes, or interfaces.
- `.cpp` files usually contain the actual function implementations.
- `image_processor.hpp` acts like the interface or contract for the image-processing module.
- `image_processor.cpp` contains the actual logic for loading, printing, converting, and saving images.
- `image_loader.cpp` should focus on the main program flow.
- Separating logic from `main()` makes the project easier to read, debug, and extend.
- `const` means the function promises not to modify the parameter.
- `&` means the parameter is passed by reference, avoiding unnecessary copying.
- `const std::string& input_path` means the function can read the path efficiently without modifying it.
- `const cv::Mat& image` means the function can read the image efficiently without modifying it.
- `include/` should not be ignored because it contains important source/header files.
- Generated files such as `build/`, `outputs/`, executables, and object files should be ignored.
- `target_include_directories(image_loader PRIVATE include)` tells CMake where to find header files when compiling the `image_loader` target.
- `PRIVATE` means the include directory is only needed by this target.
- A project can have multiple source files compiled into one executable.

### Next Steps

- Review the three-file structure again:
  - `include/image_processor.hpp`
  - `src/image_processor.cpp`
  - `src/image_loader.cpp`
- Make sure I can explain the role of each file without looking at notes.
- Consider adding one more simple image-processing function, such as:
  - blur image
  - edge detection
  - thresholding
- Continue keeping the project focused on clean structure, build workflow, documentation, and GitHub progress.

## 2026-05-31

### What I did

- Started Day 7 of the `ros2-visual-navigation` project.
- Added a new image-processing function declaration in `include/image_processor.hpp`:
  - `cv::Mat detectEdges(const cv::Mat& gray_image);`
- Implemented the new `detectEdges()` function in `src/image_processor.cpp`.
- Used `cv::GaussianBlur()` to blur the grayscale image before edge detection.
- Used `cv::Canny()` to detect edges from the blurred grayscale image.
- Updated `src/image_loader.cpp` so the program now saves:
  - `outputs/test_gray.jpg`
  - `outputs/test_edges.jpg`
- Successfully rebuilt the project with CMake after adding the new function.
- Successfully ran the program and confirmed the output:
  - grayscale image saved
  - edge image saved
- Verified generated output files with:
  - `ls outputs`
- Learned why `#pragma once` is used in a header file.
- Learned the basic meaning of image edges:
  - sharp brightness/intensity changes in an image
  - often corresponding to object boundaries or structural lines
- Added annotations/comments to better explain the image-processing code.

### Problems Encountered

- I was confused about what “edges” mean in an image.
- I needed to understand why edge detection is usually applied after grayscale conversion.
- I needed to understand why Gaussian blur is applied before Canny edge detection.

### What I Learned
- `#pragma once` prevents the same header file from being included multiple times during one compilation.
- Header protection becomes more important as a project grows and headers are included by multiple source files.
- An edge is a sharp change in pixel intensity.
- In a grayscale image, pixel intensity roughly means brightness.
- Edge detection tries to find boundaries or strong visual structure in an image.
- Canny edge detection is a common method for detecting edges.
- Edge detection is sensitive to noise, so blurring the image first can reduce false edges.
- `cv::GaussianBlur(gray_image, blurred, cv::Size(5, 5), 1.5)` smooths the image before edge detection.
  - `cv::Size(5, 5)` means the blur uses a 5-by-5 neighborhood.
  - The sigma value controls the blur strength.
- `cv::Canny(blurred, edges, 100, 200)` detects edges using two thresholds.
  - Lower thresholds may detect more edges but can include more noise.
  - Higher thresholds may detect fewer edges but can miss weaker boundaries.
- The `detectEdges()` function takes a grayscale image as input and returns an edge image as output.
- The OpenCV pipeline now looks like:
```text
load color image
→ convert to grayscale
→ blur grayscale image
→ detect edges
→ save grayscale and edge outputs
```
- This is the first step from simple image loading toward basic visual perception.

### Next Steps
- Review the full image-processing pipeline and make sure I can explain:
  - what each file does
  - what each function does
  - why edge detection uses grayscale input
  - why blur is applied before Canny
- Consider adding one more small improvement next:
  - command-line input/output paths
  - thresholding
  - saving output filenames more cleanly
  - a short architecture note for the current OpenCV module
- Continue keeping the project incremental, documented, and connected to the future ROS2 visual navigation system.

## 2026-06-07

### What I did

- Started Day 8 of the `ros2-visual-navigation` project.
- Continued improving the standalone C++/OpenCV image-processing pipeline.
- Changed `main()` from:
```cpp
int main()
```
to:
```cpp
int main(int argc, char* argv[])
```
- Added basic command-line input path support.
- Updated the program so it can run in two modes:
  - default mode:
```bash
./build/image_loader
```
  - custom input image mode:
```bash
./build/image_loader assets/test.jpg
```
- Learned the basic meaning of:
  - `argc`
  - `argv`
  - `argv[0]`
  - `argv[1]`
- Added automatic output-directory creation:
```cpp
std::filesystem::create_directories("outputs");
```
- Learned why the program should create the `outputs/` directory automatically before saving generated files.
- Successfully ran the program with a custom input path:
```bash
./build/image_loader assets/test.jpg
```
- Confirmed that the program:
  - loaded the custom input image
  - printed width, height, and channel count
  - saved `outputs/test_gray.jpg`
  - saved `outputs/test_edges.jpg`
- Tested output-directory creation by deleting `outputs/`:
```bash
rm -rf outputs
```
- Confirmed that the program recreated `outputs/` automatically.
- Verified generated output files with:
```bash
ls outputs
```

### Problems Encountered

- I needed clarification on why command-line arguments are useful.
- I needed to understand the difference between:
  - a hard-coded input path
  - a user-provided input path
- I needed clarification on why `std::filesystem::create_directories("outputs")` is useful.
- I needed to understand why a program should not depend too much on manual setup steps, such as creating the output folder by hand.

### What I Learned

- `argc` means argument count.
- `argv` stores command-line argument values.
- `argv[0]` is usually the program name or executable path.
- `argv[1]` is the first user-provided argument after the program name.
- This command:
```bash
./build/image_loader assets/test.jpg
```
means:
```text
argv[0] = ./build/image_loader
argv[1] = assets/test.jpg
```
- The program can now use a default image path if no argument is provided.
- The program can also use a custom image path if the user provides one.
- Hard-coded paths are simple, but less flexible.
- Command-line input makes the program more reusable.
- `std::filesystem::create_directories("outputs")` makes sure the output directory exists before saving images.
  - If `outputs/` does not exist, the program creates it.
  - If `outputs/` already exists, the program continues normally.
  - This makes the program more robust and reduces fragile manual setup assumptions.

### Next Steps

- Review the full pipeline and make sure I can explain:
  - `argc`
  - `argv`
  - default input path
  - custom input path
  - `std::filesystem::create_directories`
- Consider the next improvement:
  - cleaner output filenames based on the input image
  - better error messages
  - adding a small architecture note for the OpenCV module
- Continue moving gradually toward a reusable vision component that can later connect to ROS2.

## 2026-06-08

### What I did

- Started Day 9 of the `ros2-visual-navigation` project.
- Continued improving the standalone C++/OpenCV image-processing pipeline.
- Updated `src/image_loader.cpp` so output filenames are generated from the input image name.
- Used `std::filesystem::path` to treat the input image path as a filesystem path.
- Used `.stem().string()` to extract the base filename without the extension.
- Changed output paths from fixed names:
```bash
outputs/test_gray.jpg
outputs/test_edges.jpg
```
to generated names based on the input file:
```bash
outputs/<input_name>_gray.jpg
outputs/<input_name>_edges.jpg
```
- Added runtime print messages to show:
  - input image path
  - grayscale output path
  - edge output path
- Tested the program with a copied image:
```bash
cp assets/test.jpg assets/test2.jpg
./build/image_loader assets/test2.jpg
```
- Confirmed that the program generated:
```bash
outputs/test2_gray.jpg
outputs/test2_edges.jpg
```
- Created a new architecture note file `docs/opencv-module-notes.md`
- Documented the current purpose, pipeline, and file responsibilities of the OpenCV module.
- Updated the README to include the current OpenCV module progress.
- Committed and pushed today’s work to GitHub:
```bash
git add src/image_loader.cpp README.md docs/opencv-module-notes.md
git commit -m "Generate output filenames and document OpenCV module"
git push
```

### Problems Encountered

- I initially had a variable-name typo between:
  - `edges_output_path`
  - `edge_output_path`
- I needed clarification on how `std::filesystem::path` works.
- I needed to understand what `.stem().string()` does.
- I was unsure whether the temporary copied image `assets/test2.jpg` should be committed.

### What I Learned

- `std::filesystem::path` lets C++ represent and work with filesystem paths more cleanly than plain strings.
- `input_file.stem().string()` extracts the input filename without the extension.
- Generated output filenames make the program more reusable.
- Different input images no longer have to overwrite the same output files.
- Runtime debug messages make it easier to understand what the program is reading and writing.
- Temporary test files do not always need to be committed.
- A documentation file such as `docs/opencv-module-notes.md` is useful because it records the current architecture and responsibilities of the OpenCV module.
- The current OpenCV pipeline now works like this:
```text
input image path
→ extract input base filename
→ create output directory
→ generate output filenames
→ load image
→ convert to grayscale
→ detect edges
→ save generated outputs
```

### Next Steps
- Review `docs/opencv-module-notes.md` and make sure I can explain:
  - current module purpose
  - current pipeline
  - file responsibilities
  - how this module may later connect to ROS2
- Consider improving error handling next:
  - clearer message when input image path is wrong
  - clearer message when output saving fails
  - optional usage message for command-line input
- Continue moving the OpenCV module toward a reusable vision component for the future ROS2 visual navigation system.

## 2026-06-09

### What I did

- Started Day 10 of the `ros2-visual-navigation` project.
- Continued improving the standalone C++/OpenCV image-processing pipeline.
- Focused on making `image_loader` more robust as a command-line tool.
- Reviewed the current command-line usage:
```bash
./build/image_loader
./build/image_loader assets/test.jpg
```
- Added CLI validation for too many command-line arguments.
- Added a usage message for invalid command-line usage:
```text
Usage: ./build/image_loader [input_image_path]
```
- Added an input path existence check before loading the image with OpenCV.
- Used `std::filesystem::exists(input_path)` to check whether the input image path exists.
- Tested the missing input file case:
```bash
./build/image_loader assets/not_exist.jpg
```
- Confirmed that the program printed a clear error message:
```text
Error: input image does not exist: assets/not_exist.jpg
```
- Tested the too-many-arguments case:
```bash
./build/image_loader assets/test.jpg extra_argument
```
- Confirmed that the program printed the usage message:
```text
Usage: ./build/image_loader [input_image_path]
```
- Learned that CLI means command-line interface.
- Learned that validation means checking whether user input is acceptable before the main processing logic runs.

### Problems Encountered

- I needed to understand the difference between:
  - general error handling
  - input validation
  - command-line validation
- I needed to understand why checking argument count is useful.
- I needed to understand why checking whether the input path exists before calling OpenCV is better than only relying on OpenCV failure behavior.
- I had to make sure the program handled both valid and invalid command-line usage clearly.

### What I Learned

- CLI means command-line interface.
- In this project, the CLI is the way I run the program from the terminal, such as:
```bash
./build/image_loader assets/test.jpg
```
- CLI validation means checking whether the command-line input is valid before continuing.
- `argc` stores the number of command-line arguments.
- `argv` stores the command-line argument values.
- `argc > 2` means the user provided too many arguments for the current program design.
- A usage message tells the user how to run the program correctly.
- This code checks for too many arguments:
```cpp
if (argc > 2)
{
    std::cout << "Usage: " << argv[0] << " [input_image_path]" << std::endl;
    return 1;
}
  ```
- `std::filesystem::exists(input_path)` checks whether the input path exists before the program tries to load it.
- This code checks whether the image path exists:
```cpp
if (!std::filesystem::exists(input_path))
{
    std::cout << "Error: input image does not exist: " << input_path << std::endl;
    return 1;
}
  ```
- Validation is different from general error handling:
  - validation checks whether input is acceptable before the main work begins
  - error handling responds when something goes wrong
- The image-processing pipeline now has a clearer structure:
```text
read command-line arguments
→ validate argument count
→ choose default or custom input path
→ validate input path exists
→ create output directory
→ generate output filenames
→ load image
→ process image
→ save outputs
```
- The program is becoming less like a one-off script and more like a small engineering command-line tool.

### Next Steps
- Commit and push today's work:
```bash
git status
git add src/image_loader.cpp README.md docs/opencv-module-notes.md docs/learning-log.md
git commit -m "Add CLI validation for image loader"
git push
```
- Continue improving the OpenCV module gradually before connecting it to ROS2.
- Consider a future small improvement:
  - move path-generation logic into a helper function
  - add cleaner error messages
  - add a simple test checklist in documentation

