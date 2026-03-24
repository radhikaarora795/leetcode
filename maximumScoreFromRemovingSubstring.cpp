#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    stack<char> st;
    int score=0;
public:
    /*void printStack(){
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }*/

    bool compare(string str){
        char ch1;
        if(!st.empty()){
            ch1=st.top();
            st.pop();
            if(ch1==str[1] && !st.empty() && st.top()==str[0]){
                st.pop();
                return true;
            }
            else{
                st.push(ch1);
            }
        }
        return false;
    }

    int maximumGain(string s, int x, int y) {
        string pref1="ab";
        string pref2="ba";
        int maxScore=x;
        int minScore=y;
        if(x<y){
            pref1="ba";
            pref2="ab";
            maxScore=y;
            minScore=x;
        }
        for(char ch:s){
            st.push(ch);
            if(compare(pref1)){
                score+=maxScore;
            }
        }

        string str2;
        while(!st.empty()){
            str2+=st.top();
            st.pop();
        }
        reverse(str2.begin(),str2.end());
        
        for(char ch:str2){
            st.push(ch);
            if(compare(pref2)){
                score+=minScore;
            }
        }

        return score;

    }
};

int main() {
    Solution s;
    cout<<s.maximumGain("cdbcbbaaabab",4,5)<<endl;
    //s.printStack();
    
    return 0;
}