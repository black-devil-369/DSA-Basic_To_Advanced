#include<bits/stdc++.h>
int main(){
  int b;
  // Creating an Array by using an array
  int arr[] = {6,3,2,5,9,1};
  int n = sizeof(arr)/sizeof(int);
  int start = 0;
  int last = n-1;
  while(start<=last){
    int temp = arr[start];
    arr[start] = arr[last];
    arr[last] = temp;
    start++;
    last--;
  }
  for(int i =0;i<n;i++){
    std::cout<<arr[i]<<" ";
  }
  std::cout<<" "<<std::endl;
}