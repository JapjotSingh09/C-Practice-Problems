// There are N books, each ith book has A[i] number of pages.
// You have to allocate books to M number of students so that the,
// maximum number of pages allocated to a student is minimum.
// Note: Each book should be allocated to a student.
// Note: Each student has to be allocated at least one book.
// Note: Allotment should be in contiguous order.
// Calculate and return the minimum number of pages.
// Return -1 if a valid assignment is not possible.
#include<iostream>
#include<vector>
using namespace std;
int isvalid(vector<int> &arr, int n, int m , int mid){
int stu = 1, pages = 0;
for(int i = 0; i<n; i++){
    if(arr[i]>mid){return false;}
    else if((pages + arr[i]) > mid){
        stu ++;
        pages = arr[i];
    }
    else{
        pages += arr[i];
    }
}
if(stu>m){return false;}
else {return true;}
}
int allocatebooks(vector<int> &arr, int n, int m){
int sum = 0;
for(int i=0; i<n; i++){
    sum += arr[i];
}
int st = 0, end = sum; // Range Of Possible Answers.
int ans = 0;
while(st<=end){
    int mid = st + (end - st)/2;
    if (isvalid(arr, n , m , mid)){
        ans = mid;  
        end = mid - 1;}
    else {st = mid + 1;}
}
return ans;
}
int main(){
    vector<int> arr = {2,1,3,4};
    int n = 4, m = 2;
    cout<<allocatebooks(arr , 4, 2);
}