#include <iostream>
#include <string>
using namespace std;

template <class T> /*Declare a generic class*/

class node
{
public:
    T data;/*declare generic varibale called data*/
    node<T> *link;/*initialize node*/

    node(T data)
    {
        this->data = data;
        this->link = NULL;
    }
};
template <class T>
class stck
{

public:
     node<T> *head;
    void push(T data)
    {
        node<T> *newnode = new node<T>(data);
        if(this->head==NULL) this->head = newnode;
        else {
            newnode->link = this->head;
            this->head = newnode;
        }
    }
    void pop()
    {
        node<T> *tmp = this->head;
        this->head = this->head->link;
        delete tmp;
    }
    void print()
    {
         node<T> *tmp;
            tmp = this->head;
            while (tmp!=NULL)
            {
                cout << tmp->data << " ";
                tmp = tmp->link;
            }
            cout << endl;
    }
};

int main()
{
    stck<char> st;
    int n;
    char d;

    cout<<"IMPLEMENTING STACK" << endl;
    cout<<"---------------------------------------" << endl;
    cout<< "Insert Node Length : "; cin >> n;

    for(int i=0; i<n; i++)
    {
        cout<<"Insert Data "; cin >> d;
        st.push(d);

    }
    cout<<"AFTER INSERT, STACK IS: ";
    st.print();
    st.pop();
    cout<<"AFTER POP FIRST DATA, STACK IS: ";
    st.print();


}
