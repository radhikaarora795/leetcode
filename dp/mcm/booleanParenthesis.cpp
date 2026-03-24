#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// learn 

class Solution{
public:
    unordered_map<string,int> dp;
    int mod=1003;
    int solve(string s, int i,int j,bool isTrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        string key=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
        if(dp.find(key) != dp.end()){
            return dp[key];
        }
        int ways=0;
        for(int k=i+1;k<=j-1;k+=2){
            int lt=solve(s,i,k-1,true);
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            int rf=solve(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(isTrue){
                    ways=(ways + ((lt*rt) % mod)% mod);
                }
                else{
                    ways=(ways + ((lt*rf) % mod + (lf*rt) % mod + (lf*rf) % mod)) % mod;
                }
            }
            else if(s[k]=='|'){
                if(isTrue){
                    ways= (ways + (lt*rt) % mod + (lt*rf) % mod + (lf*rt) % mod) % mod;
                }
                else{
                    ways= (ways + (lf*rf) % mod) % mod;
                }
            }
            else if(s[k]=='^'){
                if(isTrue){
                    ways= (ways + (lf*rt) % mod + (lt*rf) % mod) % mod;
                }
                else{
                    ways= (ways + (lt*rt) % mod + (lf*rf) % mod) % mod;
                }
            }
        }
        return dp[key]=ways % mod;
    }
    int cnttrue(string A) {
        dp.clear();     // important kyuki dp global hai Old values remain in dp
        return solve(A,0,A.size()-1,false);
    }
};


int main() {
    Solution s;
    cout<<s.cnttrue("T^T^F");
    
    return 0;
}