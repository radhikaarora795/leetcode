#include <iostream>
using namespace std;

vector<int> modifyArray(vector<int>& arr){
    int n=arr.size();
    if(n<=1){
        return arr;
    }
    int prev=arr[0];
    arr[0]=arr[1];

    for(int i=1;i<n-1;i++){
        int curr=arr[i];
        arr[i]=prev+arr[i+1];
        prev=curr;
    }
    arr[n-1]=prev;
    return arr;
}

int main() {
    vector<int> arr={2,3,4,5,6};
    vector<int> ans=modifyArray(arr);

    for(int i:arr){
        cout<<i<<" ";
    }
    
    return 0;
}