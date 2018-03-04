
/*
792. Number of Matching Subsequences

Weekly Contest 74  

Test Cases:
"abcde"
["a","bb","acd","ace"]

*/

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        // All words in words and S will only consists of lowercase letters.
        // similiar/same to a previou Leetcode 524. Longest Word in Dictionary through Deleting
        int rt=0, i, j, k, wi, ii;
        vector<pair<int,int>> vc;// words, index 
        vector<vector<pair<int,int>>> vv(26, vc);
        for( i=0; i<words.size(); i++){
            if(0<words[i].size())   vv[words[i][0]-'a'].push_back(make_pair(i,0));
        }
        
        for( i=0; i<S.size(); i++){
            vc.clear();
            for( j=0, k=S[i]-'a'; j<vv[k].size(); j++){
                wi=vv[k][j].first;
                ii=vv[k][j].second;
                if(ii!=words[wi].size()-1){
                    if(S[i]!=words[wi][ii+1])   vv[words[wi][ii+1]-'a'].push_back(make_pair(wi,ii+1));
                    else    vc.push_back(make_pair(wi,ii+1));
                }else{
                    rt++;
                }
            }
            vv[k]=vc;
        }
        
        return rt;
    }
};