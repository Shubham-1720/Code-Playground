#include<iostream>
using namespace std;

//defing template
template <typename T>

//defing class
class Node
{
    public:
    T data;
    Node<T> * next;
    Node<T>()
    {
        next = NULL;
    }
};

template <typename T>
class SLL 
{
    public:
    Node<T> * top;
    SLL<T>()
    {
        top = NULL;
    }
    void push(int num)
    {
        Node * ptr = new Node();
        ptr->data = num;
        ptr->next = top;
        top = ptr;
    }

    bool isEmpty()
    {
        if (top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Singly List is empty"<<endl;
        }
        else
        {
            Node* temp = top;
            top = top->next;
            cout<<"Data at deleted node is: "<<temp->data<<endl;
            delete(temp);
        }
        
    }

    void Top()
    {
        if(isEmpty())
        {
            cout<<"Singly List is empty"<<endl;
    }
    else{
        Node<T> * ptr = top;
        cout<<"Data of lists: ";
        cout <<ptr->data<<endl;
    }}

    void display()
    {
        Node<T> * ptr = top;
        cout<<"Data of lits: ";
        while(ptr!=nullptr)
        {
            cout <<ptr->data<<" , ";
            
            ptr = ptr->next;
        }
        cout << endl;
    }

};

int main()
{
    	
    SLL<int> myLinkedList;
    int num, choice;
    
     do {
        cout<< endl;
        cout << "Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Top" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to push: ";
                cin >> num;
                myLinkedList.push(num);
                break;
            case 2:
                myLinkedList.pop();
                break;
            case 3:
                myLinkedList.display();
                break;
            case 4:
                myLinkedList.Top();
                break;
            case 5:
                cout<<"Exiting from the program"<<endl;
                break;
            default:
                cout<<"Invalid choice.. Please try again.."<<endl;
                break;
        }
        } while (choice!=5);
        
        
    return 0;
}