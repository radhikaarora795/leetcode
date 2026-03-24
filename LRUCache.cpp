#include <iostream>
#include <unordered_map>
#include <array>
#include <chrono>
using namespace std;

class LRUCache {
    unordered_map<int,array<int,2>> map;
    int capacity;
    int time=0; // timestamp

public:
    LRUCache(int c) {
        capacity=c;
                         // bucket count is number of key value pairs
    }
  
    int get(int key) {
        int result=-1;
        auto it=map.find(key);
        if (it != map.end()) {
            it->second[1]=time++;
            result = it->second[0];
        }
        return result;   
    }
    
    void put(int key, int value) {
        auto it=map.find(key);
        if (it !=map.end()){    // if key found then update its value
            it->second[0]=value;
            it->second[1]=time++;
        }
        else{                               // size full so del least used
            if((int)map.size() >= capacity){
                auto it=map.begin();
                int k=it->first;
                int min=it->second[1];
                for(auto i:map){
                    if(i.second[1]<min){
                        min=i.second[1];
                        k=i.first;
                    }
                }
                map.erase(k);
            }
            map[key][0]=value; // if not found insert key value pair
            map[key][1]=time++;
        }
    }

    /*void printMap(){
        for(auto it : map){
            cout<<it.first<<" : "<<it.second[0]<<" : "<<it.second[1]<<endl;
        }
    }*/
        
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache l(2);
    l.put(1,1);
    l.put(2,2);
    //l.printMap();
    cout<<l.get(1);
    l.put(3,3);

   cout<<l.get(2);

   l.put(4,4);
   cout<<l.get(1);
   cout<<l.get(3);
   cout<<l.get(4);

    
    
    return 0;
}