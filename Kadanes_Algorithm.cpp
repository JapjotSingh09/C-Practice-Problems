#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,-2,3,4,5};
    int n = sizeof(arr)/4;
    int maxsum = INT_MIN;
    int currsum = 0;
    for(int i=0;i<n;i++){
        currsum += arr[i];
        maxsum = max(currsum,maxsum);
        if(currsum<0){
            currsum = 0;
        }
    }
  cout<<maxsum;
}
