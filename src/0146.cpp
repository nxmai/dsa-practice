#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int _capacity;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> _map;
    
public:
    LRUCache(int capacity) : _capacity(capacity) {
    }
    
    int get(int key) {
        if(_map.find(key) != _map.end()){
            keys.erase(_map[key].second);
            keys.push_front(key);
            _map[key].second = keys.begin();
            return _map[key].first;
        }   
        return -1;
    }
    
    void put(int key, int value) {
        if(_map.find(key) != _map.end()){
            keys.erase(_map[key].second);
            keys.push_front(key);
            _map[key] = {value, keys.begin()};
        }
        else
        {
            if(keys.size() == _capacity){
                _map.erase(keys.back());
                keys.pop_back();
            }
            keys.push_front(key);
            _map[key] = {value, keys.begin()};
        }
    }
};