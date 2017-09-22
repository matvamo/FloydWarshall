## Floyd-Warshall

This project uses the Floyd-Warshall algorithm to find the shortest path between two nodes in a weighted graph. It uses both C++ and Python. Python interfaces with the compiled C++ library using ctypes. 

## Getting Started

Clone this repository and simply use make mac, linux or windows to build a dylib, so or dll file for Python to use. Make sure the LoadLibrary('./fwlib.dylib') statement in the Python program uses the library of your platform.

Then simply run the Python program. A sample weighted graph is included and the program will print the shortest path between two nodes.

## Prerequisites

The makefile assumes the g++ compiler is being used. Furthermore an installation of Python is required to run the Python program. 

## About

The program uses the following weighted grapgh as a demo

![Weighted graph](https://i.imgur.com/A93yjSj.png)

In the python program the amount of vertices are defined, and then using a Python list of lists the connections between these vertices are defined.

## Authors

* **Mathijs van Mourick*

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details