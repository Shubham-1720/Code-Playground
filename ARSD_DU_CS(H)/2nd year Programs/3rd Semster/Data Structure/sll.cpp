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

class SLL
{
public:
Node * head;
void insert_at_beg(int);
void insert_at_position(int, int);
void delete_from_beg();
void delete_from_position(int);
Node * Search(int);
void display(){
  Node * ptr = head;
  cout<<"Singly Linked List is"<<endl;
  if (ptr == nullptr) {
      cout << "List is empty." << endl;
      return;
  }
  
  while(ptr != nullptr){
    cout<<ptr->data<<" ";
    ptr = ptr->next;
    }
  cout<<endl;
}
SLL(){
  head = nullptr;
}
};

void SLL::insert_at_beg(int num){
  Node * newNode = new Node();
  newNode->data = num;
  if(head==nullptr){
    head = newNode;
  }
  else{
    newNode->next = head;
    head = newNode;
  }
}

void SLL::insert_at_position(int num, int position){
  Node * newNode = new Node();
  newNode->data = num;
  if(head==nullptr){
    head=newNode;
  }
  else if(position == 1){
    insert_at_beg(num);
  }
  else{
    Node * ptr = head;
    int i = 1;
    while(i<(position-1)){
      ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
  }
  
}

void SLL:: delete_from_beg(){
  if(head==nullptr){
    cout<<"Singly Linked List is already empty"<<endl;
  }
  else{
    Node * ptr = head;
    cout<<"Data at deleted Node is: "<<ptr->data<<endl;
    head = ptr->next;
    delete(ptr);
    
  }
}

void SLL::delete_from_position(int position){
  if(head==nullptr){
    cout<<"Singly Linked List is already empty"<<endl;
  }
  else{
    Node * ptr = head;
    Node * delptr;
    int i = 1;
    while(i<(position-1)){
      ptr = ptr->next;
    }
    delptr = ptr->next;
    ptr->next = ptr->next->next;
    delete(delptr);
  }
  
}

Node * SLL::Search(int num){
  Node * ptr = head;
  while(ptr!=nullptr){
    if(ptr->data == num){
      return ptr;
    }
    ptr = ptr->next;
    
  }
  return nullptr;
}

int main() {
  SLL mylist;
  mylist.insert_at_beg(2);
  mylist.insert_at_beg(6);
  mylist.insert_at_beg(3);
  mylist.display();
  mylist.insert_at_position(9,2);
  mylist.display();
  mylist.insert_at_position(0,1);
  mylist.display();
  mylist.delete_from_beg();
  mylist.display();
  mylist.delete_from_position(2);
  mylist.display();
  
  
}