#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node * next;
  Node * prev;
  Node();
  friend class DLL;
};

class DLL{
    public:
    Node * head;
    DLL();
    void insert_at_begining(int);
    void insert_at_end(int);
    void insert_at_position(int, int);
    void delete_from_begining();
    void delete_from_end();
    void delete_from_position(int);
    void display();
};

Node::Node(){
    next = nullptr;
    prev = nullptr;
}

DLL::DLL(){
    head = nullptr;
}

void DLL::insert_at_begining(int num){
    Node * newNode = new Node();
    newNode->data = num;
    if(head == nullptr){
        head = newNode;
    }
    else{
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
        }
}

void DLL::insert_at_end(int num){
  Node * newNode = new Node();
  newNode->data = num;
  if(head == nullptr){
      head = newNode; 
  }
  else{
    Node * temp = head;
    while(temp->next != nullptr){
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

void DLL::insert_at_position(int num, int position){
  Node * newNode = new Node();
  newNode->data = num;
  Node * temp = head;
  int i = 1;
  while(i < (position-1)){
    temp = temp->next;
    i++;
  }
  newNode->next = temp->next;
  newNode->prev = temp;
  temp->next = newNode;
  
}

void DLL::delete_from_begining(){
  if(head == nullptr){
    cout<<"Doubly Linked List is Already Empty"<<endl;
  }
  else{
    Node * temp = head;
    head = temp->next;
    head->prev = nullptr;
    delete(temp);
  }
}

void DLL::delete_from_end(){
  if(head == nullptr){
    cout<<"Doubly Linked List is Already Empty"<<endl;
  }
  else{
    Node * temp = head;
    while(temp->next->next != nullptr){
      temp = temp->next;
    }
    Node * delnode = temp->next;
    temp-> next = nullptr;
    delete (delnode);
  }
}

void DLL::delete_from_position(int position){
  Node * temp = head;
  int i=1;
  while(i < (position)){
    temp = temp->next;
    i++;
  } 
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete (temp);
}

void DLL::display(){
  if(head == nullptr){
    cout<< "Doubly Linked List is Empty"<<endl;
  }

  else{
    cout<< "Elements in Doubly Linked List"<<endl;
    Node * temp = head;
    while(temp->next!=nullptr){
      cout<< temp->data << ", ";
      temp = temp->next;
    }
    cout<< temp->data <<endl;
  }
}

int main() {
DLL mylist;
int choice, element, position;
  do{
    cout<<endl;
cout<<"Menu for Doubly Linked List "<<endl;
  cout<<"1. Insert element at begining"<<endl;
  cout<<"2. Insert element at end"<<endl;
  cout<<"3. Insert element at given position"<<endl;
  cout<<"4. Delete element from begining"<<endl;
  cout<<"5. Delete element from end"<<endl;
  cout<<"6. Delete element from given position"<<endl;
  cout<<"7. Press 7 to exit"<<endl;
    cout<<"Enter your choice ";
    cin>>choice;
      
 switch (choice){
     case 1:
   
   cout<<"Enter the element"<<endl;
   cin>> element;
   mylist.insert_at_begining(element);
       mylist.display();
       cout<<endl;
   break;
   case 2:
     
      cout<<"Enter the element"<<endl;
      cin>> element;
      mylist.insert_at_end(element);
     mylist.display();
     cout<<endl;
   break;
   case 3:
     cout<<"Enter the element and position"<<endl;
     cin>> element>>position;
  mylist.insert_at_position(element, position);
     mylist.display();
     cout<<endl;
   break;
   case 4:
     mylist.display();
     mylist.delete_from_begining();
     cout<<"Element Deleted from begining"<<endl;
     mylist.display();
   break;

   case 5:
     mylist.display();
      mylist.delete_from_end();
      cout<<"Element Deleted from End"<<endl;
      mylist.display();
   break;
   case 6:
     mylist.display();
     cout<<"Enter the position"<<endl;
     cin>> position;
     mylist.delete_from_position(position);
     cout<<"Element Deleted from given position"<<endl;
     mylist.display();
   break;
   case 7:
   cout << "Exiting the program." << endl;
   break;

 }
  }while(choice != 7);

return 0;
}