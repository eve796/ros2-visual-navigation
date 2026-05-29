# Learning Log

## 2026-05-25

### What I did

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

- Successfully connected to Rutgers iLab using SSH
- Logged into a remote Ubuntu 24.04 Linux machine
- Learned how remote Linux infrastructure works through terminal access
- Tested multiple Linux commands:
  - `ssh`
  - `which`
  - `find`
  - `ls`
- Investigated possible ROS2 installation paths such as '/opt/ros'
- Read Ruthers infrastructure documentation regarding:
  - virtual machines
  - Docker containers
  - user-managed environments
  - Linux compute systems

### Problems Encountered

- Initially misunderstood SSH command syntax
- Confused infrastructure\network access with software availability
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
- `git add` stages changes for the next commit, and Git’s documentation calls this staging area the “index.” :contentReference[oaicite:2]{index=2}
- `.gitignore` tells Git which files or directories to ignore, and already-tracked files must be untracked first with `git rm --cached`. :contentReference[oaicite:3]{index=3}

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
