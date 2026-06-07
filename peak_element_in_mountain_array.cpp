#include<iostream>
#include<vector>
using namespace std;
int findpeak(vector<int> arr){
int start = 1; // we start from 1 because the first element cannot be a peak
int end = arr.size() - 2;// we end at size - 2 because the last element cannot be a peak
while(start<=end){
    int mid = start + (end - start)/2;
    if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){return arr[mid];} // if mid is greater than both its neighbors, it is a peak
    else if(arr[mid] < arr[mid + 1]){start = mid + 1;} // if mid is less than its right neighbor, then the peak must be in the right half
    else{end = mid - 1;} // if mid is less than its left neighbor, then the peak must be in the left half
}
return -1;
}
int main(){
    vector<int> arr = {0,3,8,9,1,2};
    cout<<findpeak(arr);
}