#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> Height = {1,8,6,2,5,4,8,3,7};
    int n = Height.size();
    int maxvolume = 0;
    int start = 0;
    int end = n-1;
    while(start<end){
        int width = end-start;
        int height = min(Height[start],Height[end]);
        int currvolume = height*width;
        maxvolume = max(maxvolume,currvolume);
        if(start<end){
            start++;
        }
        else{
            end--;
        }
    }
    cout<<maxvolume;
}