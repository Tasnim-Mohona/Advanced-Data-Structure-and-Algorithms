// Kruskal's algorithm in C++

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
    public:
    vector<pair<int, edge> > G;  // graph
    vector<pair<int, edge> > T;  // mst
    int *set_list;
    int V;

    //public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};
Graph::Graph(int V) {
   //Make_set
  set_list = new int[V];

  for (int i = 0; i < V; i++)
    set_list[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == set_list[i])
    return i;
  else

    return find_set(set_list[i]);
}

void Graph::union_set(int u, int v) {
 set_list[u] = set_list[v];
}

void Graph::kruskal() {
  int i, us, vs;
  sort(G.begin(), G.end());  // sorting according increasing weight
  for (i = 0; i < G.size(); i++) {
    us = find_set(G[i].second.first);
    vs = find_set(G[i].second.second);
    if (us != vs) {
      T.push_back(G[i]);  // add to tree
      union_set(us, vs);
    }
  }
}
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;

    cout << endl;
  }
}
int main() {
  Graph g(9);


  g.AddWeightedEdge(0, 1, 54);
    g.AddWeightedEdge(0, 6, 47);
    g.AddWeightedEdge(0, 5, 80);

    g.AddWeightedEdge(1, 2,74);
    g.AddWeightedEdge(1, 6, 75);

    g.AddWeightedEdge(6, 2, 88);
    g.AddWeightedEdge(6, 7, 55);
    g.AddWeightedEdge(6, 4, 66);
    g.AddWeightedEdge(6, 5, 23);

    g.AddWeightedEdge(5, 7, 32);
    g.AddWeightedEdge(5, 4, 93);
    g.AddWeightedEdge(2, 3, 29);
    g.AddWeightedEdge(2, 7, 31);

    g.AddWeightedEdge(3, 7, 79);

    g.AddWeightedEdge(3, 4, 68);
    g.AddWeightedEdge(7, 4, 74);

    //g.AddWeightedEdge(7, 8, 7);


  g.kruskal();
  g.print();
  int cost=0;

  for (int i = 0; i < g.T.size(); i++) {
      cost= cost+ g.T[i].first;
  }
  cout<<""<<endl;
  cout<<"cost:"<< cost<<endl;
  return 0;
}
