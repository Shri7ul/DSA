#include<bits/stdc++.h>
using namespace std;

struct Node {
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

void InsertLast1(int data){
    if(head1==nullptr){
        head1=CreateListNode(data);
        tail1=head1;
    } else {
        Node *temp=CreateListNode(data);
        tail1->next=temp;
        tail1=temp;
    }
}

void InsertLast2(int data){
    if(head2==nullptr){
        head2=CreateListNode(data);
        tail2=head2;
    } else {
        Node *temp=CreateListNode(data);
        tail2->next=temp;
        tail2=temp;
    }
}

void MergeNode(){
    if(head1==nullptr) { 
        head=head2;
        tail=tail2;
    }
    else {
        tail1->next=head2;
        head=head1;
        tail=tail2;
    }
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
    cout<<endl;
}

int main() {
    int choice, val;
    while(1){
        cout<<"\nMenu:\n";
        cout<<"1. Insert into List1\n";
        cout<<"2. Insert into List2\n";
        cout<<"3. Merge, Sort & Print\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            cout<<"Enter value for List1: ";
            cin>>val;
            InsertLast1(val);
        }
        else if(choice==2){
            cout<<"Enter value for List2: ";
            cin>>val;
            InsertLast2(val);
        }
        else if(choice==3){
            MergeNode();
            Sort();
            cout<<"Merged & Sorted List: ";
            PrintList();
        }
        else if(choice==4){
            cout<<"Exiting...\n";
            break;
        }
        else{
            cout<<"Invalid choice!\n";
        }
    }
    return 0;
}

