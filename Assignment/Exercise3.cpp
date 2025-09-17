#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *next;
    Node *prev;
};
Node *head = nullptr;
Node *tail = nullptr;

Node *CreateNode(char data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void InsertLast(char data) {
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
    InsertLast('50');
    InsertLast('20');
    InsertLast('30');
    InsertLast('20');
    InsertLast('50');
    if (IsPalindrome()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    head = tail = nullptr;

    InsertLast('50');
    InsertLast('20');
    InsertLast('20');
    InsertLast('50');
    if (IsPalindrome()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    head = tail = nullptr;

    InsertLast('a');
    InsertLast('b');
    InsertLast('c');
    InsertLast('c');
    InsertLast('c');
    if (IsPalindrome()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

