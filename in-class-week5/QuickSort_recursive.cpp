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

void quickSort(int arr[], int left, int right) {
    if (left >= right) { // left == right is the base case
        return;
    }

    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++){
        if (arr[j] < pivot) {  // swap elements
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, ++i, right);

    quickSort(arr, left, i-1);
    quickSort(arr, i+1, right);

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

    auto begin = std::chrono::high_resolution_clock::now();
    
    quickSort(arr, 0, size-1);

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    
    cout << endl << "Sorted Array : " << endl;
    printArray(arr, size);
}
