import ctypes
import array
import sys
import unittest

if(sys.platform == "darwin"):
    lib = ctypes.cdll.LoadLibrary('./fwlib.dylib')
elif (sys.platform == "linux"):
    lib = ctypes.cdll.LoadLibrary('./fwlib.so')
elif(sys.platform == "win32"):
    lib = ctypes.cdll.LoadLibrary('./fwlib.dll')
else:
    print("Platform unsupported! Exiting...")
    sys.exit(1)

class TestSolvingGraphs(unittest.TestCase):
    def testGraph1a(self):
        nodes = 4
        weights = [[1, 2, 3], [1, 4, 1], [1, 3, 3], [3, 4, 1], [4, 3, 1], [4, 2, 1]]
        self.assertEqual(shortestPath(nodes, weights, 1, 2), "1 -> 4 -> 2")
    
    def testGraph1b(self):
        nodes = 4
        weights = [[1, 2, 3], [1, 4, 1], [1, 3, 3], [3, 4, 1], [4, 3, 1], [4, 2, 1]]
        self.assertEqual(shortestPath(nodes, weights, 3, 3), "3")

    def testGraph2(self):
        nodes = 4
        weights = [ [1, 3, -2], [ 2, 1, 4], [2, 3, 3], [3, 4, 2], [4,2,-1]]
        self.assertEqual(shortestPath(nodes, weights, 4, 3), "4 -> 2 -> 1 -> 3")
    
    def testGraph3a(self):
        nodes = 6
        weights = [[1, 2, 2], [2, 3, 2], [3, 4, 2], [4, 5, 2], [5, 6, 2], [6, 1, 2], [1, 3, 3], [3, 5, 3], [5, 1, 3]]
        self.assertEqual(shortestPath(nodes, weights, 2, 1), "2 -> 3 -> 5 -> 1")
    
    def testGraph3b(self):
        nodes = 6
        weights = [[1, 2, 2], [2, 3, 2], [3, 4, 2], [4, 5, 2], [5, 6, 2], [6, 1, 2], [1, 3, 3], [3, 5, 3], [5, 1, 3]]
        self.assertEqual(shortestPath(nodes, weights, 6, 4), "6 -> 1 -> 3 -> 4")

    def testGraph4(self):
        nodes = 4
        weights = [[1, 2, 1], [2, 3, 2], [3, 4, -1], [4, 1, 2],[1, 3, 2], [3, 1, 2]]
        self.assertEqual(shortestPath(nodes, weights, 2, 1), "2 -> 3 -> 4 -> 1")

    def testGraph5(self):
        nodes = 4
        weights = [[1, 2, 1], [2, 3, 1], [3, 1, 1], [4, 1, 1]]
        self.assertEqual(shortestPath(nodes, weights, 1, 4), "Unreachable")    

def main():
    unittest.main()

    #Graph 1
    # nodes = 4
    # weights = [[1, 2, 3], [1, 4, 1], [1, 3, 3], [3, 4, 1], [4, 3, 1], [4, 2, 1]]
    # print(shortestPath(nodes, weights, 1, 2))

def shortestPath(amountOfVertices, weightsArray, fromNode, toNode):
    if(fromNode == toNode):
        return str(fromNode)
    lib.setNumVertices(amountOfVertices)
    lib.setNumWeights(len(weightsArray))
    lib.fw.restype = ctypes.POINTER(ctypes.c_int)
    A = ((ctypes.c_int * 3) * len(weightsArray))
    a = A()
    for i in range (0, len(weightsArray)):
        for j in range(0, 3):
            a[i][j] = weightsArray[i][j]
    shortestPath = lib.fw(a, fromNode, toNode)
    i = 0
    currNode = fromNode
    pathString = ''
    while (str(currNode) != str(toNode)):
        if(shortestPath[i] == -1):
            return "Unreachable"
        if(shortestPath[i] == toNode):
            pathString += str(shortestPath[i])
        else:
            pathString += str(shortestPath[i]) + " -> "
        currNode = shortestPath[i]
        i += 1
    return pathString
main()
