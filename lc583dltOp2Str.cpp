
/*
Leetcode 583. Delete Operation for Two Strings

Companies 
Google
Related Topics
String
Similar Questions
Edit Distance, Minimum ASCII Delete Sum for Two Strings

Next challenges: Minimum ASCII Delete Sum for Two Strings

Test Case:
"sea"
"eat"

Runtime: 43 ms
Your runtime beats 73.09 % of cpp submissions.

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        // similar but easier than Leetcode 72. Edit Distance: only add and deletion are allowed, no replace
        // DP: O(m*n) time, O(m) space 
        // Again, MITOCW 6.006 Intro2Algo 21.DPIII blowed my mind!!, which is a more generalized case. 
        // Characters in given words can only be lower-case letters.
        int d;
        vector<int> vc, vd;
        
        // b/t word1[:i] & an empty string 
        for(int i=0; i<=word1.size(); i++)  vc.push_back(i);
        
        for(int j=0; j<word2.size(); j++){
            vd={j+1};// an empty string & word2[:j] 
            for(int i=0; i<word1.size(); i++){// b/t word1[:i] & word2[:j] 
                if(word1[i]!=word2[j])  vd.push_back(vc[i+1]<vd.back()?vc[i+1]+1:vd.back()+1);
                else    vd.push_back(vc[i]);
            }
            vc=vd;
        }
        
        return vc.back();
    }
};
