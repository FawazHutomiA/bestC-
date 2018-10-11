#include <iostream>
#include <stdlib.h>
#include <list>
#include <cmath>
#include <fstream>


using namespace std;

class Graph {
    int numVertices;
    list<int> *adjacencyList;

  public:
     Graph(int numVertices);
     void addEdge(int v, int w);
     void BestFirstSearch(int start);
};

Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    adjacencyList = new list<int>[numVertices];
}

void Graph::addEdge(int v, int w)
{
    adjacencyList[v].push_back(w);
} 

void Graph::BestFirstSearch(int start)
{
    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
    {
       visited[i] = false;
    }

    list<int> queue;

    visited[start] = true;
    queue.push_back(start);
    list<int>::iterator i;

    while(!queue.empty())
    {
      start = queue.front();
      cout << start << " " << '\n';
      queue.pop_front();

        for(i = adjacencyList[start].begin(); i != adjacencyList[start].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
       } 

}

} 

 int main() {

    int x, y, lines;
    float distance;
    Graph g(4); //Create 4 vertices.
    ifstream read("test.txt");
    while(read>>x>>y) {
       g.addEdge(x, y); //makes edges with point provided.
       g.BestFirstSearch(0); //start at the first node/vertex.

    }
    //lines = c1.size();    

   //distance = sqrt(pow(e, 2) + pow(f, 2));

  //cout << distance << "" << endl;

  return 0;
}