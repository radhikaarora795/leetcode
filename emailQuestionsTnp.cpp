#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

// reverse string without built in: two pointer approach

string reverse(string str){
    int i=0;
    int j=str.size()-1;

    while(i<j){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
    return str;
}

bool isPallindrome(string str){
    int i=0;
    int j=str.length()-1;

    while(i<j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

/* method 1: Use a boolean array (or unordered_set) to track if a character has appeared.
Traverse the string once, keep only first occurrences.*/
string removeDuplicates(string str){
    bool seen[256]={false};
    string result="";
    for(char ch:str){
        if(!seen[ch]){
            result+=ch;
            seen[ch]=true;
        }
    }
    return result;
}

/* method 2: In-Place Removal Using Two Pointers
Keep a write pointer to overwrite duplicates.
Use a seen array to track first occurrences.*/
string removeDuplicates2(string str){
    bool seen[256]={false};
    int write=0;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(!seen[str[i]]){
            str[write]=ch;
            write++;
            seen[ch]=true;
        }
    }
    str.resize(write);
    return str;
    /*
    if without resize return str.substr(0, write);
    */
}

/*
Q: first non repeating character who stands alone
The first character that appears exactly once
Input: "swiss"
Output: 'w'
Explanation:
's' appears 3 times → repeating
'w' appears 1 time → first non-repeating character

We do two passes: one to count frequencies, one to find the first character with frequency 1. 
This is O(n) time and O(1) extra space for ASCII
*/

char firstNonRepeatingCharacter(string str){

    /*
    Alternative: Using unordered_map (for Unicode / large character sets)
    #include <unordered_map>
    unordered_map<char,int> freq;
    for(char ch : s) freq[ch]++;
    */
    int count[256]={0};
    for(char ch:str){
        count[ch]++;
    }
    for(char ch:str){
        if(count[ch] == 1){
            return ch;
        }
    }
    return '\0';    // Return null char if no non-repeating character
}

/* count how many times each character appears:
can use both array and unordered map
*/

void countCharacters(string str){
    unordered_map<char,int> count;
    for(char ch:str){
        count[ch]++;
    }
    for(auto i:count){
        cout<<i.first<<": "<<i.second<<endl;
    }
}

// reverse array in place

void reverseArray(vector<int> &arr){
    int left=0;
    int right=arr.size()-1;
    while(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
}

// second largest element in array

// distinct version: duplicates not allowed
int secondLargestElement(vector<int> &arr){
    if(arr.size()<2){
        return -1;
    }
    
    int largest=arr[0];
    int secondLargest=-1;
    bool found=false;
    
    for(int i=1;i<arr.size();i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
            found=true;
        }
        else if(arr[i]<largest){
            if(!found || arr[i]>secondLargest){
                secondLargest=arr[i];
                found=true;
            }
        }
    }
    return found ? secondLargest:-1;
}

// non distinct version: duplicates allowed
int secondLargestElement2(vector<int> &arr){
    if(arr.size()<2){
        return -1;
    }
    
    int largest,secondLargest;

    if(arr[0]>=arr[1]){
        largest=arr[0];
        secondLargest=arr[1];
    }
    else{
        largest=arr[1];
        secondLargest=arr[0];
    }
    
    for(int i=2;i<arr.size();i++){
        if(arr[i]>=largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondLargest){
            secondLargest=arr[i];
        }
    }
    return secondLargest;
}

vector<int> twoSum(vector<int>& nums,int target){
    vector<int> result;
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        int temp=target-nums[i];
        auto it=map.find(temp);
        if(it != map.end()){
            result.push_back(map[temp]);
            result.push_back(i);
            break;;
        }
        map[nums[i]]=i;
    }
    return result;
}

/*
An Armstrong number (also called a narcissistic number) is a number that is equal to the sum of its own digits 
each raised to the power of the number of digits.
Example: 
153=1^3+2^3+3^3=153 
*/
bool isArmstrong(int n){
    int result=0;
    int temp=n;
    int count=0;
    while(temp>0){
        count++;
        temp=temp/10;
    }
    temp=n;
    while(temp>0){
        int x=temp%10;
        result+=pow(x,count);
        temp=temp/10;
    }
    return result==n;
}

string removeSpaces(string str){
    string result;
    for(char ch:str){
        if(ch != ' '){
            result+=ch;
        }
    }
    return result;
}

void swap(int a,int b){
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<a<<" "<<b;
}

void swap2(int a,int b){
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;  // Divide first to avoid overflow
}

// if string use num=stoi(str)
int binaryToDecimal(int binary){
    int result=0;
    int base=1;
    while(binary>0){
        int n=binary%10;
        result+=n*base;
        base*=2;
        binary=binary/10;
    }
    return result;
}

int lengthOfLongestSubstring(string s){
    int left=0;
    int maxLength=0;
    unordered_set<char> set;
    
    for(int right=0;right<s.size();right++){
        while(set.find(s[right]) != set.end()){
            set.erase(s[left]);
            left++;
        }
        set.insert(s[right]);
        maxLength=max(maxLength,right-left+1);
    }
    return maxLength;
}

int maxSumSubarray(vector<int>& arr, int k){
    int n=arr.size();
    int maxSum=0;
    int windowSum=0;

    for(int i=0;i<k;i++){
        windowSum+=arr[i];
    }
    maxSum=windowSum;

    for(int i=k;i<n;i++){
        windowSum+=arr[i]-arr[i-k];
        maxSum=max(maxSum,windowSum);
    }
    return maxSum;
}

int countWords(string s){
    int count=0;
    bool inWord=false;

    for(char ch:s){
        if(ch == ' '){
            inWord=false;
        }
        else{
            if(!inWord){
                count++;
                inWord=true;
            }
        }
    }
    return count;
}

int majorityElement(vector<int>& nums){
    int candidate=nums[0];
    int count=0;

    for(int n:nums){
        if(count==0){
            candidate=n;
        }
        if(n == candidate){
            count++;
        }
        else{
            count--;
        }
    }
    return candidate;
}

long long power(int x, int n) {
    if (n == 0)      // base case
        return 1;
    return x * power(x, n - 1);
}

class Solution {
public:
    void solve(int n, char from, char aux, char to, vector<string>& res) {
        if (n == 1) {
            res.push_back("Move disk 1 from " + string(1, from) +
                          " to " + string(1, to));
            return;
        }

        solve(n - 1, from, to, aux, res);

        res.push_back("Move disk " + to_string(n) +
                      " from " + string(1, from) +
                      " to " + string(1, to));

        solve(n - 1, aux, from, to, res);
    }

    vector<string> towerOfHanoi(int n) {
        vector<string> res;
        solve(n, 'A', 'B', 'C', res);
        return res;
    }
};


int main() {
    string str;
    cout<<"Enter a string: ";
    //cin>>str;
    getline(cin,str);
    // cout<<"Reversed: "<<reverse(str)<<endl`;
    // cout<<isPallindrome(str);
    // cout<<removeDuplicates2(str);
    //cout<<firstNonRepeatingCharacter(str)<<endl;
    //countCharacters(str);

    vector<int> v={3,2,3};
    // reverseArray(v);
    // for(int i:v){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // vector<int> result=twoSum(v,9);
    // for(int r:result){
    //     cout<<r<<" ";
    // }
    // cout<<isArmstrong(153);
    // cout<<removeSpaces(str);

    //cout<<binaryToDecimal(1011);

    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=5;i>=1;i--){
    //     for(int j=1;j<=i;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    //cout<<lengthOfLongestSubstring("abcabcbb");
    // cout<<maxSumSubarray(v,3);

    // cout<<countWords(str);

    cout<<majorityElement(v);

    
    return 0;
}
