Cluster Detection in 2D Grids
This project implements a solution for detecting and labeling clusters (connected components) in a 2D grid using the Breadth-First Search (BFS) algorithm. Each cluster consists of adjacent cells that share the same value (typically 1) and are connected either horizontally or vertically. The program identifies these clusters, assigns them a unique label, and calculates the area of each cluster.

Problem Overview
In many applications, data can be represented as a 2D grid of values (like a pixelated image or a grid map). In this case, the grid consists of binary values (0 and 1), where:

1 represents part of a cluster or block.
0 represents an empty cell or background.
The goal is to identify all distinct clusters of 1's, label them, and calculate the area (number of 1's) in each cluster.

Approach
We use the Breadth-First Search (BFS) algorithm to explore and label all connected components in the grid. BFS is well-suited for this task as it systematically explores each cell in the grid and checks its adjacent cells to see if they belong to the same cluster.

Key Features:
Cluster Detection: The program detects all clusters of connected 1's in the grid.
Labeling Clusters: Each detected cluster is given a unique number for easy identification.
Area Calculation: The program calculates the area of each cluster (number of 1's in each cluster).
Maximum Area: The largest cluster area is calculated and displayed as part of the output.

Input
The user is prompted to enter the number of rows and columns for the grid (1–50).
A 2D grid is input by the user, consisting of binary values (0 and 1). Each cell in the grid is either a 0 or a 1.
Output
The grid is printed with each cluster labeled by a unique integer starting from 2.
The area of each cluster is calculated and stored.
The maximum cluster area is printed at the end.

Example
For a grid input:

0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0
0 1 1 0 1 0 0 0 0 0 0 0 1
0 1 0 0 1 1 0 0 1 0 1 0 1
0 1 0 0 1 1 0 0 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0 0

The output labeled grid would be:

0   0   2   0   0   0   0   3   0   0   0   0   0
0   0   0   0   0   0   0   3   3   3   0   0   0
0   4   4   0   5   0   0   0   0   0   0   0   6
0   4   0   0   5   5   0   0   6   0   6   0   6
0   4   0   0   5   5   0   0   6   6   6   6   6
0   0   0   0   0   0   0   0   0   0   6   0   0
0   0   0   0   0   0   0   7   7   7   0   0   0
0   0   0   0   0   0   0   7   7   0   0   0   0

Max Area: 10 (Cluster 6 is the largest, covering 10 cells).

Algorithm
Input Validation: Ensures the user enters a valid number of rows and columns (between 1 and 50).
Grid Construction: Takes input from the user to build a 2D grid with binary values.
Cluster Detection: Uses BFS to detect and label each connected cluster of 1's.
Area Calculation: Counts the number of 1's in each labeled cluster.
Maximum Area: Determines the largest cluster in terms of area.
