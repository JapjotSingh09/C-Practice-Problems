#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string s = " Hello World";
    string ans = "";
    reverse(s.begin(), s.end());
    int n = s.length();
    for(int i=0;i<n;i++){
        string word = "";
    while(i<n && s[i]!=' '){
        word += s[i];
        i++;
    }
    if(word.length()>0){
    reverse(word.begin(), word.end());
    if(ans.length()!=0){
    ans += " ";
    }
    ans += word;
    }

}
cout<<ans;
}