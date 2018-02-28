
/*
Leetcode 524. Longest Word in Dictionary through Deleting

Companies 
Google
Related Topics 
Two Pointer, Sort 
Similar Questions 
Longest Word in Dictionary

Test Cases: 
"abpcplea"
["ale","apple","monkey","plea"]
"bab"
["ba","ab","a","b"]
"barfoofoobarthefoobarman"
["bar","foo","the"]

Next challenges: Longest Word in Dictionary

Runtime: 102 ms
Your runtime beats 55.66 % of cpp submissions.

*/

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        // 2-pointer; greedy; O(s.size()*d.size())
        // All the strings in the input will only contain lower-case letters. 
        // If there are more than one possible results, return the longest word with the smallest lexicographical order. 
        vector<pair<int,int>> vc;
        vector<vector<pair<int,int>>> vv(26, vc);
        int t, sz, mx=0, si, sj;
        string rt="";
        
        for(int i=0; i<d.size(); i++)   if(0<d[i].size())   vv[d[i][0]-'a'].push_back(make_pair(i,0));
        
        for(int i=0; i<s.size(); i++){
            //cout<<s[i]<<":";
            vc.clear();
            t=s[i]-'a';
            for( int j=0; j<vv[t].size(); j++){
                si=vv[t][j].first;
                sj=vv[t][j].second;
                //cout<<d[si]<<",";
                if(sj==d[si].size()-1){// reaches the end
                    if(mx<d[si].size()){
                        mx=d[si].size();
                        rt=d[si];                        
                    }else if(mx==d[si].size()&&lessStr(d[si],rt)){
                        rt=d[si];
                    }
                }else{
                    if(d[si][++sj]!=s[i])   vv[d[si][sj]-'a'].push_back(make_pair(si,sj));
                    else    vc.push_back(make_pair(si,sj));
                }
            }
            //cout<<endl;
            vv[t]=vc;
        }
        
        return rt;
    }
    
protected:    
    bool lessStr(string& s1, string& s2){//s1.size()==s2.size()
        for(int i=0; i<s1.size(); i++){
            if(s1[i]-s2[i]<0)   return true;
            else if(0<s1[i]-s2[i])  return false;
        }
        return false;
    }
};
