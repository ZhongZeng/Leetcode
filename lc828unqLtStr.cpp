
/*
Leetcode 828. Unique Letter String

Companies 
ForUsAll
Related Topics 
Two Pointers

Next challenges: Implement strStr(), Substring with Concatenation of All Words, Candy Crush

Runtime: 16 ms

Test Cases:
"ABCDEF"
"ABA"
"ABAB"
"ABABA"
"AAAA"

*/

class Solution {
public:
    int uniqueLetterString(string S) {
		// DP, hash table, O(n) time, 1 pass
		// 0 <= S.length <= 10000; %1000000007
        int sum=0, ls=0, ts;// ts: sum of UNIQ(substring ending @ S[i])
		unordered_map<char, pair<int,int>> um;// 2nd and latest occurance of char in S 
		unordered_map<char, pair<int,int>>::iterator umi;
		
		for(int i=0; i<S.size(); i++){
			umi=um.find(S[i]);
			if(umi!=um.end()){
                ts=ls+i+1-2*(umi->second.second-umi->second.first)-(umi->second.first+1);// + unique - non repetive of S[i] 
                umi->second.first=umi->second.second;
                umi->second.second=i;
			}else{
				ts=ls+i+1; //# substrings ending @ S[i] = i+1
				um.emplace(S[i], make_pair(-1, i));
			}
            sum=(sum+ts)%1000000007;
			ls=ts%1000000007;
		}
		
		return sum;
    }
};
