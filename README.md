# Tree Data Structure Implementation

This repository contains implementations of two self-balancing binary search tree data structures: AVL Tree and Red-Black Tree. These implementations are used to analyze the performance and height characteristics of these trees with large datasets.

## Files in this Repository

### AVLTree.cpp
An implementation of the AVL Tree data structure in C++. AVL trees are height-balanced binary search trees where the difference in height between left and right subtrees of any node is at most 1. This implementation includes:

- Node creation and management
- Tree balancing through rotations (left, right, left-right, right-left)
- Insertion operations with automatic rebalancing
- Height calculation
- In-order traversal

The program reads integers from a data file and builds an AVL tree, then outputs the count of nodes and the tree height.

### RBTree.cpp
An implementation of the Red-Black Tree data structure in C++. Red-Black trees are self-balancing binary search trees with color properties that ensure the tree remains approximately balanced. This implementation includes:

- Node creation with color attributes (red and black)
- Tree balancing through rotations
- Insertion operations with color adjustments to maintain red-black properties
- Height calculation
- In-order traversal

Similar to the AVL tree implementation, this program reads integers from a data file, builds a Red-Black tree, and outputs the count of nodes and the tree height.

### Data.py
A Python script that generates large datasets for testing the tree implementations. It creates a file containing random integers:

- Generates up to 1,000,000 unique random integers between 0 and 10,000,000
- Writes these integers to a text file named 'Data2.txt'

### Test.txt
A small sample data file containing 5 integers (1, 2, 3, 4, 5) used for initial testing of the tree implementations.

## Usage

1. Generate test data using the Python script:
   ```
   python Data.py
   ```

2. Compile and run the AVL Tree implementation:
   ```
   g++ -o avl AVLTree.cpp
   ./avl
   ```

3. Compile and run the Red-Black Tree implementation:
   ```
   g++ -o rbtree RBTree.cpp
   ./rbtree
   ```

Both tree implementations will output the number of nodes processed and the final height of the tree.

## Purpose

This project demonstrates the implementation and comparison of different self-balancing binary search trees. It's useful for:

- Educational purposes to understand tree balancing algorithms
- Performance analysis of different tree structures with large datasets
- Comparing theoretical height guarantees with practical results

The code includes comments in Vietnamese for educational purposes, explaining the algorithms and balancing operations.

## Note

The implementation files (AVLTree.cpp and RBTree.cpp) are currently configured to read from specific data files (Data10.txt and Data5.txt). You may need to modify these filenames to match your generated data files.
