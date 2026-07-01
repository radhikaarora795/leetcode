#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cyclicSort(vector<int>& arr){
    int i=0;
    int n=arr.size();

    while(i<n){
        int correctIndex=arr[i]-1;
        if(arr[i] != arr[correctIndex]){
            swap(arr[i],arr[correctIndex]);
        }
        else{
            i++;
        }
    }
}

/*
If the array contains 0, negative numbers, or values greater than n
if (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[correctIndex]) {
    swap(arr[i], arr[correctIndex]);
}
*/

int main() {
    vector<int> arr={3, 1, 5, 4, 2};
    cyclicSort(arr);
    for(int x:arr){
        cout<<x<<" ";
    }
    
    return 0;
}