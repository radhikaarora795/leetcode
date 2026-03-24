#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < s.length(); ++right) {
        char currentChar = s[right];

        // count != 0 means currentChar is in lastIndex map
        // if character was seen and is inside the current window
        if (lastIndex.count(currentChar) && lastIndex[currentChar] >= left) {
            // move left pointer right after where we last saw currentChar
            left++;
            //left = lastIndex[currentChar] + 1;
        }
        lastIndex[currentChar] = right;
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
    }
};

int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("pwwkew");

    return 0;
}
