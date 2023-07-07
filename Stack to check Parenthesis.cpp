#include <bits/stdc++.h>
using namespace std;

//Linked list
struct Node{
    char par;
    Node* next;
    Node (char h){
        par=h;
        next=NULL;
    }
};

Node* top;

void push(char par){
  Node* temp=new Node(par);
  temp->next = top;
  top = temp;
}

bool EmptyStack(){
    return top==NULL;
}

char tip(){
  if (!EmptyStack())
    return top->par;
  else
    return true;
}

void pop(){
    Node* temp;
    if (top==NULL){
       cout<<"Stack underflow";
        exit(1);
    }

    else{
        temp = top;
        top=top->next;
        free (temp);
    }
}

int main(){
    string parenthesis= "{[()]}";
    string input;

    cout<<"Balanced or Unbalanced?" <<endl;
    cout<<"Enter Expression: ";
    cin>>input;


for(int i=0;i<input.length();i++){
    if (parenthesis.find(input[i]) != string::npos){
    if(EmptyStack()){
        push (input[i]);
       }
    else if (tip()=='('&& input[i]==')' || tip() =='{'&&input[i]=='}' ||tip()=='['&&input[i]==']'){
      pop();
    }
      else{
        push(input[i]);
      }
    }
}

    if (EmptyStack()){
     cout<<"Balanced Expression";
    }

    else{
    cout<<"Unbalanced Expression" <<std::endl;
    }

    return 0;
}
