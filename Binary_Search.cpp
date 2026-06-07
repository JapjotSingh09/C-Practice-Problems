#include <iostream>
#include <vector>
using namespace std;
int binarysearch(vector<int> arr, int target){
int st = 0;
int end = arr.size()-1;
while(st<=end){
    int mid = st + (end - st)/2;
    if(target>arr[mid]){
        st = mid + 1;
    }
    else if(target<arr[mid]){
        end = mid - 1;
    }
    else {
        return mid;
    }
}
return -1;
}
int main(){
vector<int>arr1 = {-1,0,3,4,5,9,12}; //ODD
int target1 = 12;
cout<<binarysearch(arr1, target1)<<endl;
vector<int>arr2 = {-1,0,3,5,9,12}; //EVEN
int target2 = 0;
cout<<binarysearch(arr2, target2)<<endl;
}