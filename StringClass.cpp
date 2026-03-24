#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    string str="abc def ghi jkl";
    vector<string> v;
    //cout<<"Enter a string: ";
    //getline(cin,str);
    /*str.push_back('d');
    cout<<str<<endl;
    str.pop_back();
    cout<<"Entered: "<<str<<endl;
    cout<<"length: "<<str.length();*/

    stringstream ss(str);
    string temp;

    char delimiter=' ';

    while(getline(ss,temp,delimiter)){
        v.push_back(temp);
    }

    int length=v.size();
    cout<<v[length-1].length();
    return 0;
}