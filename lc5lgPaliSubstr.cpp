
/*
Leetcode 5. Longest Palindromic Substring

Companies   
Amazon, Microsoft, Adobe, Google, Facebook, Baidu, GoDaddy, Yahoo, Alibaba, Apple, Airbnb, IBM, JPMorgan 
Related Topics 
String, Dynamic Programming
Similar Questions 
Shortest Palindrome, Palindrome Permutation, Palindrome Pairs, 
Longest Palindromic Subsequence, Palindromic Substrings

Runtime: 56 ms
Your runtime beats 43.11 % of cpp submissions.

*/

class Solution {
public:
    string longestPalindrome(string s) {
		// DP, O(n*n) time; if multiple, return any  
		if(s.size()<1)	return "";
        string rt;
		pair<int,int> pr=make_pair(0,1);
		vector<int> vc={0,1}, vd;// s[vc[i],) is palindrome 
		
		for( int i=1; i<s.size(); i++){
			vd.clear();
			for( int j=0; j<vc.size(); j++){
				if(0<vc[j]&&s[vc[j]-1]==s[i]){
					vd.push_back(vc[j]-1);
					if(pr.second-pr.first<i+2-vc[j])	pr=make_pair(vc[j]-1,i+1);
				}
			}
            vd.push_back(i);// s[i] itself 
            vd.push_back(i+1);// empty string 
			vc=vd;
            //for(auto e:vc)  cout<<e<<" ";   cout<<endl;
		}
		
		for( int i=pr.first; i<pr.second; i++)	rt.push_back(s[i]);
		
		return rt;
    }
};
