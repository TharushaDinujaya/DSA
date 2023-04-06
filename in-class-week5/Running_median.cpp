#include<iostream>
#include<iomanip>

using namespace std;

void printArray(int arr[], int left, int right){
    cout << "[ ";
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]";
    
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

void findMedian(int arr[], int right, int len){
    if(len == right){
        return;
    }
    quickSort(arr, 0, right);
    if((right-0)%2 == 1){
        int mid = right/2;
        float value = arr[mid] + arr[mid + 1];
        printArray(arr, 0, right);
        cout << "\t" << setprecision(1) << fixed << (value/2) << endl;
    }
    else{
        int mid = right/2;
        printArray(arr, 0, right);
        cout << "\t" << setprecision(1) << fixed << static_cast<float>(arr[mid]) << endl;
    }
    right++;
    return findMedian(arr, right, len);
}

int main(){
    int arr[4]{7,3,5,2};
    findMedian(arr, 0, 4);

}