
/*
Leetcode 594. Longest Harmonious Subsequence

Related Topics 
Hash Table 

Next challenges: Longest Substring with At Most Two Distinct Characters, 
Unique Word Abbreviation, Binary Tree Vertical Order Traversal

Test Cases:
[1,3,2,2,5,2,3,7]
[]

Runtime: 89 ms
You are here! 
Your runtime beats 85.84 % of cpp submissions.


*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi, umj;
        int len=0, mlen=0;
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            umi=um.find(*it);
            if( umi!=um.end() ){
                umi->second += 1;                
            }else{
                um.emplace( *it, 1);
            }
        }
        
        for(umj=um.begin(); umj!=um.end(); umj++ ){
            umi = um.find( umj->first+1 ) ; 
            if( umi!=um.end() ){
                len = umj->second + umi->second ;
                mlen = len<mlen ? mlen : len;
            }
        }
        
        return mlen;
    }
};
