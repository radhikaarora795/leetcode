#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m, 0);

    int len = 0; // length of previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int firstOccurrence(string text, string pat) {
    int n = text.size();
    int m = pat.size();

    if (m == 0) return 0;

    vector<int> lps = computeLPS(pat);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j; // first occurrence index
        } 
        else if (i < n && text[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return -1;
}

int main() {
    string text = "sadbutsad";
    string pattern = "ababd";

    cout << firstOccurrence(text, pattern);
    return 0;
}
