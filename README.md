## Floyd-Warshall

This project uses the Floyd-Warshall algorithm to find the shortest path between two nodes in a weighted graph. It uses both C++ and Python. Python interfaces with the compiled C++ library using ctypes. 

## Getting Started

Clone this repository and simply use make mac, linux or windows to build a dylib, so or dll file for Python to use. Make sure the LoadLibrary('./fwlib.dylib') statement in the Python program uses the library of your platform.

Then simply run the Python program. A sample weighted graph is included and the program will print the shortest path between two nodes.

## Prerequisites

The makefile assumes the g++ compiler is being used. Furthermore an installation of Python is required to run the Python program. 

## About

The program uses the following weighted graph as a demo

![Weighted graph](https://i.imgur.com/A93yjSj.png)

In the python program the amount of vertices are defined, and then using a Python list of lists the connections between these vertices are defined.

Running the program will print the output like so:
![Program output](https://i.imgur.com/xfD1tTz.png)

## Authors

* **Mathijs van Mourick**

## License

This project is licensed under the MIT License.

Copyright 2017 Mathijs van Mourick

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
