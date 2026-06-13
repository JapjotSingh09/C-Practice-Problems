#include <iostream>
#include <vector>
using namespace std;
int main() {
    int arr1[] = {1, 3, 5, 0, 0, 0};
    int arr2[] = {2, 4, 6};
    int m = 3, n = 3, Idx = m+n-1;
    int i = m - 1, j = n - 1;
    while(i>=0 && j>=0){
        if(arr1[i]>=arr2[j]){
            arr1[Idx--] = arr1[i--];
        }
        else{arr1[Idx--] = arr2[j--];}
    }
    while(j>=0){
        arr1[Idx--] = arr2[j--]; // If arr1 is exhausted, copy remaining elements of arr2.
    }
    for(int i=0;i<m+n;i++){
        cout<<arr1[i]<<" ";
    }
}