#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
if(root == NULL){
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  struct node *temp = new struct node(); // make new node with new key
  temp->key = key;
  if(node == nullptr){ 
    node = temp;
  }else{
    if( node->key >= key){ // add node for left branch
      node->left = insertNode(node->left, key);
    }else{// add node for right branch
      node->right = insertNode(node->right, key);
    }
  }
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
 if ( root == nullptr ){
    return root ;
  }
  else if(  root->key < key )  { // delete from right
    root->right = deleteNode(root->right , key);
  }
  else if( root->key > key  ){ // delete from left
    root->left = deleteNode(root->left , key);
  }else{
    if (root->left == nullptr && root->right == nullptr){
            root = nullptr;
        }
        else if (root->right == nullptr){
            root = root->left;
        }
        else if (root ->left == nullptr){
            root = root->right;
        }
        else{
            
            struct node* nd = root->left;
            while(nd->right != nullptr){
                nd = nd->right;
            }
            int data = nd ->key;
            root->key = data;
            root ->left = deleteNode(root->left , data);
    }
  } return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}