#include <iostream>
using namespace std;

void leftRotate(vector<int>& arr){
    int n=arr.size();
    int save=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=save;
    for(int i:arr){
        cout<<i<<" ";
    }
}

void rightRotate(vector<int>& arr){
    int n=arr.size();
    int save=arr[n-1];
    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=save;
    for(int i:arr){
        cout<<i<<" ";
    }
}

int main() {
    vector<int> arr={1,2,3,4,5};
    rightRotate(arr);
    
    return 0;
}