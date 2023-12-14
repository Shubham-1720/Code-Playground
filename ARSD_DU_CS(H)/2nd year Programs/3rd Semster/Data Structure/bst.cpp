#include <iostream>
using namespace std;

class Node
{
public:
int data;
Node * left;
Node * right;
Node(){
  left = right  =nullptr;
}

};

class BST
{
public:
Node * root;
BST(){
  root = nullptr;
}
Node * create();
void preorder(Node *root){
  if(root == nullptr)
    return;
  else{
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
  }
}
 void inorder(Node *root){
   if(root == nullptr)
     return;
   else{
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
   }
   }

void postorder(Node *root){
  if(root == nullptr)
     return;
  else{
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
  }
}
Node * search(Node *root, int num){
  if((root==nullptr) || root->data == num)
    return root;
  if(num < root->data){
    return search(root->left, num);
  }
  else{
      return search(root->right, num);
    }
  
}

Node * findMin(Node * root){
  while(root->left != nullptr){
    root = root->left;
  }
  return root;
}

Node * deleteNode(Node *root,int num){
  if(root == nullptr){
    cout<<"Tree is empty"<<endl;
    return root;
  }
  if(num < root->data){
    root->left = deleteNode(root->left, num);
  }
  else if(num > root->data){
    root->right = deleteNode(root->right, num);
  }
  else{
    //Node with only one or two child
    if (root->left == nullptr) {
        Node* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == nullptr) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    //Node with two child
    Node* temp = findMin(root->right); // Find the in-order successor
    root->data = temp->data; // Copy the in-order successor's value to this node
    root->right = deleteNode(root->right, temp->data); // Delete the in-order successor
    }
  return root;
  }


};

Node * BST::create()
{
  int value;
  Node * newNode = new Node();
  cout<<"Enter the value or enter -1 for nothing to add"<<endl;
  cin>>value;
  if(value== -1)
    return nullptr;

  newNode->data = value;
  cout<<"Enter left child of element"<<value<<endl;
  newNode->left = create();
  cout<<"Enter right child of element"<<value<<endl;
  newNode->right = create();
  return newNode;
}


int main() {
  BST mytree;
  mytree.root = mytree.create();
  mytree.preorder(mytree.root);
  mytree.inorder(mytree.root);
  mytree.postorder(mytree.root);
  cout<<"Data is at"<<mytree.search(mytree.root, 4)<<endl;
  mytree.deleteNode(mytree.root, 4); 
  mytree.preorder(mytree.root);
}