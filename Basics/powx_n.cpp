#include<iostream>
using namespace std;
double mypower(long int n, int x){
    double ans = 1;
    if(n==0) return 1;
    if (x==1) return 1;
    if(x==0) return 0;
    if(x==-1 && n%2==0) return 1;
    if(x==-1 && n%2!=0) return -1;
    if (n<0){
        x = x/2;
        n = -n;
    }
    while(n>0){
        if(n%2==1){
            ans = ans*x;
        }
        x = x*x;
        n = n/2;
    }
    return ans;
}
int main(){
    int n,x;
    cout<<"Enter the value of base";
    cin>>x;
    cout<<"Enter The Value of exponent";
    cin>>n;
    cout<<"The answer is "<<mypower(n,x);

}