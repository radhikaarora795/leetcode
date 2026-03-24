#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findSubstr(string str,string substr){
    int n=str.size();
    int m=substr.size();
    int index=-1;

    for(int i=0;i<(n-m+1);i++){
        for(int j=0;j<m;j++){
            if(str[i+j] != substr[j]){
                break;
            }
        if(j==(m-1)){
            index=i;
            return index; // first occurance
        }
        }
    }
    return index;   // if not found
}

vector<int> findAllOccurances(string str,string substr){
    int n=str.size();
    int m=substr.size();
    int index=-1;
    vector<int> result;

    for(int i=0;i<(n-m+1);i++){
        for(int j=0;j<m;j++){
            if(str[i+j] != substr[j]){
                break;
            }
        if(j==(m-1)){
            result.push_back(i);
        }
        }
    }
    return result;   // if not found
}

string mysubstr(string str,int start,int end){
    string result;

    if(end<start){
        end=start+end;
    }   // end: number of characters 

    for(int i=start;i<end;i++){
        result+=str[i];
    }
    return result;
}

string mysubstr(string str,int start){
    string result;
    int end=str.size();

    for(int i=start;i<end;i++){
        result+=str[i];
    }
    return result;
}

int main() {
    /*string str;
    cout<<"Enter: ";
    getline(cin,str);
    //str=cin.get();
    cout<<str;*/

    /*vector<int> result=findAllOccurances("abcdefcd","cd");

    for(int i:result){
        cout<<i<<" ";
    }*/
    cout<<mysubstr("ChatGPT by OpenAI",8,2);
    
    return 0;
}