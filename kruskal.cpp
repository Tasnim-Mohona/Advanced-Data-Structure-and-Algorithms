#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
    private:
    vector<pair<int, edge> > G;  // graph
    vector<pair<int, edge> > T;  // mst
    int *parent;
    int V;  // number of vertices/nodes in graph

    public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,

    return find_set(parent[i]);   // so we recursively call Find on its parent
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, U, V;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    U = find_set(G[i].second.first);
    V = find_set(G[i].second.second);
    if (U != V) {
      T.push_back(G[i]);  // add to tree
      union_set(U, V);
    }
  }
}
void Graph::print() {
  cout << "Edge  |"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}
int main() {
  Graph g(9);


    g.AddWeightedEdge(0, 1, 4);
    g.AddWeightedEdge(0, 7, 8);
    g.AddWeightedEdge(1, 2, 8);
    g.AddWeightedEdge(1, 7,11);
    g.AddWeightedEdge(2, 8, 2);
    g.AddWeightedEdge(2, 3, 7);
    g.AddWeightedEdge(2, 5, 4);
    g.AddWeightedEdge(3, 4, 9);
    g.AddWeightedEdge(3, 5, 14);
    g.AddWeightedEdge(4, 5, 10);
    g.AddWeightedEdge(5, 6, 2);
    g.AddWeightedEdge(6, 7, 1);
    g.AddWeightedEdge(6, 8, 6);
    g.AddWeightedEdge(7, 8, 7);

  g.kruskal();
  g.print();
  return 0;
}
