#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreater(vector<int> &arr){
    stack<int> s;
    int n=arr.size();
    vector<int> ans(n,0);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    for(int i:ans){
        cout<<i<<" ";
    }
}

int main() {
    vector<int> arr={6,8,0,1,3};
    nextGreater(arr);

    return 0;
}