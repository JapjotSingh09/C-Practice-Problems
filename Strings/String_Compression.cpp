#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
 vector<char> chars = {'a','a','b','b','c','c','c'};
int i = 0, n = chars.size();
int idx = 0;
while(i<n){
    char character = chars[i];
    int count = 0;
    while(i<n && chars[i]==character){
        count ++;
        i++;
    }
    if(count == 1){
        chars[idx++] = character;
    }
    if(count!=1){
        chars[idx++] = character;
        string str = to_string(count);
        for(char dig : str){
            chars[idx++] = dig;
        }
    }
}
for(int i=0;i<idx;i++){
    cout<<chars[i]<<" ";
}
}