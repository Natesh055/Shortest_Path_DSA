# Dijkstra's Algorithm Implementation

This project implements Dijkstra's Algorithm in C++ to find the shortest path between two nodes in a graph. The graph is represented using an adjacency list, and the algorithm efficiently computes the shortest path using a priority queue (min-heap).

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Input Format](#input-format)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Dijkstra's Algorithm is a well-known algorithm for finding the shortest paths between nodes in a graph, particularly in cases where the edges have non-negative weights. This implementation allows users to input a graph with a set of nodes and edges (with weights) and then computes the shortest path between two specified nodes.

## Features

- Supports custom input of nodes and distances.
- Handles any graph with non-negative weights.
- Outputs the shortest path and the corresponding total distance.
- Easily customizable for different types of graphs and inputs.

## Installation

To run this project, you will need a C++ compiler. The steps below outline how to set up and compile the project:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/yourusername/dijkstra-algorithm.git
    cd dijkstra-algorithm
    ```

2. **Compile the code**:
    ```bash
    g++ -o dijkstra dijkstra.cpp
    ```

3. **Run the program**:
    ```bash
    ./dijkstra
    ```

## Usage

When you run the program, it will prompt you for the following inputs:

1. **Total number of nodes/stations**: The number of nodes in your graph.
2. **Name of nodes**: A list of names for each node.
3. **Distances between nodes**: The distance between each pair of nodes. Enter `0` if no direct path exists.
4. **Starting and Ending nodes**: The nodes between which you want to find the shortest path.

## Input Format

- **Node names**: Provide names for each node in the graph.
- **Distances**: Provide the distances between nodes. If no direct path exists, enter `0`.
- **Starting and Ending nodes**: Provide the indices (0-based) of the start and end nodes.

### Example

Sample input and output:

```plaintext
Enter Total Number of nodes/Stations:
5

Enter name of nodes:
A
B
C
D
E

Enter distance from A to B:
10

Enter distance from A to C:
5

Enter distance from B to C:
2

Enter distance from B to D:
1

Enter distance from C to E:
2

Enter Starting node (0-based index):
0

Enter Ending node (0-based index):
4

Output:
Shortest path from 0 to 4 is: 0 2 4
Total distance: 7
