
/*
522. Longest Uncommon Subsequence II

Related Topics: String
Similiar Questions: Longest Uncommon Subsequence I 

Test Cases:
["aba","cdc","eae"]
["aba","ada","eae"]

Runtime: 4 ms, faster than 62.66% of C++ online submissions for Longest Uncommon Subsequence II.

*/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        // greedy 
        // strs[i].size()<=10, strs.size() in [2,50] 
        int i, j, len;
        bool b;
        sort(strs.begin(),strs.end(),greaterThan);
        
        for( i=0; i<strs.size(); i++){// if s is subsequence of t, subsequence of s if subsequence of t 
            for( j=0; j<strs.size(); j++){// check if strs[i] valid
                if(j==i)    continue;
                if(strs[j].size()>strs[i].size()){
                    if(isSubsequence(strs[j],strs[i]))  break;
                }else if(strs[j].size()==strs[i].size()){
                    if(isSame(strs[j],strs[i]))  break;
                }else{
                    return strs[i].size();
                }
            }
            if(j==strs.size())   return strs[i].size();
        }
        
        return -1;
    }
    
    static bool greaterThan(string& s1, string& s2){
        return s1.size()>s2.size();
    }

protected:
    bool isSubsequence(string& s, string& t){// greedy
        for( int i=0, j=0; i<s.size(); i++){
            if(s[i]==t[j])  j++;
            if(j==t.size()) return true;
        }
        return false;
    }
    
    bool isSame(string& s, string& t){
        if(s.size()!=t.size())  return false;// redundant in this case
        for(int i=0; i<s.size(); i++){
            if(s[i]!=t[i])  return false;
        }
        return true;
    }
    

};
