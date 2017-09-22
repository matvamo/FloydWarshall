import ctypes
import array
print ("Floyd Warshall shortest path between nodes")

lib = ctypes.cdll.LoadLibrary('./fwlib.dylib')

def main():
    nodes = 4;
    weights = [ [1, 3, -2], [ 2, 1, 4], [2, 3, 3], [3, 4, 2], [4,2,-1]]
    shortestPath(nodes, weights, 4, 3)

def shortestPath(amountOfVertices, weightsArray, fromNode, toNode):
    lib.setNumVertices(amountOfVertices)
    lib.setNumWeights(len(weightsArray))
    lib.fw.restype = ctypes.POINTER(ctypes.c_int)
    A = ((ctypes.c_int * 3) * 5)
    a = A()
    for i in range (0, 5):
        for j in range(0, 3):
            a[i][j] = weightsArray[i][j]
    shortestPath = lib.fw(a, fromNode, toNode)
    print ("Printing shortest path from node " + str(fromNode) + " to node " + str(toNode))
    for i in range (0, len(weightsArray) - 1 ):
        if i != len(weightsArray)-2:
            print(str(shortestPath[i]) + " -> ", end = '')
        else:
            print(str(shortestPath[i]), end = '')
main()
