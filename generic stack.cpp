#include <bits/stdc++.h>
using namespace std;

// creating a linked list;
template<class T>
class Node {
public:
    T data;
    Node<T>* link;

// Constructor
    Node(T n)
    {
        this->data = n;
        this->link = NULL;
    }
};


template<class T>
class Stack {
    Node<T>* top;

public:
    Stack()
    { top = NULL; }

    void push(T data)
    {

        // Create new node temp and allocate memory in heap
        Node<T>* temp = new Node<T>(data);

        // Check if stack (heap) is full.
        // Then inserting an element would
        // lead to stack overflow
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }

        // Initialize data into temp data field
        temp->data = data;

        // Put top pointer reference into temp link
        temp->link = top;

        // Make temp as top of Stack
        top = temp;
    }

    // Utility function to check if
    // the stack is empty or not
    bool isEmpty()
    {
        // If top is NULL it means that
        // there are no elements are in stack
        return top == NULL;
    }

    // Utility function to return top element in a stack
    int peek()
    {
        // If stack is not empty , return the top element
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    // Function to remove
    // a key from given queue q
    void pop()
    {
        Node<T>* temp;

        // Check for stack underflow
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {

            // Assign top to temp
            temp = top;

            // Assign second node to top
            top = top->link;

            // This will automatically destroy
            // the link between first node and second node

            // Release memory of top node
            // i.e delete the node
            free(temp);
        }
    }

    // Function to print all the
    // elements of the stack
    void display()
    {
        Node<T>* temp;

        // Check for stack underflow
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {

                // Print node data
                cout << temp->data;

                // Assign temp link to temp
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

// Driven Program
int main()
{
    // Creating a stack
    Stack<int> s;

    // Push the elements of stack
    s.push(118);
    s.push(22);
    s.push(33);
    s.push(44);

    // Display stack elements
    s.display();

    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;

    // Delete top elements of stack
    s.pop();
    s.pop();

    // Display stack elements
    s.display();

    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;

    return 0;
}

