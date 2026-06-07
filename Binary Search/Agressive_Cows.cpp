// Assign C cows to N stalls such that min distance between them
// is largest possible
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isvalid(vector<int> arr, int n, int c, int mindistance){
    int cow = 1, lastcowposition = arr[0];
    for(int i=0; i<n;i++){
        if((arr[i]-lastcowposition)>=mindistance){cow++; lastcowposition=arr[i];}
    }
    if (c>=cow) return true;
    else return false;
}
int main(){
    vector<int> arr = {1,2,8,4,9};
    int n = arr.size(), c = 3;
    sort(arr.begin(),arr.end());
    int start = 1, end = arr[n-1]-arr[0];
    int ans = 0;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(isvalid(arr, n, c, mid)){
            ans = mid;
            start = mid+1;
        }
        else{end = mid - 1;}
    }
    cout<<ans;
}
