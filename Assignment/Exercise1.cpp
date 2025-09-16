#include<bits/stdc++.h>
using namespace std;
struct Node{
   int data;
   Node *next;
};
Node *head=nullptr;
Node *tail=nullptr;
Node *head1=nullptr;
Node *head2=nullptr;
Node *tail1=nullptr;
Node *tail2=nullptr;

Node *CreateListNode(int data){
    Node *temp=new Node();
    temp->data=data;
    temp->next=nullptr;

    return temp;
}
void InsertFirst1(int data){
    if(head1==nullptr){
        head1=CreateListNode(data);
        tail1=head1;
    }
    else{
        Node *temp=CreateListNode(data);
        temp->next=head1;
        head1=temp;
    }
}
void InsertFirst2(int data){
    if(head2==nullptr){
        head2=CreateListNode(data);
        tail2=head2;
    }
    else{
        Node *temp=CreateListNode(data);
        temp->next=head2;
        head2=temp;
    }
}
void InsertLast1(int data){
  if(head1==nullptr){
        head1=CreateListNode(data);
        tail1=head1;
    }
    else{
        Node *temp=CreateListNode(data);
        tail1->next=temp;
        tail1=temp;
    }
}
void InsertLast2(int data){
  if(head2==nullptr){
        head2=CreateListNode(data);
        tail2=head2;
    }
    else{
        Node *temp=CreateListNode(data);
        tail2->next=temp;
        tail2=temp;
    }
}
void MergeNode(){
    tail1->next=head2;
    head=head1;
    tail=tail2;
}
void Sort() {
    if (head == nullptr) return;

    Node *i, *j;
    for (i = head; i != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data > j->data) {
                swap(i->data, j->data);
            }
        }
    }
}
void PrintList(){
    Node *temp=head;
    while(temp !=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    InsertFirst1(30);
    InsertLast1(10);
    InsertLast1(20);
    InsertLast1(50);
    InsertLast1(80);
    InsertFirst2(70);
    InsertLast2(90);
    InsertLast2(60);
    InsertLast2(100);
    InsertLast2(40);

    MergeNode();
    Sort();

    cout << "Merged & Sorted List: ";
    PrintList();
    return 0;
}

