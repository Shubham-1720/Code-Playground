#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    };
};

class SLL
{
private:
    Node *head;

public:
    SLL();
    void insert_element(int);
    

    void delete_element();
    
    int lsearch(int num);
    void reverseNode();
    void mergeNode(SLL myList2);
    void display();
};

SLL::SLL()
{
    head = NULL;
}

void SLL::insert_element(int num)
{
    Node *newNode = new Node();
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}


void SLL::delete_element()
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}


int SLL::lsearch(int num)
{
    int loc = 1;
    while (head != nullptr)
    {
        if (head->data == num)
        {
            return loc;
        }
        loc++;
        head = head->next;
    }

    return -1;
}

void SLL::reverseNode()
{
    Node *prev, *next1, *curr = head;
    prev = next1 = nullptr;

    while (curr != nullptr)
    {
        next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
    }
    head = prev;
}

void SLL::mergeNode(SLL myList2)
{
    Node *ptr1 = head;
    Node *ptr2 = myList2.head;
    Node *mergedList = nullptr;
    Node *ptr3 = nullptr;

    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        Node *newNode = new Node();

        if (ptr1->data < ptr2->data)
        {
            newNode->data = ptr1->data;
            ptr1 = ptr1->next;
        }
        else
        {
            newNode->data = ptr2->data;
            ptr2 = ptr2->next;
        }

        if (mergedList == nullptr)
        {
            mergedList = ptr3 = newNode;
        }
        else
        {
            ptr3->next = newNode;
            ptr3 = ptr3->next;
        }
    }

    while (ptr1 != nullptr)
    {
        Node *newNode = new Node();
        newNode->data = ptr1->data;

        ptr3->next = newNode;
        ptr3 = ptr3->next;
        ptr1 = ptr1->next;
    }

    while (ptr2 != nullptr)
    {
        Node *newNode = new Node();
        newNode->data = ptr2->data;

        ptr3->next = newNode;
        ptr3 = ptr3->next;
        ptr2 = ptr2->next;
    }

    head = mergedList;
}

void SLL::display()
{
    Node *current = head;

    if (current == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Linked List: ";
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    SLL myList, myList2;
    myList2.insert_element(9);
    myList2.insert_element(6);
    myList2.insert_element(2);
    int choice, num, position;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Insert the element" << endl;
        cout << "2. Delete the element" << endl;
        cout << "3. Linear search" << endl;
        cout << "4. Reverse Linked List" << endl;
        cout << "5. Merge Linked List" << endl;
        cout << "6. Display" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number to insert at the beginning: ";
            cin >> num;
            myList.insert_element(num);
            break;
        case 2:
            myList.delete_element();
            break;
        case 3:
            cout << "Enter a number to search for: ";
            int num;
            cin >> num;
            cout <<"Entered number is at: ";
            cout << myList.lsearch(num) << endl;
            break;
        case 4:
            cout << "Reversed SLL"<<endl;
            myList.reverseNode();
            break;
        case 5:
            cout << "Merged SLL"<<endl;
            myList.mergeNode(myList2);
            break;
        case 6:
            myList.display();
            break;
        case 7:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 11);

    return 0;
}