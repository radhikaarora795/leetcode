#include <iostream>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.size();
        vector<int> diff(n + 1, 0);

        for(auto &v : shifts) {

            int l = v[0];
            int r = v[1];
            int val = (v[2] == 1) ? 1 : -1;

            diff[l] += val;

            if(r + 1 < n)
                diff[r + 1] -= val;
        }

        int shift = 0;

        for(int i = 0; i < n; i++) {

            shift += diff[i];

            int pos = s[i] - 'a';

            pos = (pos + shift) % 26;

            if(pos < 0)
                pos += 26;

            s[i] = 'a' + pos;
        }

        return s;
    }
};

int main() {
    
    return 0;
}