
/*
Leetcode 288. Unique Word Abbreviation

Companies 
Google
Related Topics 
Hash Table, Design 
Similar Questions 
Two Sum III - Data structure design, Generalized Abbreviation

Next challenges: Generalized Abbreviation

Test Cases:
["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique"]
[[["deer","door","cake","card"]],["dear"],["cart"],["cane"],["make"]]
["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique"]
[[["deer","door","cake","card"]],["dear"],["door"],["cart"],["cake"]]
["ValidWordAbbr","isUnique"]
[[["hello"]],["hello"]]
["ValidWordAbbr","isUnique"]
[[["hello","hello"]],["hello"]]
["ValidWordAbbr","isUnique"]
[[["a"]],[""]]
["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique"]
[[["deer","door","cake","card"]],["dear"],["door"],["cart"],["cake"]]

Runtime: 168 ms
Your runtime beats 25.63 % of cpp submissions.

*/

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        // O(n*m) time
        // this question should be more well defined instead of relying on test cases to find out 
        string s;
        unordered_map<string, int>::iterator it;
        for(int i=0; i<dictionary.size(); i++){
            it=us.find(dictionary[i]);
            if(it==us.end()){
                us.emplace(dictionary[i],1);
                
                s.clear();
                s.push_back(dictionary[i][0]);
                if(2<dictionary[i].size())  s.append(to_string(dictionary[i].size()-2));
                if(1<dictionary[i].size())  s.push_back(dictionary[i].back());
                //cout<<dictionary[i]<<","<<s<<endl;
                it=uq.find(s);
                if(it!=uq.end())    it->second+=1;
                else    uq.emplace(s, 1);                
            }
        }
    }
    
    bool isUnique(string word) {
        string s;
        s.push_back(word[0]);
        if(2<word.size())   s.append(to_string(word.size()-2));
        if(1<word.size())   s.push_back(word.back());
        
        unordered_map<string, int>::iterator it=uq.find(s);
        return it==uq.end()||(it->second<2&&us.find(word)!=us.end());
    }
    
    unordered_map<string, int> us, uq;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
 