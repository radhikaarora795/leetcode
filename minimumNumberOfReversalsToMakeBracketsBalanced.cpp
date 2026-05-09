#include <iostream>
using namespace std;

// gfg count the reversals

class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        
        int n=s.size();
        if(n%2 != 0){
            return -1;
        }
        
        stack<char> st;
        for(char c:s){
            if(c=='{'){
                st.push(c);
            }
            else{
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        int open=0;
        int closed=0;
    
        while(!st.empty()){
            if(st.top()=='{'){
                open++;
            }
            else{
                closed++;
            }
            st.pop();
        }
        return (open+1)/2 + (closed+1)/2;
    }
};

int main() {
    
    return 0;
}