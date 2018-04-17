
/*
Leetcode 712. Minimum ASCII Delete Sum for Two Strings

Companies 
TripleByte
Related Topics 
Dynamic Programming 
Similar Questions 
Edit Distance, Longest Increasing Subsequence, Delete Operation for Two Strings

Next challenges: Regular Expression Matching, 
Unique Binary Search Trees II, Largest Sum of Averages

Test Case:
"sea"
"eat"

Runtime: 19 ms
Your runtime beats 49.58 % of cpp submissions.

*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // Again, MITOCW 6.006 Intro2Algo 21.DPIII blowed my mind!!, which is a more generalized case. 
        // similar to Edit Distance, Delete Operation for Two Strings
        // DP: O(m*n) time, O(m) space, space can be optimized to O(1)
        // All elements of each string will have an ASCII value in [97, 122].
        int d1, d2;
        
        // deleteSum b/t s1[:i] & an empty string 
        vector<int> vc(1,0), vd, v2(1,0);
        for(int i=0; i<s1.size(); i++)  vc.push_back(vc.back()+s1[i]);
        for(int i=0; i<s2.size(); i++)  v2.push_back(v2.back()+s2[i]);
            
        // deleteSum b/t s1[:i] & s2[:j]
        for(int j=0; j<s2.size(); j++){
            vd={v2[j+1]};// deleteSum b/t an empty string & s2[:j]
            for(int i=0; i<s1.size(); i++){
                if(s1[i]!=s2[j]){
                    d1=vd.back()+s1[i];// deleteSum b/t s1[:i-1] & s2[:j]
                    d2=vc[i+1]+s2[j];// deleteSum b/t s1[:i] & s2[:j-1]
                    vd.push_back(d1<d2?d1:d2);
                }else{
                    vd.push_back(vc[i]);// deleteSum b/t s1[:i-1] & s2[:j-1]
                }
            }
            vc=vd;
        }
        
        return vc.back();
    }
};
