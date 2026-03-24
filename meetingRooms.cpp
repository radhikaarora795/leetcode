/*
You are given timings of n meetings in the form of (start[i],end[i]) where start[i] is the start time
of meeting i and end[i] is the end time of meeting i. Return the maximum number of meetings that can be
accomadated in a single meeting room at a particular time.
Note: the start time of one chosen meeting cant be equal to the end time of the other chosen meetings.

example:
input: start[]=[1,3,0,5,8,5] end[]=[2,4,6,7,9,9]
output: 4
explanation: maximum four meetings can be held with given start and end timings. The meetings are:
(1,2),(3,4),(5,7) and (8,9)

input: start[]=[10,12,20] end[]=[20,25,30]
output: 1
explanation: only one meeting can be held with given start and end timings

input: start[]=[1,2] end[]=[100,99]
output: 1

Constraints:
1<=n<=10^5
0<=start[i]<=end[i]<=10^6
*/

#include <iostream>
#include <utility>  // for pair
using namespace std;

/*
Key Observations
If we choose meetings that end earliest, we leave the room free for as many later meetings as possible.
The condition start[i] > lastEnd ensures there’s no overlap (strictly greater, because start = end is not allowed here).
Sorting by end time is the optimal greedy step.
*/

class Solution{
public:
    int maxMeetings(vector<int>& start,vector<int>& end){
        vector<pair<int,int>> meetings;
        for(int i=0;i<start.size();i++){
            meetings.push_back({end[i],start[i]});
        }
        sort(meetings.begin(),meetings.end());

        int count=0;
        int lastEnd=-1;

        for(auto m:meetings){
            if(m.second>lastEnd){   //If start[i] > lastEnd
                count++;
                lastEnd=m.first;     //lastEnd=end[i];
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> start={1,2};
    vector<int> end={100,99 };
    cout<<s.maxMeetings(start,end);
    
    return 0;
}