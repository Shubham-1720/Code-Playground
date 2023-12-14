#include <iostream>
using namespace std;

class Node
{
public:
int data;
Node * next;
Node(){
  next = nullptr;
}
};

class CLL
{
public:
Node * cursor;
CLL(){
  cursor = nullptr;
}
void insert_element(int num){
  Node * newNode = new Node();
  newNode->data = num;
  if(cursor==nullptr){
    cursor = newNode;
    cursor->next = cursor;
  }
  else{
    
    newNode->next = cursor->next;
    cursor->next = newNode;
  }
}

void remove(){
  if(cursor==nullptr){
    cout<<"CLL is already Empty"<<endl;
  }
  else if(cursor->next==cursor){
    cursor->next = nullptr;
    delete(cursor);
  }
  else{
    Node * temp = cursor->next;
    cursor->next = cursor->next->next;
    delete(temp);
  }
}
void search(int num){
  if(cursor==nullptr){
    cout<<"CLL is already Empty"<<endl;
  }
  else{
    Node * temp = cursor;
    while(temp->next != cursor){
      if(temp->data == num){
        cout<<"Element found"<<endl;
        return;
      }
      temp = temp->next;
    }
    if(temp->data == num){
      cout<<"Element found"<<endl;
    }
  }
}

void display(){
  if(cursor==nullptr)
    cout<<"CLL is empty"<<endl;
  else{
    Node * temp = cursor;
    while(temp->next != cursor){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<temp->data<<" ";
  }
  cout<<endl;
}
};

int main() {
  CLL mylist;
  mylist.insert_element(2);
  mylist.insert_element(4);
  mylist.insert_element(8);
  mylist.display();
  mylist.search(4);
  mylist.remove();
   mylist.remove();
   mylist.remove();
   mylist.remove();
  mylist.display();
}