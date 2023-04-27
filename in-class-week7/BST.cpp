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
 if ( root == NULL ){
    return root ;
  }else if(root->key == key){
    if (root->left == NULL && root->right == NULL){
            root = NULL;
        }
        else if (root->right == NULL){ // if right is null then left is assign to root
            root = root->left;
        }
        else if (root ->left == NULL){ // if left is null then right is assing to root
            root = root->right;
        }
        else{ // if root has two branches (left and right then highest value in left branch is assign to root)
            struct node* nd = root->left; // select left branch
            while(nd->right != NULL){ // highest value is in most right branch
                nd = nd->right;
            }
            root->key = nd->key; // change root key with left most right node's key
            root ->left = deleteNode(root->left , nd->key);
    }
  }
  else if(  root->key < key )  { // delete from right
    root->right = deleteNode(root->right , key);
  }
  else if( root->key > key  ){ // delete from left
    root->left = deleteNode(root->left , key);
  }
  return root;
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
