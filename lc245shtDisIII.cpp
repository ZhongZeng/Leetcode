

/*
Leetcode 245. Shortest Word Distance III

Companies 
LinkedIn
Related Topics 
Array 
Similar Questions 
Shortest Word Distance, Shortest Word Distance II

Next challenges: Shortest Word Distance II

Test Cases:
["a","b"]
"a"
"b"
["a","b","c","a","a"]
"a"
"b"

Runtime: 17 ms
Your runtime beats 22.18 % of cpp submissions.

*/


class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
		// This doesn't diff much from lc243. lc244 is more difficult. 
        if(sameStr(word1, word2)){
            vector<int> vc=pos(words, word1);
            int rt=vc[1]-vc[0];
            for(int i=2; i<vc.size(); i++)  if(vc[i]-vc[i-1]<rt)    rt=vc[i]-vc[i-1];
            return rt;
        }else{
            vector<int> vc1=pos(words, word1), vc2=pos(words, word2);
            int rt=vc1[0]<vc2[0]?vc2[0]-vc1[0]:vc1[0]-vc2[0];
            for(int i=0, j=0; i<vc1.size()&&j<vc2.size(); ){
                while(i<vc1.size()&&vc1[i]<vc2[j]){
                    if(vc2[j]-vc1[i]<rt)    rt=vc2[j]-vc1[i];
                    i++;
                }
                while(j<vc2.size()&&vc2[j]<vc1[i]){
                    if(vc1[i]-vc2[j]<rt)    rt=vc1[i]-vc2[j];
                    j++;
                }                
            }
            return rt;
        }
    }
    
    vector<int> pos(vector<string>& words, string word1){
        vector<int> vc;
        for(int i=0; i<words.size(); i++)   if(sameStr(words[i], word1))    vc.push_back(i);
        return vc;
    }
    
    bool sameStr(string& s1, string& s2){
        if(s1.size()!=s2.size())    return false;
        for(int i=0; i<s1.size(); i++)  if(s1[i]!=s2[i])    return false;
        return true;
    }
};