

/*
Leetcode 97. Interleaving String

Related Topics 
String, Dynamic Programming

Next challenges: Unique Binary Search Trees II, Read N Characters Given Read4, Coin Path

Test Cases:
"aa"
"ab"
"abaa"
"aabcc"
"dbbca"
"aadbbcbcac"
"a"
""
"a"
""
"a"
"a"
""
""
""
"a"
"b"
"a"

Runtime: 4 ms
Your runtime beats 70.21 % of cpp submissions.

*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // DP: O(m*n) time, O(m) space; similiar to lcs; inspired by MITOCW 6.006
        if(s1.size()+s2.size()!=s3.size())  return false;
        // delete the above line than it's a solution to a different problem
        int i, j, tc, td;
        vector<int> vb(1,-1), vc(1,-1), vd;// vector of longest matched position in s3 
        
        // s1[:i], empty s2 matches longest substr in s3 
        for( i=0; i<s1.size(); i++)  vb.push_back(s1[i]!=s3[vb.back()+1]?vb.back():vb.back()+1);
        if(vb.back()==s3.size()-1)  return true;
        
        // empty s1, s2[:i] matches longest substr in s3 
        for( j=0; j<s2.size(); j++)  vc.push_back(s2[j]!=s3[vc.back()+1]?vc.back():vc.back()+1);    
        
        for( i=0; i<s1.size(); i++){// s1[:i], s2[:j] matches longest substr in s3
            vd.clear();
            vd.push_back(vb[i+1]);// s1[:i], s2[:-1] matches longest substr in s3
            for( j=0; j<s2.size(); j++){
                tc=s1[i]!=s3[vc[j+1]+1]?vc[j+1]:vc[j+1]+1;// from s1[:i-1], s2[:j] 
                td=s2[j]!=s3[vd.back()+1]?vd.back():vd.back()+1;// from s1[:i], s2[:j-1] 
                vd.push_back(tc<td?td:tc);
                if(vd.back()==s3.size()-1)  return true;
            }
            vc=vd;
            //for(auto e:vc)  cout<<e<<" ";   cout<<endl;
        }
        
        return vc.back()==s3.size()-1;
    }
};
