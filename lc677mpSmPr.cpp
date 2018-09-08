
/*
Leetcode 677. Map Sum Pairs

Companies   
Akuna Capital 
Related Topics 
Trie 

Test Cases: 
["MapSum", "insert", "sum", "insert", "sum","insert", "sum", "sum"]
[[], ["apple",3], ["ap"], ["app",2], ["ap"],["app",1],["ap"],["b"]]
["MapSum", "insert", "sum", "insert", "sum", "sum"]
[[], ["aa",3], ["a"], ["aa",2], ["a"], ["aa"]]

Next challenges: Word Search II, Design Search Autocomplete System, Prefix and Suffix Search

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

// trie
struct node{
    char c;
    int vl, sum;
    unordered_map<char,node*> um;
    node(): vl(0),sum(0){}
    node(char _c): c(_c),vl(0),sum(0){}
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root=new node();
    }
    
    void insert(string key, int val) {
        // update i in insert; O(key.size()) time 
        node * nd, * newNd;
        unordered_map<char,node*>::iterator umi;
        vector<node*> vn;
        vn.push_back(root);
        int i=0, t;
        
        for( ; i<key.size(); i++){
            nd=vn.back();
            umi=nd->um.find(key[i]);
            if(umi!=nd->um.end())   vn.push_back(umi->second);
            else    break;
        }
        
        for( ; i<key.size(); i++){
            newNd=new node(key[i]);
            vn.back()->um.emplace(key[i],newNd);
            vn.push_back(newNd);
        }
        
        t=vn.back()->vl;
        vn.back()->vl=val;
        for( i=0; i<vn.size(); i++) vn[i]->sum+=val-t;// update vl&sum along prefix path 
        
        return ;
    }
    
    int sum(string prefix) {
        int i;
        node * nd=root;
        
        for( i=0; i<prefix.size(); i++){
            unordered_map<char,node*>::iterator umi=nd->um.find(prefix[i]);
            if(umi!=nd->um.end())   nd=umi->second;
            else    break;
        }
        
        return i!=prefix.size()?0:nd->sum;
    }
    
protected:
    node * root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
