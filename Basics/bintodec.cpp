#include<iostream>
using namespace std;
int bintodec(int n){
    int sum = 0;
    int pow = 1; //2kipower0
    while(n>0){
        int rem = n%10;
        sum += rem*pow;
        n /= 10;
        pow *= 2;
    }
    return sum;
    }
int main(){
    int n = 101;
    cout<<bintodec(n);
}
