# Sorting Algorithm Comparison

This project compares the performance of various popular sorting algorithms when applied to large arrays of floating-point numbers.

## Introduction

The project implements and analyzes the performance of four different sorting algorithms:
- Quick Sort
- Heap Sort
- Merge Sort
- C++ default sort (std::sort)

Each algorithm is tested with the same large dataset of random floating-point numbers to evaluate efficiency and execution time.

## Project Structure

- `create.cpp`: Generates test data - creates 500,000 random floating-point numbers, sorts them, and saves to `create.txt` in descending order
- `hamsort.cpp`: Implements sorting using C++'s default std::sort function
- `heapsort.cpp`: Implements the Heap Sort algorithm
- `mergesort.cpp`: Implements the Merge Sort algorithm
- `quicksort.cpp`: Implements the Quick Sort algorithm

## Usage

1. Compile and run `create.cpp` to generate the test data file:
```bash
g++ create.cpp -o create
./create
```

2. Compile and run the different sorting algorithms:
```bash
g++ heapsort.cpp -o heapsort
./heapsort

g++ mergesort.cpp -o mergesort
./mergesort

g++ quicksort.cpp -o quicksort
./quicksort

g++ hamsort.cpp -o hamsort
./hamsort
```

3. Compare the execution time of each algorithm.

## Implementation Notes

- All files use the C++ standard library and `<bits/stdc++.h>`
- Array sizes and input file paths may differ between implementations:
  - `create.cpp`: Generates 500,000 elements and saves to `create.txt`
  - `hamsort.cpp`: Reads 1,000,000 elements from `TEST10.txt`
  - `heapsort.cpp`: Reads 100,100 elements from `TEST10.txt`
  - `mergesort.cpp`: Reads 200,100 elements from `TEST10.txt`
  - `quicksort.cpp`: Reads 90,000 elements from `TEST10.txt`

## Algorithm Analysis

| Algorithm  | Average Complexity | Worst Case Complexity | Auxiliary Space |
|------------|---------------------|----------------------|-----------------|
| Quick Sort | O(n log n)          | O(n²)                | O(log n)        |
| Heap Sort  | O(n log n)          | O(n log n)           | O(1)            |
| Merge Sort | O(n log n)          | O(n log n)           | O(n)            |
| std::sort  | O(n log n)          | O(n log n)           | O(log n)        |
