#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    string st;
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
        int length=st.size();
        if(!st.empty() && length>1){
            if(st[length-2]==str[0] && st[length-1]==str[1]){
                st.pop_back();
                st.pop_back();
                return true;
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
            st+=ch;
            if(compare(pref1)){
                score+=maxScore;
            }
        }
        string st2=st;
        st.clear();
        for(char ch:st2){
            st+=ch;
            if(compare(pref2)){
                score+=minScore;
            }
        }

        return score;

    }
};

int main() {
    Solution s;
    cout<<s.maximumGain("aabbaaxybbaabb",5,4)<<endl;
    //s.printStack();
    
    return 0;
}