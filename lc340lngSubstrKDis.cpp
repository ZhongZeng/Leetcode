
/*
Leetcode 340. Longest Substring with At Most K Distinct Characters

Companies   
Amazon, Google 
Related Topics 
Hash Table, String 
Similar Questions 
Longest Substring with At Most Two Distinct Characters, Longest Repeating Character Replacement

Test Cases:
"eceba"
2
"aa"
1

Next challenges: Longest Repeating Character Replacement

Runtime: 12 ms
Your runtime beats 46.03 % of cpp submissions.

*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
		// 2-pointer, hash table, O(n) time, similar to LRU 
		if(k<1)	return 0;
        int sz=0, mx=0;
		unordered_map<char,int> um;// char, latest appearance of char 
		unordered_map<char,int>::iterator umi;
		
		for( int i=0, j=0; j<s.size(); j++){// [i,j]
			umi=um.find(s[j]);
			if(sz<k){
				if(umi!=um.end()){
					umi->second=j;
				}else{
					sz++;
					um.emplace(s[j],j);
				}
			}else{// sz==k 
				if(umi!=um.end()){
					umi->second=j;
				}else{
					um.emplace(s[j],j);
					// remove one earliest last-appearing char, i<umi->second meaning not the last apperance 
					for( umi=um.find(s[i]); i<umi->second; umi=um.find(s[++i]) ){}
					um.erase(umi);// i==umi->second
					i++;
				}
			}
			if(mx<j-i+1)	mx=j-i+1;
		}
		
		return mx;
    }
};
