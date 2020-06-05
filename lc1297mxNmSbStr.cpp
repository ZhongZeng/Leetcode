/*
1297. Maximum Number of Occurrences of a Substring

Medium
Companies	Roblox
Related Topics	String, Bit Manipulation

Test Cases:
"aababcaab"
2
3
4
"aaaa"
1
3
3
"aabcabcab"
2
2
3
"abcde"
2
3
3

Runtime: 116 ms, faster than 71.37% of C++ online submissions for Maximum Number of Occurrences of a Substring.
Memory Usage: 13.4 MB, less than 74.95% of C++ online submissions for Maximum Number of Occurrences of a Substring.
Runtime: 116 ms, faster than 71.37% of C++ online submissions for Maximum Number of Occurrences of a Substring.
Memory Usage: 13.6 MB, less than 66.74% of C++ online submissions for Maximum Number of Occurrences of a Substring.
Next challenges: Basic Calculator IV, Find K-Length Substrings With No Repeated Characters,
Before and After Puzzle
*/

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // Two-pointer, Greedy; O(n*m) time; use minSize only; lowercase English letters only
        unordered_map<string,int> counts;
        vector<int> vc(26,0);
        int unq=0, mx=0;
        
        for( int i=0; i<s.size()&&i<minSize; i++){
            vc[s[i]-'a']+=1;
            if(vc[s[i]-'a']==1) unq++;
        }
        if(unq<=maxLetters){
            if(counts[s.substr(0,minSize)]!=NULL)   counts[s.substr(0,minSize)]+=1;
            else    counts[s.substr(0,minSize)]=1;
        }
        
        for( int i=0; i+minSize<s.size(); i++){
            vc[s[i]-'a']-=1;
            if(vc[s[i]-'a']==0) unq--;
            vc[s[i+minSize]-'a']+=1;
            if(vc[s[i+minSize]-'a']==1)   unq++;
            if(unq<=maxLetters){
                if(counts[s.substr(i+1,minSize)]!=NULL)   counts[s.substr(i+1,minSize)]+=1;
                else    counts[s.substr(i+1,minSize)]=1;
            }
        }
        
        for( unordered_map<string,int>::iterator it=counts.begin(); it!=counts.end(); it++)
            mx=mx<it->second?it->second:mx;
        
        return mx;
    }
};

/*
Runtime: 1392 ms, faster than 5.04% of C++ online submissions for Maximum Number of Occurrences of a Substring.
Memory Usage: 197 MB, less than 100.00% of C++ online submissions for Maximum Number of Occurrences of a Substring.
Next challenges: Basic Calculator IV, 
Find K-Length Substrings With No Repeated Characters, Before and After Puzzle
*/
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // O(n*m*m) time
        int mx=0;
        unordered_map<string,int> counts;
        
        for( int i=0, j, uq; i<s.size(); i++){
            vector<int> vc(26, 0);
            for( j=0, uq=0; j<minSize-1&&i+j<s.size(); j++){
                vc[s[i+j]-'a']+=1;
                if(vc[s[i+j]-'a']==1)   uq++;
            }
            for( ; j<maxSize&&i+j<s.size(); j++){
                vc[s[i+j]-'a']+=1;
                if(vc[s[i+j]-'a']==1)   uq++;
                if(uq<=maxLetters){
                    if(counts.find(s.substr(i,j+1))!=counts.end())
                        counts[s.substr(i,j+1)]+=1;
                    else
                        counts[s.substr(i,j+1)]=1;
                }else{
                    break;
                }
            }
        }
        
        for( unordered_map<string,int>::iterator it=counts.begin(); it!=counts.end(); it++)
            mx=mx<it->second?it->second:mx;
        
        return mx;
    }
};
