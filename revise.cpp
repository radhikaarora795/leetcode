#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

/*class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> map;
        vector<int> result;

        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i];
            auto it=map.find(temp);
            if(it != map.end()){
                result.push_back(i);
                result.push_back(map[temp]);
                break;
            }
            map[nums[i]]=i;
        }
        return result;
    }
};*/

int reverse(long x){
    bool negative=false;
    if(x<0){
        negative=true;
        x=x*(-1);
    }
    long rev=0;
    int n=0;
    while(x>0){
        n=x%10;
        rev=rev*10+n;
        x=x/10;
    }
    if(negative==true){
        rev=rev*(-1);
        if(rev<pow(-2,31)){
            rev=0;
        }
    }
    else{
        if(rev>pow(2,31)){
            rev=0;
        }
    }
    return rev;
}

bool isPallindrome(int x){
    int save=x;
    if(x<0){
        return false;
    }
    long long reverse=0;
    int n=0;

    while(x>0){
        n=x%10;
        reverse=reverse*10+n;
        x=x/10;
    }
    if(reverse != save){
        return false;
    }
    return true;
}

class Solution{
public:
    int maxArea(vector<int>& height){
        int length=height.size();
        int vol=0;
        int maxVol=0;
        int p=0;
        int q=length-1;

        while(p<q){
            vol=min(height[p],height[q])*(q-p);
            maxVol=max(maxVol,vol);
            if(height[p]<=height[q]){
                p++;
            }
            else{
                q--;
            }
        }
        return maxVol;
    }
};

int main() {
    Solution s;
    /*vector<int> result;
    vector<int> nums={2,7,11,15};
    
    result=s.twoSum(nums,9);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }*/

    //cout<<reverse(120);
    //cout<<isPallindrome(-121);

    vector<int> v={1,1};
    cout<<s.maxArea(v);
    
    return 0;
}