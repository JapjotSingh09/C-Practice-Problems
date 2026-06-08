/* Rule yaad rakho:
0 → low ke sath swap, low++, mid++
1 → mid++
2 → high ke sath swap, high-- (mid same rahega) */
#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,0,1,0,2,1};
    int n = 6;
    int mid=0, low=0, high=n-1;
    while(mid<=high){
        if(arr[mid]==0){swap(arr[low], arr[mid]);mid++; low++;}
        if(arr[mid]==1){mid++;}
        if(arr[mid]==2){swap(arr[mid], arr[high]);high--;}
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}