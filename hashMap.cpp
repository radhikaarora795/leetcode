#include <iostream>
#include <unordered_map>
using namespace std;


void printMap(unordered_map<int, string> map){
    /* Each i is a pair<int, string>, so:
    i.first prints the key.
    i.second prints the value.*/

    for(auto i:map){
        cout<<i.first<<" : "<<i.second<<endl;
    }
}

int main(){
    unordered_map<int, string> map;
    map[1]="abc";
    map[2]="def";
    map[3]="ghi";
    //printMap(map);

    /* accessing elements: can be done using [] and at() function 
    if key does not exist [] will insert a new key with default values
    if key does not exist .at() will throw an out_of_range exception*/

    cout<<map[1]<<endl;
    cout<<map[4]<<endl; // inserted with default value ""

    cout<<"printing map"<<endl;
    //printMap(map);

    cout<<map.at(2);

    /* check existence using .find()
    read only, no insertion
    returns an interator, a pointer like object to the key value pair*/

    auto it=map.find(6);
    if (it !=map.end()){
        cout<<"found key 2, value: "<<it->second<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    // traversing
    for(auto it=map.begin(); it !=map.end();it++){
        cout<<it->first<<": "<<it->second<<endl;
    }

    // deletion
    map.erase(4);
    cout<<"After del:\n";
    printMap(map);

    
                                    
    return 0;
}