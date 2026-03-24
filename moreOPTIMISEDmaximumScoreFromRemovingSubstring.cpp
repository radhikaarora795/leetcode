#include <iostream>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string st;
        int score = 0;

        string first = "ab", second = "ba";
        int high = x, low = y;

        if (x < y) {
            swap(first, second);
            swap(high, low);
        }

        // First pass: remove higher scoring pattern
        for (char ch : s) {
            st += ch;
            int len = st.size(); 
            if (len >= 2 && st[len - 2] == first[0] && st[len - 1] == first[1]) {
                st.pop_back();
                st.pop_back();
                score += high;
            }
        }

        // Second pass: remove remaining lower scoring pattern
        string st2;
        for (char ch : st) {
            st2 += ch;
            int len = st2.size();
            if (len >= 2 && st2[len - 2] == second[0] && st2[len - 1] == second[1]) {
                st2.pop_back();
                st2.pop_back();
                score += low;
            }
        }

        return score;
    }
};

int main() {
    
    return 0;
}