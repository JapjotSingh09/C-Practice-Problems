#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"Write A Number: ";
    cin>>x;
    int o = x;
    int r = 0;
    while(x!=0){
        int ld = x%10;
        x /=10;
       r = (r*10)+ld; 
    }
    cout<<r;
    cout<<endl<<(o+r);
}