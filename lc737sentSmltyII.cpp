
/*
Leetcode 737. Sentence Similarity II

Companies 
Google 
Related Topics 
Depth-first Search, Union Find 
Similar Questions 
Friend Circles, Accounts Merge, Sentence Similarity

Test Cases:
["great","acting","skills"]
["fine","drama","talent"]
[["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
["I","have","enjoyed","happy","thanksgiving","holidays"]
["I","have","enjoyed","happy","thanksgiving","holidays"]
[["great","good"],["extraordinary","good"],["well","good"],["wonderful","good"],["excellent","good"],["fine","good"],["nice","good"],["any","one"],["some","one"],["unique","one"],["the","one"],["an","one"],["single","one"],["a","one"],["truck","car"],["wagon","car"],["automobile","car"],["auto","car"],["vehicle","car"],["entertain","have"],["drink","have"],["eat","have"],["take","have"],["fruits","meal"],["brunch","meal"],["breakfast","meal"],["food","meal"],["dinner","meal"],["super","meal"],["lunch","meal"],["possess","own"],["keep","own"],["have","own"],["extremely","very"],["actually","very"],["really","very"],["super","very"]]
["a","very","delicious","meal"]
["one","really","delicious","dinner"]
[["great","good"],["extraordinary","good"],["well","good"],["wonderful","good"],["excellent","good"],["fine","good"],["nice","good"],["any","one"],["some","one"],["unique","one"],["the","one"],["an","one"],["single","one"],["a","one"],["truck","car"],["wagon","car"],["automobile","car"],["auto","car"],["vehicle","car"],["entertain","have"],["drink","have"],["eat","have"],["take","have"],["fruits","meal"],["brunch","meal"],["breakfast","meal"],["food","meal"],["dinner","meal"],["super","meal"],["lunch","meal"],["possess","own"],["keep","own"],["have","own"],["extremely","very"],["actually","very"],["really","very"],["super","very"]]
["a","very","delicious","meal"]
["one","really","delicious","dinner"]
[["great","good"],["a","one"],["eat","have"],["dinner","meal"],["really","very"]]
["a","very","delicious","meal"]
["one","really","delicious","dinner"]
[["a","one"],["extremely","very"],["actually","very"],["really","very"],["super","very"]]

Runtime: 207 ms ( I would say path compresson is powerful.) 
Your runtime beats 94.57 % of cpp submissions.

*/

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size()!=words2.size())    return false;
        string s, t;
        vector<unordered_map<string, string>::iterator> vt;
        unordered_map<string, string> um;
        unordered_map<string, string>::iterator umi, umj;
        
        // Quick Union w/ path compresson
        for( int i=0; i<pairs.size(); i++){
            umi=um.find(pairs[i].first);
            umj=um.find(pairs[i].second);
            if( umi!=um.end() ){
                if( umj!=um.end() ) umd( um, umi, umj);
                else    umd( um, umi, pairs[i].second);
            }else{
                if( umj!=um.end() ){
                    umd( um, umj, pairs[i].first);
                }else{
                    um.emplace(pairs[i].first, pairs[i].first);
                    um.emplace(pairs[i].second, pairs[i].first);
                }                
            }
        }
        
        // Quick Find
        for( umi=um.begin(); umi!=um.end(); umi++)   umd(um, umi);
        
        for( int i=0; i<words1.size(); i++){
            if(words1[i]!=words2[i]){
                umi=um.find(words1[i]);
                umj=um.find(words2[i]);
                if(umi==um.end()||umj==um.end()||umi->second!=umj->second){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void umd(unordered_map<string, string>& um, unordered_map<string, string>::iterator umi){ 
        unordered_map<string, string>::iterator umj=umi;
        vector<unordered_map<string, string>::iterator> vt={umj};
        while(umj->first!=umj->second){
            umj=um.find(umj->second);
            vt.push_back(umj);
        }
        for(int j=0; j<vt.size()-1; j++)    vt[j]->second=vt.back()->second;
        return ;
    }
    
    void umd(unordered_map<string, string>& um, 
             unordered_map<string, string>::iterator umi, unordered_map<string, string>::iterator umj){
        vector<unordered_map<string, string>::iterator> vt={umi};
        while(umi->first!=umi->second){
            umi=um.find(umi->second);
            vt.push_back(umi);
        }
        string s=vt.back()->second;
        for(int j=0; j<vt.size()-1; j++)    vt[j]->second=vt.back()->second;

        vt={umj};
        while(umj->first!=umj->second){
            umj=um.find(umj->second);
            vt.push_back(umj);
        }
        for(int j=0; j<vt.size(); j++)  vt[j]->second=s;// no -1 here 
        return ;
    }    
    
    void umd(unordered_map<string, string>& um, unordered_map<string, string>::iterator umi, string& s){
        vector<unordered_map<string, string>::iterator> vt={umi};
        while(umi->first!=umi->second){
            umi=um.find(umi->second);
            vt.push_back(umi);
        }
        for(int j=0; j<vt.size()-1; j++)    vt[j]->second=vt.back()->second;
        um.emplace( s, vt.back()->second);
        return ;
    }
};
