/*
1433. Check If a String Can Break Another String

Medium
Companies	endurance
Related Topics	String, Greedy 

Test Cases:
"abc"
"xya"
"abe"
"acd"
*/

/*
Runtime: 76 ms, faster than 98.57% of C++ online submissions for Check If a String Can Break Another String.
Memory Usage: 11.6 MB, less than 59.55% of C++ online submissions for Check If a String Can Break Another String.
Next challenges: Reverse Words in a String II, Search Suggestions System,
Find the Longest Substring Containing Vowels in Even Counts
*/
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
		// Greedy; O(n) time, O(26) space; s1, s2: lowercase English letters only
        vector<int> c1(26, 0), c2(26, 0);
		for( int i=0; i<s1.size(); i++)	c1[s1[i]-'a']+=1;
		for( int i=0; i<s1.size(); i++)	c2[s2[i]-'a']+=1;
		
		return check( c1, c2)||check( c2, c1);
    }
	
protected:
	bool check(vector<int> & c1, vector<int> & c2){
		for( int i=0, sum1=0, sum2=0; i<c1.size(); i++){
			sum1+=c1[i];
			sum2+=c2[i];
			if(sum1<sum2)	return false;
		}
		return true;
	}
};

/*
Runtime: 392 ms, faster than 69.69% of C++ online submissions for Check If a String Can Break Another String.
Memory Usage: 11.5 MB, less than 87.37% of C++ online submissions for Check If a String Can Break Another String.
Next challenges: Reverse Words in a String II, Search Suggestions System,
Find the Longest Substring Containing Vowels in Even Counts
*/
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        // greedy; O(n*log(n)) time
        if(s1.size()!=s2.size())    return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return check( s1, s2)||check( s2, s1);
    }
    
protected:
    bool check(string & s1, string & s2){
        for( int i=0; i<s1.size(); i++)
            if(s1[i]<s2[i]) return false;
        return true;
    }
};