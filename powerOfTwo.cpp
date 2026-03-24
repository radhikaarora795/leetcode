#include <iostream>
using namespace std;

/*class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool isPowerOf2=false;
        if(n<=0){
            return false;
        }
        if((n & (n-1)) == 0){
            isPowerOf2=true;
        }
        return isPowerOf2;
    }
};*/


// better time
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        return ((n & (n-1)) == 0);
    }
};

/*
A power of two has exactly ONE 1 bit in binary.
When you subtract 1 from a positive integer in binary:
The lowest-position 1 becomes 0
All bits to the right of that position become 1
Bits to the left stay the same
The AND operator (&) keeps a 1 only where both bits are 1.
Therefore, when we compute n & (n - 1), the result is zero if and only if
the number originally had exactly one set bit.
*/

int main() {
    Solution s;
    cout<<s.isPowerOfTwo(128);
    
    return 0;
}