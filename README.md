# Sorting-Using-Pthreads

## Project Overview
This project enhances the Bubble Sort algorithm implemented in Program 3 by incorporating multi-threading with `pthreads` to achieve parallel processing. The goal is to sort 1 million unsorted numbers using 16 threads and compare the performance improvement over a single-threaded approach. The program divides the input array into 8 sections, sorts each section in parallel, and then merges the sorted sections into a fully sorted array. The final sorted array is printed to a file.

## Objectives
- Utilize `pthread` to implement multi-threading in C++.
- Split a large dataset into multiple sections and sort them concurrently using the Bubble Sort algorithm.
- Merge sorted sections to create a fully sorted dataset.
- Measure and compare sorting time improvements due to parallelization.

## Key Features
- **Multi-threaded Sorting**: The array is divided into 8 sections, and each section is sorted by a separate thread using the Bubble Sort algorithm.
- **Parallel Processing**: The program uses 16 threads to achieve substantial performance gains by leveraging multi-core CPUs.
- **Dynamic Memory Allocation**: The array of 1 million numbers is dynamically allocated and properly cleaned up at the end of the program.
- **Merging Sorted Sections**: After all sections are sorted in parallel, the program merges adjacent sections two at a time until the entire array is sorted.
- **Automated Result Verification**: The program generates output that can be verified for correctness and sorting order.

## How It Works
1. **Input**: The program reads 1 million unsorted numbers from `numbers.dat` into an array.
2. **Thread Creation**: The array is divided into 8 sections, and 8 threads are created using `pthread_create()`. Each thread sorts its respective section using the existing Bubble Sort algorithm from Program 3.
3. **Sorting**: The threads sort their assigned sections in parallel.
4. **Merging**: Once sorting is complete, adjacent sorted sections are merged together until a fully sorted array is produced.
5. **Output**: The sorted array is written to a file for verification.

## File Descriptions
- **`mySort.cpp`**: Contains the C++ source code that implements the multi-threaded sorting program using `pthreads`.
- **`generate.cpp`**: A helper program (from Program 3) that generates 1 million random numbers and saves them to `numbers.dat`.
- **`sortrace.sh`**: A shell script used to automate the sorting process and capture performance statistics.
- **`sortrace.log`**: A log file that contains the execution results of the sorting process.

## Compilation Instructions
To compile the multi-threaded sorting program, use the following command:
```bash
g++ mySort.cpp -o mySort -pthread
