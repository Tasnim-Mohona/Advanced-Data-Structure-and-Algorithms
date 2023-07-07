#include <iostream>
#include <string>
using namespace std;
class EmptyStackException
{
public:
    EmptyStackException()
    {
        cout << "Stack is empty!" << endl;
    }
};
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <class T>
class Stack
{

public:
    Node<T> *head;
    Stack()
    {
        this->head = NULL;
    }
    ~Stack()
    {
        Node<T> *temp = this->head;
        while(temp != NULL)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }
    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if(this->head==NULL) this->head = newNode;
        else {
            newNode->next = this->head;
            this->head = newNode;
        }
    }
    void pop()
    {
        if(this->head==NULL) cout << "Stack is empty!" << endl;
        else {
            Node<T> *tmp = this->head;
            this->head = this->head->next;
            delete tmp;
        }
    }
    bool isEmpty()
    {
        return this->head==NULL;
    }
    T top()
    {
        if(this->isEmpty()) throw EmptyStackException();
        else return this->head->data;
    }
    void print()
    {
        if(this->head==NULL) cout << "Stack is empty!" << endl;
        else {
            Node<T> *tmp;
            tmp = this->head;
            while (tmp!=NULL)
            {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }

    }

};

int main()
{
    // Stack<int> st;
    // st.push(5);
    // st.push(4);
    // st.push(3);
    // st.push(2);
    // st.push(1);


    // st.print();

    // st.pop();
    // st.pop();
    // st.pop();
    // st.print();
    // st.~Stack();
    // Stack<string> st;
    // st.push("Three");
    // st.push("Two");
    // st.push("One");
    // st.print();

    Stack<char> st;
    st.push('C');
    st.push('B');
    st.push('A');
    st.print();

    return 0;
}
