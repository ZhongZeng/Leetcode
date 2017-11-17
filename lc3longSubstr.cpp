
/*
Leetcode 3. Longest Substring Without Repeating Characters

Related Topics 
Hash Table, Two Pointers, String 
Similar Questions 
Longest Substring with At Most Two Distinct Characters

Next challenges: Longest Substring with At Most Two Distinct Characters

Test Cases:
"qwnfenpglqdq"
"abba"
"abcabcbb"
""

Runtime: 26 ms
You are here! 
Your runtime beats 69.50 % of cpp submissions.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<1)  return 0;
        unordered_map<char, int> um;
        unordered_map<char, int>::iterator umi;
        int ml=0, b=-1;
        for( int i=0; i!=s.size(); i++ ){ // (b,i]
            //cout<<i<<" "<<endl;
            umi=um.find(s[i]);
            if( umi!=um.end() ){
                if( b<umi->second ){
                    ml = ml<i-b-1 ? i-b-1 : ml;
                    //cout<<ml<<" "<<b<<" "<<i<<endl;
                    b = umi->second;                               
                }
                umi->second = i;  
            }else{
                um.emplace(s[i],i);                               
            }            
        }        
        ml = ml<s.size()-b-1 ? s.size()-b-1 : ml;
        //cout<<ml<<" "<<b<<" "<<s.size()<<endl;
        
        return ml;
    }
};
