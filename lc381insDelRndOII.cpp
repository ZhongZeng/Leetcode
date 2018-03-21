

/*
Leetcode 381. Insert Delete GetRandom O(1) - Duplicates allowed

This is not much harder than 380. Insert Delete GetRandom O(1) 

Companies 
Yelp 
Related Topics 
Array, Hash Table, Design 
Similar Questions 
Insert Delete GetRandom O(1)

Next challenges: Implement Queue using Stacks, 
3Sum Smaller, Design Hit Counter

Test Cases:
["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]
[[],[1],[1],[2],[],[1],[]]
["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[1],[1],[2],[1],[2],[2],[1],[2],[2],[2],[],[],[],[],[],[],[],[],[],[]]
["RandomizedCollection","insert","remove","insert","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[0],[0],[-1],[0],[],[],[],[],[],[],[],[],[],[]]

Runtime: 66 ms
Your runtime beats 15.32 % of cpp submissions.

*/

class RandomizedCollection {
public:
    // unordered_map + vector
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        unordered_map<int, unordered_set<int>>::iterator umi=um.find(val);
        if(umi!=um.end()){
            umi->second.emplace(vc.size());
            vc.push_back(val);
            return false;
        }else{
            unordered_set<int> us;
            us.emplace(vc.size());
            um.emplace(val, us);
            vc.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        unordered_map<int, unordered_set<int>>::iterator umi=um.find(val), umj;
        if(umi!=um.end()){
            if(val!=vc.back()){
                int v=vc.back(), p=*(umi->second.begin());
                vc[p]=vc.back();
                vc.pop_back();

                if(1<umi->second.size())    umi->second.erase(umi->second.begin());
                else    um.erase(umi);

                umj=um.find(v);
                umj->second.emplace(p);
                umj->second.erase(vc.size());
            }else{
                vc.pop_back();
                if(1<umi->second.size())    umi->second.erase(vc.size());
                else    um.erase(umi);
            }
            
            // for(auto e:vc)  cout<<e<<" ";   cout<<endl;
            // for(auto e:um)  cout<<e.first<<","<<e.second.size()<<" ";   cout<<endl<<endl;            
            return true;
        }else{
            return false;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int i=rand()%vc.size();
        return vc[i];
    }
    
    unordered_map<int, unordered_set<int>> um;
    vector<int> vc;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
