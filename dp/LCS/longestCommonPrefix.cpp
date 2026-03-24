/* 
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string result="";
    int i=0,j;
    bool areEqual=false;
    int length=strs.size();
    for(j=0;j<200;j++){
        i=0;
        if(length == 1 && j<strs[i].size()){
            result.push_back(strs[i][j]);
        }
        while(i+1<length && j<strs[i].size() ){
            if(strs[i][j] == strs[i+1][j]){
                areEqual=true;
            }
            else{
                areEqual=false;
                return result;
            }
            i++;
        }
        if(i>0){
            result.push_back(strs[i-1][j]);
        }
        else{
            break;
        }
        
    }
    return result;
}


int main(){

    vector<string> s={"aabc","aaabc"}; 
    string result = longestCommonPrefix(s);
    cout<<result;
    return 0;
}