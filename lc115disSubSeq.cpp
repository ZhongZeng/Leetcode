
/*
Leetcode 115. Distinct Subsequences

Related Topics 
String, Dynamic Programming 

Runtime: 5 ms
Your runtime beats 89.11 % of cpp submissions.

Test Case:
"rabbbit"
"rabbit"

*/

class Solution {
public:
    int numDistinct(string s, string t) {
		// O(n*m) time, O(n) space 
        vector<int> vc(s.size()+1, 1), vd; 
		// s -> empty string t 
		
		// s[:i] -> t[:j]
		for(int j=0; j<t.size(); j++){
			vd={0};// empty string s -> t[:j] 
			for(int i=0; i<s.size(); i++){
				if(s[i]!=t[j])	vd.push_back(vd.back()); 
				else	vd.push_back(vd.back()+vc[i]); 
			}
			vc=vd;
		}
		
		return vc.back();
    }
};
