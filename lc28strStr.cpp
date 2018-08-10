
/*
Leetcode 28. Implement strStr()

Companies   
Facebook, Amazon, Microsoft, Google, Tencent, Alibaba 
Related Topics 
Two Pointer, String 
Similar Questions 
Shortest Palindrome, Repeated Substring Pattern

Test Cases:
"hello"
"ll"
"aaaaa"
"bba"
""
""
"abc"
""
"mississippi"
"issip"
"aabaaabaaac"
"aabaaac"

Next challenges: Shortest Palindrome, Repeated Substring Pattern

Runtime: 4 ms
Your runtime beats 98.18 % of cpp submissions.

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        // KMP, 2-pointer, DP 
        if(needle.empty())  return 0;// got from expected answer 
        vector<int> vc={-1};
        
        for( int i=1, t; i<needle.size(); i++){
            t=vc.back();
            while(t!=-1&&needle[i]!=needle[t+1])	t=vc[t];
			if(needle[i]==needle[t+1])	t++;
            vc.push_back(t);
        }
        //for(auto e:vc)  cout<<e<<" ";
        
        for( int i=0, t=-1; i<haystack.size(); i++){// i,j:last matched position in haystack,needle 
			if(haystack[i]!=needle[t+1]){
				while(t!=-1&&haystack[i]!=needle[t+1])	t=vc[t];
				if(haystack[i]==needle[t+1])	t++;
			}else{
				t++;
			}
            
            if(t==needle.size()-1)  return i-needle.size()+1;
        }
        
        return -1;
    }
};
