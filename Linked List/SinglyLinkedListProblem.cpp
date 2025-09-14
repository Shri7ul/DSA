#include<bits/stdc++.h>
using namespace std;

struct ListNode{
   int data;
   ListNode *next;
};

ListNode *head=nullptr;
ListNode *tail=nullptr;

ListNode *CreateListNode(int data){
   ListNode *temp=new ListNode();
   temp->data=data;
   temp->next=nullptr;
   return temp;
}

void InsertFirst(int data){
    if(head==nullptr){
        head=CreateListNode(data);
        tail=head;
        return;
        }
    ListNode *temp=CreateListNode(data);
    temp->next=head;
    head=temp;
}

void InsertLast(int data){
   if(head==nullptr){
        head=CreateListNode(data);
        tail=head;
        return;
        }
    ListNode *temp=CreateListNode(data);
    tail->next=temp;
    tail=temp;

}

void DeleteFirst(){
    if(head==nullptr){
        cout<<"No Value Available";
        return;
        }
    else if(head==tail){
        free(head);
        head=tail=nullptr;
        return;
    }
    ListNode *temp=head;
    head=head->next;
    free(temp);

}

void DeleteLast(){
    if(head==nullptr){
        cout<<"No Value Available";
        return;
        }
    else if(head==tail){
        free(head);
        head=tail=nullptr;
        return;
    }
    ListNode *temp=head;
    while(temp->next->next !=nullptr){
        temp=temp->next;

    }
    free(tail);
    tail=temp;
    tail->next=nullptr;

}

ListNode *Search(int key){
    ListNode *temp=head;
    while(temp !=nullptr){
        if(temp->data==key){
            cout<<"Found";
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}
void PrintLIstNode(){
    ListNode *temp=head;
    while(temp != nullptr){
        cout<<temp->data;
        temp=temp->next;
    }

}
void InsertAfter(int key,int data){
   ListNode *loc=Search(key);
   if(loc==nullptr){
    cout<<"item Not Found";
    return;
   }
   ListNode *temp=CreateListNode(data);
   temp->next=loc->next;
   loc->next=temp;
}
void DeleteAfter(int key){
  ListNode *loc=Search(key);
  if(loc==nullptr){
    cout<<"item Not Found";
    return;
   }
   ListNode *temp=loc->next;
   loc->next=temp->next;
   free(temp);
}
int Sum(){
   int sum=0;
   ListNode *temp=head;
   while(temp!=nullptr){
    sum=sum+temp->data;
    temp=temp->next;

   }
   return sum;
}


int main(){
    int data,key,n;
    while(1){
        cout<<endl<<"1.Insert First"<<endl<<"2.Insert Last"<<endl<<"3.Insert After"<<endl<<"4.Delete First"<<endl<<"5.Delete Last"<<endl<<"6.Delete After"<<endl<<"7.Search"<<endl<<"8.Print"<<endl<<"9.Sum LinkedList"<<endl<<"10.Exit"<<endl;
        cin>>n;
       if(n==1){
        cin>>data;
        InsertFirst(data);
       }
       else if(n==2){
        cin>>data;
        InsertLast(data);
       }
       else if(n==3){
        cin>>key;
        cin>>data;
        InsertAfter(key,data);
       }
       else if(n==4){
        DeleteFirst();
       }
       else if(n==5){
        DeleteLast();
       }
       else if(n==6){
            cin>>key;
        DeleteAfter(key);
       }
       else if(n==7){
        cin>>key;
        Search(key);
       }
       else if(n==8){
        PrintLIstNode();
       }
       else if(n==9){

        cout<<"Sum="<<Sum()<<endl;
       }
       else if(n==10){
        break;
       }


    }

}

