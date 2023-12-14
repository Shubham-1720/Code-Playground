#include <iostream>
using namespace std;
const int size = 5;
class Queue
{
 int front;
 int rear;
 int queue[size];
 public:
 Queue(){
   front = rear = -1;
 }
bool isFull(){
  return ((rear + 1) % size == front);
}
bool isEmpty(){
  return (front == -1 && rear == -1);
}
 void Enqueue(int num){
   if(isFull()){
     cout<<"Queue is already full"<<endl;
     return;
   }
    if(isEmpty()){
      front = rear = 0;
    }
      else{
        rear =(rear+1) % size;
      }
     queue[rear] = num;
   cout<<"Element Equeued"<<endl;
 }
void dequeue(){
  if(isEmpty()){
    cout<<"Queue is already empty"<<endl;
    return;
  }
  queue[front] = 0;
  cout<<"Element Dequeue"<<endl;

  if(front==rear){
    // Last element in the queue
    front = rear = -1;
  }
  else{
    front = (front + 1) % size;
  }
}
void peek(){
  if(isEmpty()){
    cout<<"Queue is empty"<<endl;
  }
  cout<<queue[front];
}

void display(){
  if(isEmpty()){
    cout<<"Queue is empty"<<endl;
  }
  else{
    for(int i = front; i<= rear; i++){
      cout<<queue[i]<<" ";
      
    }
    cout<<endl;
  }
}
};
int main() {
  Queue myqueue;
  myqueue.Enqueue(2);
  myqueue.Enqueue(6);
  myqueue.Enqueue(9);
  myqueue.display();
  myqueue.dequeue();
  myqueue.display();
  myqueue.peek();
}