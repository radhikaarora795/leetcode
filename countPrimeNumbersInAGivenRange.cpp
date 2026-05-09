#include <iostream>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int L, int R) {
        // code here
        vector<bool> prime(R+1,true);
        vector<int> ans;
        
        if(R>=0) prime[0]=false;
        if(R>=1) prime[1]=false;
        
        for(int i=2;i*i<=R;i++){
            if(prime[i]){
                for(int j=i*i;j<=R;j+=i){
                    prime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=max(2,L);i<=R;i++){
            if(prime[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}

