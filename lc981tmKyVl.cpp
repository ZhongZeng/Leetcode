/*
981. Time Based Key-Value Store

Related Topics: Hash Table, Binary Search 

Testcases:
["TimeMap","set","get","get","set","get","get"]
[[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
["TimeMap","set","set","get","get","get","get","get"]
[[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]

236 ms beats 33.33 % of cpp submissions.

*/

class TimeMap {
    // The timestamps for all TimeMap.set operations are strictly increasing.
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {// O(1) time 
        auto it=um.find(key);
        if(it!=um.end()){
            it->second.push_back(make_pair(value,timestamp));
        }else{
            vector<pair<string,int>> vs={make_pair(value,timestamp)};
            um.emplace( key, vs);
        }
        return ;
    }
    
    string get(string key, int timestamp) {// O(log(n)) time 
        auto it=um.find(key);
        if(it!=um.end()){
            int t=binarySearch( it->second, timestamp);
            if(t!=-1)   return it->second[t].first;
        }
        return "";// else: not found
    }
    
protected:
    unordered_map<string,vector<pair<string,int>>> um;
    
    int binarySearch(vector<pair<string,int>>& vs, int timestamp){// O(log(n)) time 
        if(vs.size()<1||timestamp<vs[0].second) return -1;
        
        int b=0, e=vs.size(), m;// timestamp in [b,e) 
        while(b+1<e){
            m=b+(e-b)/2;
            if(timestamp<vs[m].second) e=m;
            else    b=m;
        }
        
        return b;
    }
};