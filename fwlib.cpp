#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#define INF 99999

int numVertices = 0;
int numWeights = 0;

int * floydWarshall(int weights[][3], int from, int to)
{
  // Declare and initialize shortest path return array of nodes
  // and the distance matrix.
  int * result = (int *)malloc(numWeights);
  double dist[numVertices][numVertices];
  memset(dist, 0, numVertices * sizeof(int));

  //Fill distance matrix with INF
  for(int i = 0; i < numVertices; i++)
  {
    for(int j = 0; j < numVertices; j++)
    {
        dist[i][j] = INF;
    }
  }

  //Set the distance of each vertex as defined in weights
  for(int i = 0; i < numWeights; i++)
  {
      dist[weights[i][0] - 1 ][weights[i][1] - 1] = weights[i][2];
  }

  int next[numVertices][numVertices];
  memset(next, 0, numVertices * sizeof(int));

  for(int i = 0 ; i < numVertices ; i++)
  {
    for(int j = 0 ; j < numVertices ; j++)
    {
      if(i != j)
        next[i][j] = j + 1;
    }
  }

  //Iterate over the matrix and apply the Floyd-Warshall algorithm
  for(int k = 0 ; k < numVertices ; k++)
  {
    for(int i = 0 ; i < numVertices ; i++)
    {
      for(int j = 0 ; j < numVertices ; j++)
      {
        if(dist[i][k] + dist[k][j] < dist[i][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }

  //Reconstruct the path and fill the result matrix
  for(int i = 0 ; i < numVertices ; i++)
  {
    for(int j = 0 ; j < numVertices ; j++)
    {
      if(i != j)
      {
        int u = i+1;
        int v = j+1;

        if (u == from && v == to){
          int x = 1;
          result[0] = u;
          do
          {
            u = next[u - 1][v - 1];
            result[x] = u;
            x++;
          } while(u != v);
          return result;
        }
      }
    }
  }
  return result;
}

extern "C"
{
  void setNumVertices(int v) { numVertices = v; }
  void setNumWeights(int w)  { numWeights = w;  }
  int * fw(int arr[][3], int from, int to)
  {
    return floydWarshall(arr, from, to);
  }
}
