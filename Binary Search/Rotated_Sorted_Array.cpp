#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> arr, int target){
int start = 0;
int end = arr.size() - 1;
while(start <= end){ 
int mid = start + (end - start) / 2; // to avoid overflow
if (arr[mid] == target) return mid; // target found

if(arr[start] < arr[mid]){ // left part is sorted
    if(target >= arr[start] && target < arr[mid]){ // target is in left part
    end = mid - 1;
    }
    else start = mid + 1; // target is in right part
}
else{ // right part is sorted
    if(target >= arr[mid] && target <= arr[end]){ // target is in right part
    start = mid + 1;
    }
    else end = mid - 1; // target is in left part

}
}
return -1;
}
int main(){
vector<int>arr = {6,7,0,1,2,3,4,5};
int target = 0;
cout << search(arr, target) << endl; 
}
