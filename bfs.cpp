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
    void addEdge(int x, int y){
    l[x].push_back(y);
    l[y].push_back(x);
    }
    void bfs(T src){
        map<T,int> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        distance[src] = 0;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";

            for(int nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    distance[nbr] = distance[node] + 1;
                    //
                }
            }

        }

    }

};

 int main(){
 graph<int> g;

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 4);
  g.addEdge(1, 5);
  g.addEdge(2, 3);
  g.addEdge(4, 6);
  g.addEdge(5, 7);
  g.addEdge(6, 7);

 g.bfs(0);

 for (int i = 0; i < 6; i++)
 {
     cout << "Distance of " << i << " from 0 is " << g.distance[i] << endl;
 }

 return 0;

}
