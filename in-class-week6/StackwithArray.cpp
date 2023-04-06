#include <bits/stdc++.h>

using namespace std;

class Stack{
    private: 
        int* arr; // array
        int top; // to store the head of stack (head index in array)
    public:
        Stack(int  n){ // initializing the stack (create array with size of n)
            arr = new int[n];
            top = -1;
        }

        void Push(int n){ // add data into the Stack
            if(isFull()){
                return;
            }
            top++;
            arr[top] = n;
        }
        
        int Pop(){ // remove data from the Stack(remove from the top)
            if(isEmpty())
                return 0;
            int temp = arr[top];
            top--;
            return temp;
            
        }

        bool isEmpty(){ // return true is stack is empty
            return top == -1;  
        }
        
        bool isFull(){ // return true is stack is full
            return top == 10-1;
        }
        
        int StackTop(){ // return the data of top element in stack
            return arr[top];
        }

        void Display(){ // display the data in stack
            cout<<" Items are : ";
            for(int i = top; i >= 0 ; i--)
                cout << arr[i] << ", ";
            cout << endl;
}
};
int main(){
    cout << "Enter the Size of Array : ";
    int n;
    cin >> n;
    Stack stack(n);
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
