#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"Write A Number: ";
    cin>>x;
    int sum=0;
    while(x!=0){
        int ld = x%10;
        x /=10;
        if(ld%2!=0)
        continue;
        
        sum+=ld;
        
    }
    cout<<sum;
}
