

/*
Leetcode 389. Find the Difference


Related Topics 
Hash Table, Bit Manipulation 
Similar Questions 
Single Number 

Next challenges: Single Number

Runtime: 9 ms
You are here! 
Your runtime beats 5.18 % of cpp submissions.

Runtime: 6 ms
You are here! 
Your runtime beats 18.37 % of cpp submissions.

*/


class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()<1)  return t[0];
        if(t.size()<1)  return s[0];
        
        string::iterator it=s.begin();
        int i=*it;
        while( ++it!=s.end() ){
            i = i^*it;
        }
        
        for(it=t.begin(); it!=t.end(); it++){
            i = i^*it;
        }             
        
        //cout<<i<<' '<<(int)'e'<<endl;
        
        return (char) i;        
    }    
    
};
