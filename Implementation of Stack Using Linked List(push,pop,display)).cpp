#include <iostream>
using namespace std;

//Structure of the Node
struct Node
{
int data;
Node *next;
};

// top pointer to keep track of the top of the stack
Node *top = NULL;


//Function to insert an element in stack
void push (int value)
{
  Node *temp = new Node();
  temp->data = value;
  temp->next = top;
  top = temp;
}


//Function to check if stack is empty or not
bool EmptyStack()
{
 if(top == NULL)
 return true;
else
return false;
}

// Function to show the element at the top of the stack
void tip()
{
 if ( EmptyStack() )
  cout<<"Stack is Empty";
 else
  cout<<"Element at top is : "<< top->data;
}


//Function to delete an element from the stack
void pop ( )
{
 if ( EmptyStack() )
  cout<<"Stack is Empty";
 else
 {
  Node *temp = top;
  top = top -> next;
  delete(temp);
 }
}



// Function to Display the stack
void DisplayStack()
{
 if ( EmptyStack() )
  cout<<"Stack is Empty";
 else
 {
  Node *temp=top;
  while(temp!=NULL)
  {   cout<<temp->data<<" ";
   temp=temp->next;
  }
  cout<<"\n";
 }
 }

// Main function
int main()
{

 int input, flag=1, value;

 //Menu Driven Program using Switch
 while( flag == 1)
 {
 cout<<"\n 1.Push 2.Pop 3.tip 4.DisplayStack 5.exit\n";
 cin>>input;
 switch (input)
 {
 case 1: cout<<"Enter Value:\n";
         cin>>value;
         push(value);
         break;
 case 2: pop();
         break;
 case 3: tip();
         break;
 case 4: DisplayStack();
         break;
 case 5: flag = 0;
         break;
 }
 }

return 0;
}

