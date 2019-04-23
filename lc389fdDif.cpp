/*
Leetcode 389. Find the Difference

Related Topics 
Hash Table, Bit Manipulation 
Similar Questions 
Single Number 

Next challenges: Single Number
Next challenges: Minimum Unique Word Abbreviation, 
Maximum XOR of Two Numbers in an Array, Number of Distinct Islands II
*/

// Runtime: 8 ms		Your runtime beats 60.03 % of cpp submissions.
// Memory Usage: 8.8 MB	Your memory usage beats 98.35 % of cpp submissions.
class Solution {
public:
    char findTheDifference(string s, string t) {
        // Bit Manipulation
		int c=0;
		for( int i=0; i<s.size(); i++)	c^=s[i];// +- would also work 
		for( int i=0; i<t.size(); i++)	c^=t[i];
		return c;
    }
};

// Runtime: 9 ms	Your runtime beats 5.18 % of cpp submissions.
// Runtime: 6 ms	Your runtime beats 18.37 % of cpp submissions.
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
