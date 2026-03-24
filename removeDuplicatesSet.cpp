#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> removeDuplicates(vector<int>& arr){
    unordered_set<int> set;
    vector<int> result;
    for(int i:arr){
        set.insert(i);
    }
    for(int i:arr){
        auto it=set.find(i);
        if(it != set.end()){
            result.push_back(i);
            set.erase(i);
        }
    }
    return result;
}

vector<int> removeDuplicates2(vector<int>& arr){
    sort(arr.begin(),arr.end());
    auto it=unique(arr.begin(),arr.end());
    arr.erase(it,arr.end());
    return arr;
}

vector<int> moveZeroes(vector<int>& arr){
    int j=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}

int main() {
    vector<int> arr={0,0,1,2,0,0,3};
    // vector<int> result=removeDuplicates(arr);
    vector<int> result=moveZeroes(arr);

    for(int i:result){
        cout<<i<<" ";
    }
    
    return 0;
}