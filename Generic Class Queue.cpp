#include<bits/stdc++.h>
using namespace std;

template<class T>

class Node
{
public:

    T data;
    Node *next ;

Node(T n)
    {
        this->data = n;
        this->next = NULL;
    }
};

template<class T>

class Queue
{
    Node<T> *front, *rear;
public:
    Queue()
    {
        front = rear = NULL;  //   Initially
    }
    void Enqueue(T elem)    // for insertion from rear
    {
        Node<T> *newnode;
        newnode = new Node<T>(elem);
        newnode->data = elem;
        newnode->next = NULL;
        if(front == NULL)
            front = rear = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    void Dequeue()            // for deletion from front
    {
        Node<T> *temp;
        if(front == NULL)
            cout<<"Queue is Empty";
        else
        {
            temp= front;
            front = front->next;
            delete temp;
        }
    }
    void display()
    {
        Node<T> *temp;
        temp= front;
        while(temp!=NULL) // (temp!= rear->next)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Queue<int> Q1;
    Q1.Enqueue(10);
    cout<<"Queue after First Enqueue :";
    Q1.display();
    cout<<"\n";
    Q1.Enqueue(20);
    cout<<"Queue after Second Enqueue :";
    Q1.display();
    cout<<"\n";
    Q1.Dequeue();
    cout<<"Queue after Dequeue :";
    Q1.display();
}
