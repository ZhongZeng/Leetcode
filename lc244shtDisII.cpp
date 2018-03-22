
/* 

Leetcode 244. Shortest Word Distance II

Companies 
LinkedIn 
Related Topics 
Hash Table, Design 
Similar Questions 
Merge Two Sorted Lists, Shortest Word Distance, Shortest Word Distance III

Next challenges: Maximum Size Subarray Sum Equals k, Design Excel Sum Formula, Smallest Range
Next challenges: Copy List with Random Pointer, Design Snake Game, All O`one Data Structure

Test Cases:
["WordDistance","shortest","shortest"]
[[["practice","makes","perfect","coding","makes"]],["coding","practice"],["makes","coding"]]

Runtime: 38 ms
Your runtime beats 87.85 % of cpp submissions.

*/

class WordDistance {
public:
    // You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
    WordDistance(vector<string> words) {
        vector<int> vc;
        unordered_map<string, vector<int>>::iterator umi; 
        for(int i=0; i<words.size(); i++){
            umi=um.find(words[i]);
            if(umi!=um.end()){
                umi->second.push_back(i);
            }else{
                vc={i};
                um.emplace(words[i],vc);
            }
        }
    }
    
    unordered_map<string, vector<int>> um;
    vector<string> vs;    
    
    int shortest(string word1, string word2) {
        // if words1&words2 have been visited, O(words.size()) time; otherwise O() time 
        return shortest( um.find(word1)->second, um.find(word2)->second);
    }
    
    int shortest(vector<int>& vc1, vector<int>& vc2){
        int rt=vc1[0]<vc2[0]?vc2[0]-vc1[0]:vc1[0]-vc2[0];
        
        for(int i1=0, i2=0; i2<vc2.size(); ){
            while(i1<vc1.size()&&vc1[i1]<vc2[i2]){
                rt=vc2[i2]-vc1[i1]<rt?vc2[i2]-vc1[i1]:rt;
                i1++;
            }
            if(!(i1<vc1.size()))    break;
            while(i2<vc2.size()&&vc2[i2]<vc1[i1]){
                rt=vc1[i1]-vc2[i2]<rt?vc1[i1]-vc2[i2]:rt;
                i2++;
            }
        }
        return rt;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

/*
// Runtime: 924 ms
// Your runtime beats 0.81 % of cpp submissions.
// shortest called REPEATIVELY 
class WordDistance {
public:
    WordDistance(vector<string> words) {
        vs=words;
    }
    
    unordered_map<string, vector<int>> um;
    vector<string> vs;    
    
    int shortest(string word1, string word2) {
        // if words1&words2 have been visited, O(words.size()) time; otherwise O() time 
        if(sameStr(word1,word2))    return 0;
        unordered_map<string, vector<int>>::iterator umi1=um.find(word1), umi2=um.find(word2);
        
        if(umi1!=um.end()){
            if(umi2!=um.end()){
                return shortest(umi1->second, umi2->second);
            }else{
                vector<int> vc2=posStr(word2);
                return shortest(umi1->second, vc2);
            }
        }else{
            if(umi2!=um.end()){
                vector<int> vc1=posStr(word1);
                return shortest(vc1, umi2->second);
            }else{
                vector<int> vc1=posStr(word1), vc2=posStr(word2);
                return shortest(vc1, vc2);
            }
        }
    }
    
    int shortest(vector<int>& vc1, vector<int>& vc2){
        int rt=vc1[0]<vc2[0]?vc2[0]-vc1[0]:vc1[0]-vc2[0];
        
        for(int i1=0, i2=0; i2<vc2.size(); ){
            while(i1<vc1.size()&&vc1[i1]<vc2[i2]){
                rt=vc2[i2]-vc1[i1]<rt?vc2[i2]-vc1[i1]:rt;
                i1++;
            }
            if(!(i1<vc1.size()))    break;// i1<vc1.size()&&i2<vc2.size() is WRONG
            while(i2<vc2.size()&&vc2[i2]<vc1[i1]){
                rt=vc1[i1]-vc2[i2]<rt?vc1[i1]-vc2[i2]:rt;
                i2++;
            }
        }
        return rt;
    }
    
    vector<int> posStr(string& word1){
        vector<int> vc;
        for(int i=0; i<vs.size(); i++)  if(sameStr(vs[i],word1))    vc.push_back(i);
        um.emplace(word1, vc);
        return vc;
    }
    
    bool sameStr(string& s1, string& s2){
        if(s1.size()!=s2.size())    return false;
        for(int i=0; i<s1.size(); i++)  if(s1[i]!=s2[i])    return false;
        return true;
    }
};

*/
