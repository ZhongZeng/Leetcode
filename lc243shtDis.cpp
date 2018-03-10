
/*
Leetcode 243. Shortest Word Distance

Companies 
LinkedIn
Related Topics 
Array 
Similar Questions 
Shortest Word Distance II, Shortest Word Distance III

Test Cases:
["a","b"]
"a"
"b"

Runtime: 17 ms
Your runtime beats 19.56 % of cpp submissions.

*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        // You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
        // O(sum(words[i].size()))
        if(words.size()<1)  return 0;
        int rt;
        vector<int> v1, v2;
        for(int i=0; i<words.size(); i++){
            if(sameStr(words[i],word1)) v1.push_back(i);
            if(sameStr(words[i],word2)) v2.push_back(i);
        }
        
        rt=abs(v1[0],v2[0]);
        for(int i1=0, i2=0; i1<v1.size()&&i2<v2.size(); ){
            if(v1[i1]<v2[i2]){
                while(i1<v1.size()&&v1[i1]<v2[i2]){
                    rt=v2[i2]-v1[i1]<rt?v2[i2]-v1[i1]:rt;
                    i1++;
                }
            }else{
                while(i2<v2.size()&&v2[i2]<v1[i1]){// = is not needed 
                    rt=v1[i1]-v2[i2]<rt?v1[i1]-v2[i2]:rt;
                    i2++;
                }
            }
        }
        
        return rt;
    }
    
protected:     
    int abs(int& i, int& j){
        return i<j?j-i:i-j;
    }
    
    bool sameStr(string& s1, string& s2){
        if(s1.size()!=s2.size())    return false;
        for(int i=0; i<s1.size(); i++)  if(s1[i]!=s2[i])    return false;
        return true;
    }
};


/*
// Runtime: 17 ms
// Your runtime beats 19.56 % of cpp submissions.
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        // You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
        // O(sum(words[i].size()))
        if(words.size()<1)  return 0;
        int rt;
        vector<int> v1, v2;
        for(int i=0; i<words.size(); i++){
            if(sameStr(words[i],word1)) v1.push_back(i);
            if(sameStr(words[i],word2)) v2.push_back(i);
        }
        
        rt=abs(v1[0],v2[0]);
        for(int i1=0, i2=0; i1<v1.size()&&i2<v2.size(); ){
            if(v1[i1]<v2[i2]){
                while(i1<v1.size()&&v1[i1]<v2[i2]){
                    rt=abs(v1[i1],v2[i2])<rt?abs(v1[i1],v2[i2]):rt;
                    i1++;
                }
            }else{
                while(i2<v2.size()&&v2[i2]<=v1[i1]){// = is not needed 
                    rt=abs(v1[i1],v2[i2])<rt?abs(v1[i1],v2[i2]):rt;
                    i2++;
                }
            }
        }
        
        return rt;
    }
    
protected:     
    int abs(int& i, int& j){
        return i<j?j-i:i-j;
    }
    
    bool sameStr(string& s1, string& s2){
        if(s1.size()!=s2.size())    return false;
        for(int i=0; i<s1.size(); i++)  if(s1[i]!=s2[i])    return false;
        return true;
    }
};
*/
