
/*
Leetcode 217. Contains Duplicate

Tags: Array, Hash Table
Similar Problems: (E) Contains Duplicate II (M) Contains Duplicate III
Next challenges: (E) Contains Duplicate II(M) Contains Duplicate III

You are here! 
Your runtime beats 26.89 % of cpp submissions.	46 ms

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // I use hash tabel. O(n) time
        // we can also sort the array, but it's O(nlog(n)) time
        // corner cases: [0]
        unordered_set<int> unset;
        unordered_set<int>::iterator unit;
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            unit=unset.find(*it);
            // cout<<*it<<" "<<endl;
            if(unit==unset.end()){
                unset.emplace(*it);
            }else{
                return true;
            }
        }
        return false;
        
    }
};
