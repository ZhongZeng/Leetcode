

/*
Leetcode 242. Valid Anagram

Related Topics
Hash Table, Sort 
Similar Questions 
Group Anagrams, Palindrome Permutation, Find All Anagrams in a String 

Runtime: 13 ms
You are here! 
Your runtime beats 59.22 % of cpp submissions.

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
		// I used hash_table, O(n) time, O(n) space		
        unordered_map<char, int> um;
        unordered_map<char, int>::iterator ie; 
        for(string::iterator it=s.begin(); it!=s.end(); it++){
            ie = um.find(*it);
            if( ie!=um.end() ){
                ie->second = ie->second+1;
            }else{
                um.emplace( *it, 1);
            }            
        }
        
        for(string::iterator it=t.begin(); it!=t.end(); it++){
            ie = um.find(*it);
            if( ie!=um.end() ){
                ie->second = ie->second-1;
            }else{
                return false;
            }            
        }        
        
        for(unordered_map<char, int>::iterator tr=um.begin(); tr!=um.end(); tr++){
            if( tr->second!=0 ){
                return false; 
            }
        }
        
        return true;
    }
};
