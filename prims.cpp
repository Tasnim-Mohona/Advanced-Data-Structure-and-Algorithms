#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#define MX 110
using namespace std;

class Node
{public:
    int data;
    int w;
    Node* next;

     Node(int data, int w){
     this->data=data;
     this->w = w;
     next = NULL;
     }
};

/*Adjacency List*/

class AdjList
{ public:
    int val;
 Node *head;
};

/*Class Graph*/
class Graph
{
    public:
        bool vis[MX];
        int dist[MX];
        int key[9];
        int parent[9];
        int smallest;
//Queue q;
        list<int> Q;
        int nd,u;

        int v;
        AdjList* a;
        bool directed;

        Graph(int v)
        {
        this->v = v;
        a = new AdjList [v];
// directed= dir //total vertices
        for (int i = 0; i < v; ++i){
               a[i].val = i;
               a[i].head = NULL;
                }		//linking head of all vertices (array) to NULL ,it doesn't store any number only stores HEAD
        }


        void addEdge(int src, int dest, int weight)
        {
            Node * n1 = new Node(dest, weight);
            Node * n2 = new Node(src, weight);
            if (a[src].head == NULL && a[dest].head == NULL)
            { a[src].head = n1;
              a[dest].head= n2;
            }

            else if( a[src].head != NULL && a[dest].head == NULL ){

            n1->next= a[src].head;
            a[src].head= n1;
           // As a[dest].head is NULL
            a[dest].head = n2;

            }

            else if(a[src].head == NULL && a[dest].head != NULL){

             a[src].head = n1;
             n2->next= a[dest].head;
             a[dest].head= n2;

// As a[dest].head is NULL

            }
            else {
             n1->next= a[src].head;
             a[src].head= n1;

             n2->next= a[dest].head;
             a[dest].head= n2;
        	}
        }

int ExtractMin(list<int> q){
    int n;
    smallest=MX;
    list<int>::iterator it;
    for(it = q.begin(); it != q.end(); ++it){
    if(key[*it] < smallest){
        smallest = key[*it];
        n=*it;
        }
    }

    return n;
}








    void Prims(int source){
    int weight= MX;   //Initialize all key as infinite

     for(int i=0; i<v; ++i){
        Q.push_back(a[i].val);
     }

   for (int i = 0; i < v; ++i){
    key[i] = MX;
   }



//initialization
    key[source] = 0;  //source vertex is assigned 0, as it
    parent[source]= -1;

 while (!Q.empty()){

     u =  ExtractMin(Q); //minimum key vertex
     Q.remove(u);

       Node * temp = a[u].head;
       while(temp != NULL){
        int next = temp->data;
        int w_next = temp->w;

        list<int>:: iterator it2;

        for(it2 = Q.begin();it2 != Q.end(); ++it2){

        if(*it2 == next && w_next < key[next] ){
            parent[next]= u;
            key[next]= w_next;

                }
               }
               temp = temp->next;
       }
 }

    }






void printGraph()
        {
            int i;
            for (i = 0; i < v; ++i)
            {
                Node* tmp = a[i].head;
                cout<<"\n Adjacency list of vertex "<<i<<"\n head ";
                while (tmp)
                {
                    cout<<"-> "<<tmp->data;
                    tmp = tmp->next;
                }
                cout<<endl;
            }
        }
};


int main()
{
    int s,v;
    Graph g(v=9);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7,11);
    g.addEdge(2, 8, 2);

    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.printGraph();

    cout<<"\nEnter source: ";
    cin >> s;
    g.Prims(s);

     int sum=0;
    for(int i = 0; i < v; i++){

        sum = sum + g.key[i];
    }
    cout<< " "<<endl;
    cout<<"Cost of minimum spanning tree: "<<endl;
    cout<< sum <<endl;

cout<< " "<<endl;
    for(int k =0; k<v;k++){
        cout<< "parent of " << k << " is :" << g.parent[k]<< endl;
    }



    return 0;
}
