
/*
Leetcode 146. LRU Cache

Companies 
Google, Facebook, Microsoft, Amazon, Bloomberg, Uber, Twitter, Snapchat, Zenefits, Yahoo, Palantir
Related Topics 
Design 
Similar Questions 
LFU Cache, Design In-Memory File System, Design Compressed String Iterator

Next challenges: LFU Cache, Design In-Memory File System

Test Cases:
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
["LRUCache","put","put","get","put","put","get"]
[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]

Runtime: 85 ms
Your runtime beats 92.16 % of cpp submissions.

*/

class LRUCache {
public:
    // get() O(1): hash table; put(): delete/add in O(1) double linked list, inspire by title in Discuss
    LRUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        unordered_map<int, pair<int,list<int>::iterator>>::iterator umi=um.find(key);
        if(umi!=um.end()){
            ru.push_front(key);
            ru.erase(umi->second.second);
            umi->second.second=ru.begin();
            return umi->second.first;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        unordered_map<int, pair<int,list<int>::iterator>>::iterator umi=um.find(key);
        if(umi!=um.end()){
            umi->second.first=value;
            ru.erase(umi->second.second);
            ru.push_front(key);
            umi->second.second=ru.begin();
        }else{
            if(um.size()<c){
                ru.push_front(key);
                um.emplace(key, make_pair( value, ru.begin()));                
            }else{
                ru.push_front(key);
                um.emplace(key, make_pair( value, ru.begin()));          
                um.erase(um.find(ru.back()));
                ru.pop_back();
            }                
        }
        return ;
    }
    
    unordered_map<int, pair<int,list<int>::iterator>> um;
    list<int> ru;
    int c;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
