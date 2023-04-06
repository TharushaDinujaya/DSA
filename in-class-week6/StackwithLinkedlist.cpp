#include<bits/stdc++.h>

using namespace std;

struct Node{ // elements for store data in linked list
    int data;
    Node* prev;
};

class Stack{ // stack class - Push(), Pop(), isEmpty(), StackTop(), Display()
    private: 
        Node* top; // store the head of stack
    public:
        Stack(){
            top = NULL;
        }

    void Push(int n){ // push into Stack (integer)
        if(isEmpty()){ // if stack is empty
            top = new Node();
            top->data = n;
            top->prev = NULL;
        }
        Node* node;
        node = new Node();
        node->data = n;
        node->prev = top;
        top = node;
    }

    int Pop(){
        if(isEmpty()){ // nothing to pop
            cout << "Stack UnderFlow !";
            return 0;
        }
        int temp = top->data;
        top = top->prev; 
        return temp;
    }

    bool isEmpty(){
        return top == NULL;
    }

    int StackTop(){ // return the data in top node
        if(isEmpty()){ 
            cout << "Stack is Empty !";
            return 0;
        }
        return top->data;
    } 

    void Display(){ // print the data in linked list
        Node* temp = top;
        cout << "Items are : ";
        while(temp->prev != NULL){
            cout << temp->data << ", ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main(){
Stack stack;
    stack.Push(8);
    stack.Push(10);
    stack.Push(5);
    stack.Push(11);
    stack.Push(15);
    stack.Push(23);
    stack.Push(6);
    stack.Push(18);
    stack.Push(20);
    stack.Push(17);
    stack.Display();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Display();
    stack.Push(4);
    stack.Push(30);
    stack.Push(3);
    stack.Push(1);
    stack.Display();
}