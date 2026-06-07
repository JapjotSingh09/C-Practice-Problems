#include<iostream>
using namespace std;
int main(){
    int a[] = {1,2,3,2,1};
    int n = sizeof(a)/4;
   int i =0;
   int j=n-1-i;
   while(i<n/2){
    if(a[i] == a[j])
    i++;
    j--;
   }
   if(a[i]==a[j]) cout<<"Yes";
   else cout<<"No";
}
