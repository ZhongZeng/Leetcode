

/*
953. Verifying an Alien Dictionary

Test Cases:
["hello","leetcode"]
"hlabcdefgijkmnopqrstuvwxyz"
["hello","hellol"]
"hlabcdefgijkmnopqrstuvwxyz"

Related Topics: Hash Table 

Runtime: 8 ms

*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // order.length == 26; All chars are lowercase letters 
        vector<int> od(26,0);
        
        for( int i=0; i<order.size(); i++)  od[order[i]-'a']=i;
        
        for( int i=1; i<words.size(); i++){
            if(!isSmaller(words[i-1],words[i],od))    return false;
        }
        
        return true;
    }
    
    bool isSmaller( string& s1, string& s2, vector<int>& od ){
        int i;
        
        for( i=0; i<s1.size()&&i<s2.size(); i++){
            if(od[s1[i]-'a']<od[s2[i]-'a']){
                return true;
            }else if(od[s1[i]-'a']>od[s2[i]-'a']){
                return false;
            }
        }
        
        return i!=s2.size();
    }
};