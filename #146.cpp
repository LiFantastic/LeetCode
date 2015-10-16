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
class LRUCache{
    int m_capacity;
    unordered_map<int, list<pair<int, int>>::iterator> key2listNode;  //key2listNode_iter->first: key, key2listNode_iter->second: list iterator;
    list<pair<int, int>> keyValueList;                               //keyValueList_iter->first: key, keyValueList_iter->second: value;
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        auto it = key2listNode.find(key);
        if (it == key2listNode.end())  //key doesn't exist
            return -1;
        keyValueList.splice(keyValueList.begin(), keyValueList, it->second);  //move the node corresponding to key to front
        return it->second->second;  //return value of the node
    }
    
    void set(int key, int value) {
        auto it = key2listNode.find(key);
        if (it != key2listNode.end()) {  //key exists
            keyValueList.splice(keyValueList.begin(), keyValueList, it->second);  //move the node corresponding to key to front
            it->second->second = value;  //update value of the node
            return;
        }
        if (keyValueList.size() == m_capacity) {  //reached capacity
           int key_to_del = keyValueList.back().first; 
           keyValueList.pop_back();  //remove node in list;
           key2listNode.erase(key_to_del);  //remove key in map
        }
        keyValueList.emplace_front(key, value);  //create new node in list
        key2listNode[key] = keyValueList.begin();  //create correspondence between key and node
    }
};