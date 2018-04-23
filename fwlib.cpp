#include <iostream>
#include <vector>
#define INF 99999

int numVertices = 0;
int numWeights = 0;
bool verbose = false;

int * floydWarshall(int weights[][3], int from, int to)
{
  // Declare the distance matrix
  double dist[numVertices][numVertices];

  //Initialise distance matrix with INF, and set vector distance to itself to 0
  for(int i = 0; i < numVertices; i++)
  {
    for(int j = 0; j < numVertices; j++)
    {       
        if(i==j)
          dist[i][j] = 0;
        else
          dist[i][j] = INF;
    }
  }

  if(verbose)
  {
    std::cout << "Initialized distance matrix\n";
    for(int i = 0; i < numVertices; i++)
    {
      for(int j = 0; j < numVertices; j++)
      {
        std::cout << dist[i][j] << " ";
        if(j == numVertices-1)
          std::cout <<"\n";
      }
    }
  }

  //Set the distance of each vertex as defined in weights
  for(int i = 0; i < numWeights; i++)
      dist[weights[i][0] - 1 ][weights[i][1] - 1] = weights[i][2];

  if(verbose)
  {
    std::cout << "\nInserted weights into distance matrix\n";
    for(int i = 0; i < numVertices; i++)
    {
        for(int j = 0; j < numVertices; j++)
        {
          std::cout << dist[i][j] << " ";
          if(j == numVertices-1)
            std::cout << "\n";
        }
    }
  }
  
  //Declare a second matrix to be able to retrieve path after fw algorithm terminates
  int next[numVertices][numVertices];
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

  if(verbose)
  {
    std::cout << "\nFloyd Warshall algorithm applied\n";
    for(int i = 0; i < numVertices; i++)
    {
      for(int j = 0; j < numVertices; j++)
      {
        std::cout << dist[i][j] << " ";
        if(j == numVertices-1)
          std::cout <<"\n";
      }
    }
  }
  
  //Declare a vectory array to store the shortest path in
  std::vector<int> array;
  array.reserve(20);
  
  //Check if vertex is reachable
  if(dist[from-1][to-1] == INF)
  {
    array.push_back(-1);
    array.shrink_to_fit();
    int * unreachable = array.data();
    return unreachable;
  }

  // Reconstruct the path and fill the result array  
  for(int i = 0 ; i < numVertices ; i++)
  {
    for(int j = 0 ; j < numVertices ; j++)
    {
      if(i != j)
      {
        int u = i+1;
        int v = j+1;
        if (u == from && v == to){
          array.push_back(u);
          while(u != v)
          {
            u = next[u - 1][v - 1];
            array.push_back(u);
          }
        }
      }
    }
  }

  array.shrink_to_fit();
  int * path = array.data();
  return path;
}

extern "C"
{
  void setNumVertices(int v)    { numVertices = v; }
  void setNumWeights(int w)     { numWeights = w;  }
  void setVerboseOutput(bool v) { verbose = v;     }
  int * fw(int arr[][3], int from, int to)
  {
    return floydWarshall(arr, from, to);
  }
}
