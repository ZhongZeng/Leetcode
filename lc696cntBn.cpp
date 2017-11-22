

/*
Leetcode 696. Count Binary Substrings

Related Topics 
String 
Similar Questions 
Encode and Decode Strings 

Next challenges: Encode and Decode Strings

Runtime: 46 ms
You are here! 
Your runtime beats 29.90 % of cpp submissions.

*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size()<2)  return 0;
        int c=0, p=0, t=1;// p-previous length, t-this length
        for(int i=1; i!=s.size(); i++){
            if(s[i]!=s[i-1]){                                
                c+= p<t?p:t;
                p=t;
                t=1;
            }else{
                t++;           
            }                        
        }
        c+= p<t?p:t;        
        
        return c;
    }
};
