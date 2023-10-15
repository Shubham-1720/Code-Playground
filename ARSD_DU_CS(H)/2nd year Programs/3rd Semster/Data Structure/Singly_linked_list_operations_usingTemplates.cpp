#include <iostream>
using namespace std;

// defining the class
template <class T>
class Node
{
public:
    int data;
    Node<T> *next;
    Node<T>()
    {
        next = NULL;
    }
};

template <class T>
class SLL
{
    Node<T> *head;

public:
    SLL<T>()
    {
        head = NULL;
    }
    void insert_at_beg(T);
    void insert_at_end(T);
    void insert_at_loc(T, T);

    void delete_from_beg();
    void delete_from_end();
    void delete_from_loc(T);

    void display();
};

template <class T>
void SLL<T>::insert_at_beg(T num)
{
    Node<T> * newNode = new Node<T>();
    newNode -> data = num;
    newNode -> next = head;
    head = newNode;
}

template <class T>
void SLL<T>::insert_at_loc(T num, T position)
{
    Node<T> *newNode = new Node<T>();
    newNode->data = num;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node<T> *prev = head;
    for (int i = 1; i < position - 1 && prev != nullptr; i++) {
        prev = prev->next;
    }

    if (prev == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }

    newNode->next = prev->next;
    prev->next = newNode;
}

template <class T>
void SLL<T>::insert_at_end(T num)
{
    Node<T> *newNode = new Node<T>();
    newNode->data = num;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node<T> *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

template <class T>
void SLL<T>::delete_from_beg()
{
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node<T> *temp = head;
    head = head->next;
    delete temp;
}

template <class T>
void SLL<T>::delete_from_loc(T position)
{
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (position == 1) {
        delete_from_beg();
        return;
    }

    Node<T> *prev = head;
    Node<T> *curr = head->next;

    for (int i = 2; curr != nullptr && i < position; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
}

template <class T>
void SLL<T>::delete_from_end()
{
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete_from_beg();
        return;
    }

    Node<T> *prev = head;
    Node<T> *curr = head->next;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = nullptr;
    delete curr;
}

template <class T>
void SLL<T>::display()
{
    Node<T> *current = head;

    if (current == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Linked List: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main()
{
    SLL<int> myLinkedList;
    int choice, num, position;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at a particular location" << endl;
        cout << "3. Insert at the end" << endl;
        cout << "4. Delete from the beginning" << endl;
        cout << "5. Delete from a particular location" << endl;
        cout << "6. Delete from the end" << endl;
        cout << "7. Display" << endl;
        cout << "8. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to insert at the beginning: ";
                cin >> num;
                myLinkedList.insert_at_beg(num);
                break;
            case 2:
                cout << "Enter the number to insert: ";
                cin >> num;
                cout << "Enter the position to insert at: ";
                cin >> position;
                myLinkedList.insert_at_loc(num, position);
                break;
            case 3:
                cout << "Enter the number to insert at the end: ";
                cin >> num;
                myLinkedList.insert_at_end(num);
                break;
            case 4:
                myLinkedList.delete_from_beg();
                break;
            case 5:
                cout << "Enter the position to delete from: ";
                cin >> position;
                myLinkedList.delete_from_loc(position);
                break;
            case 6:
                myLinkedList.delete_from_end();
                break;
            case 7:
                cout << "Linked List: ";
                myLinkedList.display();
                break;
            case 8:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again..." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}