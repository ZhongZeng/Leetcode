/*
467. Unique Substrings in Wraparound String

Company	Google
Related Topcis	Dynamic Programming

Runtime: 16 ms, faster than 33.15% of C++ online submissions for Unique Substrings in Wraparound String.
Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Unique Substrings in Wraparound String.
Next challenges: Sentence Screen Fitting, Find the Shortest Superstring, 
Form Largest Integer With Digits That Add up to Target
*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
		// Dynamic Programming, Array; O(n) time, O(26) space
        if(p.size()<1)  return 0;
        int sum=0, len=1;
        vector<int> lens(26, 0);// longest substring ending w/ (char)('a'+i)
        lens[p[0]-'a']=1;
        for( int i=1; i<p.size(); i++){
            if((p[i]-p[i-1]==1)||(p[i]=='a'&&p[i-1]=='z'))  len++;
            else    len=1;
            if(lens[p[i]-'a']<len)  lens[p[i]-'a']=len;
        }
        for( int i=0; i<lens.size(); i++)   sum+=lens[i];
        return sum;
    }
};
/*
// if allow dupicate
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // Dynamic Programming; O(26*n) time, O(26) space
        int len=1, sum=1;
        for( int i=1; i<p.size(); i++){
            if((p[i]-p[i-1]==1)||(p[i]=='a'&&p[i-1]=='z'))  len++;
            else    len=1;
            sum+=len;
        }
        return sum;
    }
};
*/