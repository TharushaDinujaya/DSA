#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* prev;
};

class Stack{
    private: 
        Node* top;
    public:
        Stack(){
            top = NULL;
        }

    void Push(int n){
        if(isEmpty()){
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
        if(isEmpty()){
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

    int StackTop(){
        if(isEmpty()){
            cout << "Stack is Empty !";
            return 0;
        }
        return top->data;
    } 

    void Display(){
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