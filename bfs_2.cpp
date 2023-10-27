#include<iostream>
#include<map> /*for the adjacency list*/
#include<list>
#include <queue>


using namespace std;


template <typename T>

class graph{
    map<T,list<T> > l; /* create a adjacency list named as l*/


public:
    int distance[100];
    int color[100];
    graph(){
        for (int i=0;i<100;i++) color[i]=0;
    }

    void addEdge(int x, int y){
    l[x].push_back(y);
    l[y].push_back(x);
    }
    bool bfs(T src){
        map<T,int> visited;
        queue<T> q;

        q.push(src);
        visited[src] = 1;
        distance[src] = 0;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";

            for(int nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = 1;
                    distance[nbr] = distance[node] + 1;
                    if (color[node]==0) color[nbr] = 1;
                    else color[nbr] = 0;
                    //
                } else {
                    if (color[node] == color[nbr]) return false;
                }
            }

        }
        return true;

    }

};

 int main(){
     bool is_bipsrtite;
 graph<int> g;

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 4);
  g.addEdge(1, 5);
  g.addEdge(2, 3);
  g.addEdge(4, 6);
  g.addEdge(5, 7);
  g.addEdge(6, 7);

 is_bipsrtite = g.bfs(0);
 cout << endl;

 if (is_bipsrtite) {
    cout << "Bipartite" << endl;
 } else {
 cout << "Not Bipartite" << endl;
 }

 for (int i = 0; i < 6; i++)
 {
     cout << "Distance of " << i << " from 0 is " << g.distance[i] << endl;
 }

 return 0;

}
