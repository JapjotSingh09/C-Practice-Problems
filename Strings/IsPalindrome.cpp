#include<iostream>
using namespace std;
bool IsAlphaNumeric(char ch){
if(tolower(ch)>='0' && tolower(ch)<='9'){return true;}
else if(tolower(ch)>='a' && tolower(ch)<='z'){return true;}
else {return false;};
}
bool IsPalindrome(string str){
    int st = 0, end = str.length()-1;
    while(st<end){
        if(!IsAlphaNumeric(str[st])){st++; continue;}
        if(!IsAlphaNumeric(str[end])){end--; continue;}
        if(tolower(str[st])==tolower(str[end])){st++; end--;}
        else{ return false;}
    }
    return true;
}
int main(){
    string str = "Ac3?e3c$a";
    cout<<IsPalindrome(str);
}