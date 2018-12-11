

/*
Leetcode 647. Palindromic Substrings

Companies   
Pure Storage, Amazon, Facebook 
Related Topics 
String, Dynamic Programming 
Similar Questions 
Longest Palindromic Substring, Longest Palindromic Subsequence, Palindromic Substrings

Test Cases:
"abc"
"aaa"

Next challenges: Longest Palindromic Subsequence
*/

// Runtime: 4 ms, faster than 94.26% of C++ online submissions for Palindromic Substrings.
class Solution {
public:
    int countSubstrings(string s) {
        int sum=0;

        for( int i=0; i<s.size(); i++){
            for( int j=i-1, k=i; -1<j&&k<s.size(); j--, k++){
                if(s[j]==s[k])  sum++;
                else    break;
            }
            for( int j=i, k=i; -1<j&&k<s.size(); j--, k++){
                if(s[j]==s[k])  sum++;
                else    break;
            }        
        }

        return sum;        
    }
};

// Runtime: 4 ms	Your runtime beats 94.21 % of cpp submissions.
class Solution {
public:
    int countSubstrings(string s) {
        // DP, record all Palindromic substring ending at i; O(n*n) time 
        int rt=s.size();// single char 
        vector<int> vc, vd;
        
        for( int i=0; i<s.size(); i++){
            vd.clear();
			for( int j=0; j<vc.size(); j++){
				if(0<vc[j]&&s[vc[j]-1]==s[i]){
					vd.push_back(vc[j]-1);
					rt++;
				}
			}
			vd.push_back(i);// single char 
			vd.push_back(i+1);// empty string 
			vc=vd;
        }
        
        return rt;
    }
};
