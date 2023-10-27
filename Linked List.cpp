#include <iostream>
using namespace std;

class node {
public:
 int data;
 node *next;
};

void printlist(node* a)
{
    while(a!=NULL)
    {
        cout<<a->data<<" ";
        a=a->next;
    }
}




int main() {

  node* head = NULL;
  node* n1 = NULL;
  node* n2 = NULL;
  node* tail=NULL;
  head=new node();
  n1=new node();
  n2= new node();
  tail = new node();

  head->data=2;
  head->next=n1;

  n1->data=3;
  n1-> next=n2;

  n2->data=5;
  n2->next=tail;

  tail->data=7;
  tail->next=NULL;

  printlist(head);

  return 0;
}
