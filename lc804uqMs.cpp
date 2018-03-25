
/*
Leetcode 804. Unique Morse Code Words

Weekly Contest 77  

Test Case:
["gin", "zen", "gig", "msg"]

*/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // words[i] will only consist of lowercase letters.
        string s;
        unordered_set<string> us;
        vector<string> vs={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(int i=0; i<words.size(); i++){
            s.clear();
            for(int j=0; j<words[i].size(); j++)    s.append(vs[words[i][j]-'a']);
            if(us.find(s)==us.end())    us.emplace(s);
        }
        
        return us.size();
    }
};
