
/*
Leetcode 380. Insert Delete GetRandom O(1)

Companies 
Google, Facebook, Amazon, Uber, Twitter, Yelp, Pocket Gems
Related Topics 
Array, Hash Table, Design 
Similar Questions 
Insert Delete GetRandom O(1) - Duplicates allowed

Next challenges: Insert Delete GetRandom O(1) - Duplicates allowed

Test Case:
["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]
[[],[1],[2],[2],[],[1],[2],[]]

Runtime: 59 ms
Your runtime beats 29.88 % of cpp submissions.

*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        unordered_map<int, int>::iterator mi=mv.find(val);
        if(mi!=mv.end()){
            return false;
        }else{
            mv.emplace(val, vc.size());
            vc.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_map<int, int>::iterator mi=mv.find(val);
        if(mi!=mv.end()){
            vc[mi->second]=vc.back();
            mv.find(vc.back())->second=mi->second;
            mv.erase(mi);
            vc.pop_back();
            return true;
        }else{
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i=rand()%vc.size();
        return vc[i];
    }
    
    unordered_map<int, int> mv;
    vector<int> vc;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
