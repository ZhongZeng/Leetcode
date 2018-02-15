
/*
Leetcode 646. Maximum Length of Pair Chain

Related Topics 
Dynamic Programming
Similar Questions 
Longest Increasing Subsequence, Increasing Subsequences

Next challenges: Increasing Subsequences

Test Cases:
[[1,2], [2,3], [3,4]]
[[1,2],[3,4],[7,10],[8,20]]

Runtime: 44 ms
Your runtime beats 72.64 % of cpp submissions.

*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // longest is defined as # of pairs
        // O(n*lg(n)) time
        if(pairs.size()<1)  return 0;
        
        sort(pairs.begin(), pairs.end(), lessThan);
        
        int sum=1;
        vector<int> bk=pairs[0];
        
        for(int i=1; i<pairs.size(); i++){
            if(bk[1]<pairs[i][0]){
                bk=pairs[i];
                sum++;
            }else if(pairs[i][1]<bk[1]){
                bk=pairs[i];
            }
        }
        
        return sum;
    }
    
    static bool lessThan(vector<int>& p1, vector<int>& p2){
        return p1[0]<p2[0];
    }
};