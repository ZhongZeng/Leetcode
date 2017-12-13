

/*

Leetcode 349. Intersection of Two Arrays

Related Topics 
Hash Table, Two Pointers, Binary Search, Sort 
Similar Questions 
Intersection of Two Arrays II 

Next challenges: Strobogrammatic Number, 
Logger Rate Limiter, Implement Magic Dictionary

Test Cases:
[]
[]
[1,2,2,1]
[2,2]

Runtime: 6 ms
Your runtime beats 28.11 % of cpp submissions.

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // O(m+n) time
        vector<int> vc;
        unordered_set<int> us1, us2;
        
        for(int i=0; i!=nums1.size(); i++){
            if(us1.find(nums1[i])==us1.end())   us1.emplace(nums1[i]);
        }
        
        for(int i=0; i!=nums2.size(); i++){
            if(us2.find(nums2[i])==us2.end())   us2.emplace(nums2[i]);
        }
        
        for(unordered_set<int>::iterator usi=us1.begin(); usi!=us1.end(); usi++){
            if(us2.find(*usi)!=us2.end())   vc.push_back(*usi);
        }
        
        return vc;
    }
};
