#include <iostream>
#include <unordered_map>
#include <array>
using namespace std;

class LRUCache {
    unordered_map<int, array<int, 2>> map; // key -> {value, timestamp}
    int capacity;
    int time = 0; // global counter to track recency

public:
    LRUCache(int c) {
        capacity = c;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it != map.end()) {
            time++;
            it->second[1] = time; // update timestamp
            return it->second[0];
        }
        return -1;
    }

    void put(int key, int value) {
        time++;
        auto it = map.find(key);
        if (it != map.end()) {
            // update value and timestamp
            it->second[0] = value;
            it->second[1] = time;
        } else {
            if ((int)map.size() >= capacity) {
                // evict least recently used key
                int lruKey = -1, minTime = INT32_MAX; // max value that 32 bit integer can store=2^31-1
                for (const auto &p : map) {
                    if (p.second[1] < minTime) {
                        minTime = p.second[1];
                        lruKey = p.first;
                    }
                }
                if (lruKey != -1) {
                    map.erase(lruKey);
                }
            }
            map[key] = {value, time};
        }
    }

    void printMap() {
        cout << "Current cache:\n";
        for (const auto &p : map) {
            cout << "Key: " << p.first << ", Value: " << p.second[0]
                 << ", Timestamp: " << p.second[1] << endl;
        }
    }
};

int main() {
    LRUCache l(2);
    l.put(1, 10);
    l.put(2, 20);
    l.printMap();

    cout << "get(1): " << l.get(1) << endl; // use key 1
    l.printMap();

    l.put(3, 30); // should evict key 2 (least recently used)
    l.printMap();

    cout << "get(2): " << l.get(2) << endl; // should return -1 (evicted)
    cout << "get(3): " << l.get(3) << endl; // should return 30
    cout << "get(1): " << l.get(1) << endl; // should return 10

    return 0;
}
