#include <iostream>
#include <string>
#include <vector>
using namespace std;

void lexicographicalOwn(int n){
    vector<string> v;
    for(int i=1;i<=n;i++){
        v.push_back(to_string(i));
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<" ";
    }
}

void dfs(int curr,int n){
    if(curr>n){
        return;
    }
    cout<<curr<<" ";

    for(int i=0;i<=9;i++){
        int next=curr*10+i;
        if(next>n){
            return;
        }
        dfs(next,n);
    }
}

void lexicographical(int n){
    for(int i=1;i<=9;i++){
        if(i>n){
            break;
        }
        dfs(i,n);
    }
}

int main() {
    lexicographical(13);

    return 0;
}