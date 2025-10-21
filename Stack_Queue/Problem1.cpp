#include<bits/stdc++.h>
using namespace std;

struct Node{
   char data;
   Node *next;
};

Node *top=nullptr;

void push(char c){
   Node *temp=new Node();
   temp->data=c;
   temp->next=top;
   top=temp;
}

char pop(){
    if (top == nullptr) return '/0';
    char c=top->data;
    Node *temp=top;
    top=top->next;
    free(temp);
    return c;
}

string reverseString(string str){
  for(char c : str){
    push(c);
  }
  string reversed="";

  while(top !=nullptr){
    reversed+=pop();
  }

  return reversed;
}

int main() {
    string s;
    getline(cin,s);
    cout << "Original: " << s << endl;
    cout << "Reversed: " << reverseString(s) << endl;
}
