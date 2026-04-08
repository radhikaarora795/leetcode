#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

class DisjointSet{
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unionBySize(int u, int v){
        int uParu=find(u);
        int uParv=find(v);
        if(uParu == uParv){
            return;
        }
        if(size[uParu] < size[uParv]){
            parent[uParu]=uParv;
            size[uParv]+=size[uParu];
        }
        else{
            parent[uParv]=uParu;
            size[uParu]+=size[uParv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> map;
        int n=accounts.size();
        DisjointSet d(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(map.find(email) == map.end()){       // nhi mila
                    map[email]=i;
                }
                else{
                    d.unionBySize(i,map[email]);
                }
            }
        }
        unordered_map<int,set<string>> merged;
        for(auto &i : map){
            string email=i.first;
            int parent=d.find(i.second);
            merged[parent].insert(email);
        }
        vector<vector<string>> result;
        for(auto &i : merged){
            int index=i.first;
            vector<string> temp;
            temp.push_back(accounts[index][0]);
            for(auto &email : i.second){
                temp.push_back(email);
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
    
    return 0;
}