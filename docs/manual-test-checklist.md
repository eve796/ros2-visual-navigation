# Manual Test Checklist

## Image Loader

Run from the project root.

### Build

```bash
cmake -S . -B build
cmake --build build
```

## Test Cases

### Test 1: Default input

Command:

```bash
./build/image_loader
```

Expected result:

```text
Input image: assets/test.jpg
Grayscale output: outputs/test_gray.jpg
Edge output: outputs/test_edges.jpg
Image loaded successfully!
Grayscale image saved to: outputs/test_gray.jpg
Edge image saved to: outputs/test_edges.jpg
```

### Test 2: Custom input

Command:

```bash
./build/image_loader assets/test.jpg
```

Expected result:

```text
Input image: assets/test.jpg
Grayscale output: outputs/test_gray.jpg
Edge output: outputs/test_edges.jpg
Image loaded successfully!
Grayscale image saved to: outputs/test_gray.jpg
Edge image saved to: outputs/test_edges.jpg
```


### Test 3: Missing input file

Command:

```bash
./build/image_loader assets/not_exist.jpg
```

Expected result:

```text
Error: input image does not exist: assets/not_exist.jpg
```


### Test 4: Too many arguments

Command:

```bash
./build/image_loader assets/test.jpg extra_argument
```

Expected result:

```text
Usage: ./build/image_loader [input_image_path]
```
