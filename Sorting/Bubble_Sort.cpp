#include<iostream>
using namespace std;
int main(){
    int arr[] = {4,1,2,3,5};
    int n = sizeof(arr)/4;
    for(int i=0;i<n-1;i++){
        bool isSwap = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){swap(arr[j],arr[j+1]); isSwap = true;} // For descending order, change > to <
        }
        if(!isSwap){return;} // If no swapping occurred, array is sorted
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}