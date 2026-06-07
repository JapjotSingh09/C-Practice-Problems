#include<iostream>
using namespace std;
int main(){
    int arr[] = {4,1,2,3,5};
    int n = sizeof(arr)/4;
    for(int i=0;i<n;i++){
        int smallestIdx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallestIdx]){ // For descending order, change < to >
                smallestIdx = j;
            }
        }
        swap(arr[i],arr[smallestIdx]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}