
/*
Leetcode 484. Find Permutation

Companies 
Google
Related Topics 
Greedy 

Test Cases:
"DDIIDI"
"DDIIDII"
"DDIIDIDD"

Next challenges: Course Schedule III, Split Array into Consecutive Subsequences, 
Best Time to Buy and Sell Stock with Transaction Fee

Runtime: 77 ms
Your runtime beats 53.26 % of cpp submissions.

*/

class Solution {
public:
    vector<int> findPermutation(string s) {
        // greedy O(n): 'I': smallest (valid guranteed); 'D': smallest in the consecutive 'D' sequence
        vector<int> rt;
        int n=1, i, j, c;

        for( i=0; i<s.size(); i++){
            if(s[i]!='I'){
                for( c=1; i<s.size()&&s[i]!='I'; i++)   c++;
                for( j=0; j<c; j++) rt.push_back(n+c-j-1);
                n+=c;
            }else{
                rt.push_back(n++);
            }
        }        
        
        if(s.back()!='D')   rt.push_back(n);
        
        return rt;
    }
};
