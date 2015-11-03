/*============================================================
Problem: LRU Cache
==============================================================
Design and implement a data structure for Least Recently Used 
(LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key 
if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not 
already present. When the cache reached its capacity, it 
should invalidate the least recently used item before 
inserting a new item.
============================================================*/
class LRUCache {
private:
    list<int> leastRecentUse;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int _capacity;

    void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
        int key = it->first;
        leastRecentUse.erase(it->second.second);
        leastRecentUse.push_front(key);
        it->second.second = leastRecentUse.begin();
    }
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }

    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            touch(it);
            it->second.first = value;
        }
        else {
            if (cache.size() == _capacity) {
                cache.erase(leastRecentUse.back());
                leastRecentUse.pop_back();
            }
            leastRecentUse.push_front(key);
            cache[key] = {value, leastRecentUse.begin()};
        }
    }
};