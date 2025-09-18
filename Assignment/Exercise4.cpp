#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};
Node *head = nullptr;
Node *tail = nullptr;

Node* CreateNode(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void InsertLast(int data) {
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

void PrintList() {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

void BubbleSort() {
    if (head == nullptr) return;

    bool swapped;
    Node *temp= nullptr;

    do {
        swapped = false;
        Node *curr = head;

        while (curr->next != temp) {
            if (curr->data > curr->next->data) {
                swap(curr->data, curr->next->data);
                swapped = true;
            }
            curr = curr->next;
        }
        temp = curr;
    } while (swapped);
}
int main() {
    int choice, val;
    while(1){
        cout<<"\nMenu:\n";
        cout<<"1. Insert into List\n";
        cout<<"2. Print List After Sorting\n";
        cout<<"3. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            cout<<"Enter value for List: ";
            cin>>val;
            InsertLast(val);
        }
        else if(choice==2){
            cout << "Before Sorting: ";
          PrintList();

          BubbleSort();

        cout << "After Sorting: ";
         PrintList();
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


