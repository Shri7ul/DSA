#include<bits/stdc++.h>
using namespace std;

struct ListNode{
  int data;
  ListNode *next;
 
};
ListNode *head=nullptr;
ListNode *tail=nullptr;

ListNode *CreateList(int data){
  ListNode *temp=new ListNode();
  temp->data=data;
  temp->next=nullptr;
  return temp;

}

void insertLast(int data){
 if(head==nullptr){
   head=CreateList(data);
   tail=head;
 }
 else{
   ListNode *temp=CreateList(data);
   tail->next=temp;
   tail=tail->next;
 }
}

void insertFirst(int data){
 if(head==nullptr){
   head=CreateList(data);
   tail=head;
 }
 else{
   ListNode *temp=CreateList(data);
   temp->next=head;
   head=temp;
 }
}
void PrintList(){
   for(ListNode *i=head;i != nullptr;i=i->next){
     cout<<i->data<<" ";
   }
   cout<<endl;
}

ListNode *Search(int key){
  for(ListNode *i=head;i !=nullptr;i=i->next){
    if(key==i->data){
      return i;
    }
  }
  return nullptr;
}

void DeleteFirst(){
   if(head==nullptr) return;
   else if(head==tail){
     free(head);
     head=tail=nullptr;
   }
   else{
     ListNode *temp=head;
     head=head->next;
     free(temp);
     temp=nullptr;
     }
}

void DeleteLast(){
 if(head==nullptr) return;
 else if(head==tail){
  free(head);
  head=tail=nullptr;
 }
 else {
   ListNode *temp=head;
   while(temp->next->next !=nullptr){
     temp=temp->next;
   }
   free(tail); //or free(temp->next);
   tail=temp;
   tail->next=nullptr;
 }
}

void deleteAfter(int key){
   ListNode *loc=Search(key); //delete loc-next
   ListNode *temp=loc->next;
   loc->next=loc->next->next;
   free(temp);
   temp=nullptr;
}
void InsertAfter(int data,int key){
  ListNode *loc=Search(key);
  ListNode *temp=CreateList(data);
  temp->next=loc->next;
  loc->next=temp;
}

int main() {
    insertLast(10);
    insertLast(20);
    insertLast(30);
    cout << "After insertLast(10, 20, 30): ";
    PrintList(); 

    
    insertFirst(5);
    cout << "After insertFirst(5): ";
    PrintList();  

    
    InsertAfter(15, 10);  
    cout << "After InsertAfter(15, 10): ";
    PrintList();  

    
    DeleteFirst();
    cout << "After DeleteFirst(): ";
    PrintList();  

    
    DeleteLast();
    cout << "After DeleteLast(): ";
    PrintList();  

    
    deleteAfter(10);  
    cout << "After deleteAfter(10): ";
    PrintList();  

    
    ListNode *node = Search(20);
    if (node) cout << "Found: " << node->data << endl;
    else cout << "Not Found" << endl;

    return 0;
}