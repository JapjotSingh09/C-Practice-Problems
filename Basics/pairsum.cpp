#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,7,11,15};
    int target = 9;
    int size = sizeof(arr)/4;
    for(int i=0;i<size;i++){
        int sum;
        for(int j=i+1;j<size;j++){
            sum = arr[i] + arr[j];
            if (sum == target){
                cout<<arr[i]<<" "<<arr[j];
            }
            }
        }
    }
