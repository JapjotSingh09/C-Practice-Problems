#include<iostream>
#include<vector>
using namespace std;
int singleelement(vector<int> arr){
    int start = 0;
    int end = arr.size() - 1;
    if(arr.size() == 1){return arr[0];} // if there is only one element, return that element
while(start<=end){
    int mid = start + (end - start)/2;
    if(mid == 0 && arr[mid] != arr[1]){return arr[0];} // if mid is the first element and it is not equal to the second element, return the first element
    if(mid == arr.size() - 1 && arr[mid] != arr[arr.size() - 2]){return arr[arr.size() - 1];} // if mid is the last element and it is not equal to the second last element, return the last element
if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]){return arr[mid];} 
else if(mid % 2 == 0){ // even no of elements
    if(arr[mid] == arr[mid-1]){end = mid - 1;} // if mid is equal to its left neighbor, then the single element must be in the left half
    else {start = mid + 1;} // if mid is not equal to its left neighbor, then the single element must be in the right half
}
else{ // odd number of elements
    if(arr[mid] == arr[mid-1]){start = mid + 1;} // if mid is equal to its left neighbor, then the single element must be in the right half
    else {end = mid - 1;} // if mid is not equal to its left neighbor, then the single element must be in the left half
}
}
return -1;
}
int main(){
vector<int> arr1 = {1,1,2,3,3,4,4,8,8};
vector<int> arr2 = {3,3,7,7,10,11,11};
cout<<singleelement(arr1)<<" "<<singleelement(arr2);
}
