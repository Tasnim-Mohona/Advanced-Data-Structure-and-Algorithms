#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node<T> *next;
    node(T val)
    {
        this->data = val;
        this->next = NULL;
    }
};

template <class T>
class queue
{
public:
    node<T> *head;
    node<T> *tail;
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void enqueue(T data)
    {
        node<T> *newnode = new node<T>(data);
        if(this->tail==NULL)
        {
            this->head = newnode;
            this->tail = newnode;
        }
        else
        {
            this->tail->next = newnode;
            this->tail = newnode;
        }
    }
    void dequeue()
    {
        if(this->head==NULL) cout << "Queue is empty!" << endl;
        else {
            node<T> *tmp = this->head;
            this->head = this->head->next;
            delete tmp;
        }
    }
    void print()
    {
        if(this->head==NULL) cout << "Queue is empty!" << endl;
        node<T> *tmp = this->head;
        while (tmp!=NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;

    }
};
int main()
{
    queue<char> q;
        int n;
    char d;

    cout<<"IMPLEMENTING QUEUE" << endl;
    cout<<"---------------------------------------" << endl;
    cout<< "Insert Node Length : "; cin >> n;

    for(int i=0; i<n; i++)
    {
        cout<<"Insert Data "; cin >> d;
        q.enqueue(d);

    }
    cout<<"AFTER INSERT, QUEUE IS: ";
    q.print();
    q.dequeue();
    cout<<"AFTER POP DATA, QUEUE IS: ";
    q.print();
}
//    q.enqueue(1);
//    q.enqueue(2);
//    q.enqueue(3);
//    q.enqueue(4);
//    q.print();
//    q.dequeue();
//    q.dequeue();
//    q.dequeue();
//    q.print();
//    return 0;

/*for Commenting press CLTR +SHFT +C/*/

