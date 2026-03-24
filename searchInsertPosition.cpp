#include <iostream>
#include <vector>
using namespace std;

// see below
class Solution1{
    public:
        int binarySearch(vector<int>& v,int beg,int end,int target){
            int mid;
            
            if(end>=beg){
                mid=(beg+end)/2;

                if(v[mid]==target){
                    return mid;
                }
                else if(v[mid]<target){
                    return binarySearch(v,mid+1,end,target);
                }
                else{
                    return binarySearch(v,beg,mid-1,target);
                }
            }
            return -1;
        }

        int findSmaller(vector<int>& v,int beg, int end,int target){
            int index=-1;
            
            while(end>=beg){
                int mid=(beg+end)/2;

                if(v[mid]<target){
                    index=mid;
                    beg=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            return index;
        }

        int searchInsert(vector<int>& nums,int target){
            int beg=0;
            int end=nums.size()-1;
            int positon=binarySearch(nums,beg,end,target);
            if((positon)!=-1){
                return positon;
            }
            else{
                int index=findSmaller(nums,beg,end,target);
                    return index+1;
                }
        }
        
};

// better
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg=0;
        int end=nums.size()-1;
        int mid;

        while(end>=beg){
            mid=(beg+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                beg=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return beg;
    }
    /*
    If the target is not found in the list, the while loop will terminate when beg is greater than 
    end. At this point, beg will be the index where the target should be inserted to maintain the 
    sorted order. We return beg as the insertion point.
    */
};

int main(){
    Solution s;
    vector<int> v={1, 3, 5, 6};
    
    cout<<s.searchInsert(v,7);

    return 0;
}