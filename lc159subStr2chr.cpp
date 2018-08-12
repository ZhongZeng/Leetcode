
/*
Leetcode 159. Longest Substring with At Most Two Distinct Characters

Companies   
Google, Facebook 
Related Topics 
Hash Table, Two Pointers, String 
Similar Questions 
Longest Substring Without Repeating Characters, 
Sliding Window Maximum, Longest Substring with At Most K Distinct Characters

Test Cases:
"eceba"
"ccaabbb"
""
"a"
"aa"
"abaccc"

Next challenges: Longest Substring with At Most K Distinct Characters

Runtime: 4 ms
Your runtime beats 96.06 % of cpp submissions.

*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // 2-pointer, O(n) time 
        if(s.size()<3)  return s.size();
        int i, j, mx=0;
        vector<pair<char,int>> um;// char in [a,b], its possible smallest-index location
        um.push_back(make_pair(s[0],0));
        
        for( i=0, j=1; j<s.size(); j++){
            if(um.size()<2){
                if(um[0].first!=s[j])   um.push_back(make_pair(s[j],j));
            }else{//==2 (1<j) 
                if(um[0].first==s[j]){
                    if(s[j]!=s[j-1])    um[0].second=j;
                }else if(um[1].first==s[j]){
                    if(s[j]!=s[j-1])    um[1].second=j;
                }else{// new char 
                    if(um[0].first==s[j-1]){
                        i=um[0].second;
                        um[1].first=s[j];
                        um[1].second=j;
                    }else{// um[1].first==s[j-1] 
                        i=um[1].second;
                        um[0].first=s[j];
                        um[0].second=j;
                    }
                }
            }
            //cout<<i<<","<<j<<"; ";
            if(mx<j-i+1)    mx=j-i+1;
        }
        
        return mx;
    }
};
