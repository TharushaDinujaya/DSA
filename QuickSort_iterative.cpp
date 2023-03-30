#include <cstdlib>
#include <chrono>
#include<iostream>

using namespace std;

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "  ";
    }
}

void swap(int arr[], int n, int m){
    int temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
}

void quickSort(int arr[], int len) {

    int stack[len];
    int top{-1};

    stack[++top] = 0;
    stack[++top] = len - 1;

    int left, right, index;
    for ( ; top >= 0; ){
        right = stack[top--];
        left = stack[top--];

        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++)
        {
            if (arr[j] < pivot) {
                i++;
                swap(arr, j, i);
            }
        }
        i++;
        swap(arr, i, right);

        index = i;

        if (index - 1 > left) {
            stack[++top] = left;
            stack[++top] = index - 1;
        }

        if (index + 1 < right) {
            stack[++top] = index + 1;
            stack[++top] = right;
        }
    }
}


int main() {
    cout << "Enter the size of array : ";
    int size;
    cin >> size;
    int arr[size];
    cout << "Size is : " << size << endl;
    for(int i = 0; i < size; i++){
        arr[i] = rand(); // check for average case. For worst case use arr[i] = size - i;
    }
    cout << "Started Array : ";
    printArray(arr, size);

    auto begin = chrono::high_resolution_clock::now();
    
    quickSort(arr, size);

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    cout << endl;
    
    cout << endl << "Sorted Array : " << endl;
    printArray(arr, size);
}


