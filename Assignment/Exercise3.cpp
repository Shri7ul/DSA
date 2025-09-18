#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *next;
    Node *prev;
};
Node *head = nullptr;
Node *tail = nullptr;

Node *CreateNode(string data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void InsertLast(string data) {
    if (head == nullptr) {
        head = CreateNode(data);
        tail = head;
    } else {
        Node *temp = CreateNode(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

bool IsPalindrome() {
    Node *left = head;
    Node *right = tail;

    while (left != right && right->next != left) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    int choice;
    string val;
    while(1){
        cout<<"\nMenu:\n";
        cout<<"1. Insert into List\n";
        cout<<"2. Check is Palindrome\n";
        cout<<"3. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            cout<<"Enter value for List: ";
            cin>>val;
            InsertLast(val);
        }
        else if(choice==2){
              if (IsPalindrome()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

        }
        else if(choice==3){
            cout<<"Exiting...\n";
            break;
        }
        else{
            cout<<"Invalid choice!\n";
        }
    }
    return 0;
}

