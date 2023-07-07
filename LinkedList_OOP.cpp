#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        cout << "constructor running"<<endl;
        data = val;
        next = NULL;
    }
};
class LinkedList
{

public:
    Node *head;
    LinkedList()
    {
         head = NULL;
    }
    void insertAtFirst(Node *n)
    {
        if(this->head == NULL) {
            this->head = n;
        }
        else {
            n->next = this->head;
            this->head=n;
        }
    }
    void insertAtLast(Node *n)
    {
        if(this->head == NULL) {
            this->head = n;
        }
        else {
            Node *tmp = this->head;
            while(true) {
                if(tmp->next==NULL) {
                    tmp->next = n;
                    break;
                }
                tmp=tmp->next;
            }

        }
    }
    void insertAtPosition(Node *n, int pos)
    {
        if(pos==0){
            this->insertAtFirst(n);
        }
        else {
            Node *tmp = this->head;
            int c = 1;
            while(true) {
                if(c==pos) {
                    n->next=tmp->next;
                    tmp->next=n;
                    break;
                }
                if(tmp->next==NULL) {
                    break;
                }
                tmp=tmp->next;
                c++;
            }
        }
    }
};

int main()
{
   // Node *n = new Node(56);
    LinkedList l_list;
    //cout << l_list.head << endl;

    l_list.insertAtFirst(new Node(1));
    l_list.insertAtFirst(new Node(2));
    l_list.insertAtFirst(new Node(3));


    //cout << l_list.head->data;
    Node *tmp = l_list.head;
    while(tmp!=NULL) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
    cout << endl;
    l_list.insertAtLast(new Node(18));
    tmp = l_list.head;
    while(tmp!=NULL) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
    cout << endl;
    l_list.insertAtPosition(new Node(15), 3);
    tmp = l_list.head;
    while(tmp!=NULL) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }




}
