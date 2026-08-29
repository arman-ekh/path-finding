# Path Finding Visualizer

A graphical path-finding application built with **C++ and Raylib**.

The project allows users to create and edit graphs visually, define nodes and edges, assign edge costs, and visualize different path-finding algorithms step by step.

## Features

* Create and delete graph nodes
* Create directed edges between nodes
* Set start and goal nodes
* Select and edit nodes graphically
* Visualize the graph in real time
* Run path-finding algorithms step by step
* Reset and restart algorithms

## Algorithms

Currently implemented algorithms:

* Breadth-First Search (BFS)
* Depth-First Search (DFS)
* Depth-Limited Search (DLS)
* Iterative Deepening Search (IDS)
* Uniform-Cost Search (UCS)

## Technologies

* **C++**
* **Raylib**
* **CMake**

## Project Structure

```text
src/
├── Algorithms/
│   ├── BFS.cpp
│   ├── DFS.cpp
│   ├── DLS.cpp
│   ├── IDS.cpp
│   └── UCS.cpp
│
├── Graph/
│   ├── Graph.cpp
│   ├── Graph_Node.cpp
│   └── Edge.cpp
│
├── EDITOR/
│   ├── GraphEditor.cpp
│   └── AlgorithmController.cpp
│
└── Visualization/
    ├── Graph_Renderer.cpp
    └── UI.cpp
```

## Goal

The main goal of this project is to provide a visual way to understand and compare different path-finding algorithms and how they explore a graph.

The project is currently under development.
