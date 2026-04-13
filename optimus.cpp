#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string revString(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
    return s;
}

// remove duplicate while maintaining order
string removeDuplicate(string s){
    unordered_set<char> set;
    string ans="";
    for(char c:s){
        if(set.find(c) == set.end()){
            ans+=c;
            set.insert(c);
        }
    }
    return ans;
}

/*
Circular Array Sum: Given N (length) and M (sum limit), fill a circular array 
starting from index 1 with integers 1, 2, 3... without exceeding M; 
fill remaining with the leftover sum or zero.

eg N=5 M=7
[1 2 3]
sum=6
4 nhi aayega
7-6=1 aayega
[1 2 3 1 0]
*/

vector<int> circularArraySum(int N, int M){
    vector<int> arr(N,0);
    int currSum=0;
    int num=1;

    for(int i=0;i<N;i++){
        if(currSum + num <= M){
            currSum+=num;
            arr[i]=num;
            num++;
        }
        else{
            arr[i]=M-currSum;
            break;
        }
    }
    return arr;
}

/*
Minimal Divisibility Pair: Find smallest non-negative x and y such that 
(b + y) is divisible by (a + x) and (x + y) is minimized.
*/

int minDivisibilityPair(int a, int b){
    int ans=INT_MAX;
    for(int x=0;x<=1000;x++){
        int d=a+x;
        int y=(d-(b%d))%d;
        ans=min(ans,x+y);
    }
    return ans;
}

int main() {
    // cout<<removeDuplicate("abaacaa");
    // int N = 5, M = 7;
    // vector<int> result = circularArraySum(N, M);

    // for(int x : result)
    //     cout << x << " ";

    cout<<minDivisibilityPair(8,11);
    
    return 0;
}