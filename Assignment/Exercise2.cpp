#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};
Node *head = nullptr, *tail = nullptr;

Node* CreateNode(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void InsertLast(int data) {
    if (head == nullptr) {
        head = CreateNode(data);
        tail = head;
    } else {
        Node *temp = CreateNode(data);
        tail->next = temp;
        tail = temp;
    }
}

void PrintList() {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void RemoveDuplicates() {
    Node *curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->data == curr->next->data) {
            Node *dup = curr->next;
            curr->next = curr->next->next;
            free(dup);
        } else {
            curr = curr->next;
        }
    }
}
int main() {
    int choice, val;
    while(1){
        cout<<"\nMenu:\n";
        cout<<"1. Insert into List\n";
        cout<<"2. Print List After Remove Duplicate\n";
        cout<<"3. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            cout<<"Enter value for List: ";
            cin>>val;
            InsertLast(val);
        }
        else if(choice==2){
            cout << "Original List: ";
            PrintList();

          RemoveDuplicates();

         cout << "After Removing Duplicates: ";
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



