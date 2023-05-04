#include <bits/stdc++.h>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left = root*2 + 1; // left branch index
   int right = root*2 + 2; // right branch index
   int highest;

   if( right < n && arr[right] > arr[root]){
      highest = right;
   }else{
      highest = root;
   }

   if( left < n && arr[left] > arr[highest]){
      highest = left;
   }

   if(highest != root){
      // swapping two elements arr[root] and arr[highest]
      int temp = arr[root];
      arr[root] = arr[highest];
      arr[highest] = temp;

      heapify(arr, n, highest);
   }   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
   {
      heapify(arr, n, i);
   }

   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--)
   {
      // swapping two elements - arr[0] and arr[i] 
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;

      heapify(arr, i, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   vector<int> arr ={};
   string input_text;
   cout<<"Input array"<<endl;
   getline(cin, input_text); // read input as a string

   int temp;
   istringstream input_stream(input_text); // create input stream to read data in string
   while(input_stream >> temp){
      arr.push_back(temp); // add data to the vector
   }
   int n = arr.size(); // get the array size

   int heap_arr[n];
   for(int i = 0; i < n; i++){
      heap_arr[i] = arr[i]; // copy vector to array
   }
   heapSort(heap_arr, n); // sort using heapsort
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n); // print sorted array
}