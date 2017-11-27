

/*
Leetcode 734. Sentence Similarity

Related Topics 
Hash Table 
Similar Questions 
Friend Circles, Accounts Merge, Sentence Similarity II 

Next challenges: Sentence Similarity II

Test Cases:
["great","acting","skills"]
["fine","drama","talent"]
[["great","fine"],["drama","acting"],["skills","talent"]]

["great","acting","skills"]
["fine","drama","talent"]
[["grea","fine"],["drama","acting"],["skills","talent"]]

["this","summer","thomas","get","actually","actually","rich","and","possess","the","actually","great","and","fine","vehicle","every","morning","he","drives","one","nice","car","around","one","great","city","to","have","single","super","excellent","super","as","his","brunch","but","he","only","eat","single","few","fine","food","as","some","fruits","he","wants","to","eat","an","unique","and","actually","healthy","life"]
["this","summer","thomas","get","very","very","rich","and","possess","the","very","fine","and","well","car","every","morning","he","drives","a","fine","car","around","unique","great","city","to","take","any","really","wonderful","fruits","as","his","breakfast","but","he","only","drink","an","few","excellent","breakfast","as","a","super","he","wants","to","drink","the","some","and","extremely","healthy","life"]
[["good","nice"],["good","excellent"],["good","well"],["good","great"],["fine","nice"],["fine","excellent"],["fine","well"],["fine","great"],["wonderful","nice"],["wonderful","excellent"],["wonderful","well"],["wonderful","great"],["extraordinary","nice"],["extraordinary","excellent"],["extraordinary","well"],["extraordinary","great"],["one","a"],["one","an"],["one","unique"],["one","any"],["single","a"],["single","an"],["single","unique"],["single","any"],["the","a"],["the","an"],["the","unique"],["the","any"],["some","a"],["some","an"],["some","unique"],["some","any"],["car","vehicle"],["car","automobile"],["car","truck"],["auto","vehicle"],["auto","automobile"],["auto","truck"],["wagon","vehicle"],["wagon","automobile"],["wagon","truck"],["have","take"],["have","drink"],["eat","take"],["eat","drink"],["entertain","take"],["entertain","drink"],["meal","lunch"],["meal","dinner"],["meal","breakfast"],["meal","fruits"],["super","lunch"],["super","dinner"],["super","breakfast"],["super","fruits"],["food","lunch"],["food","dinner"],["food","breakfast"],["food","fruits"],["brunch","lunch"],["brunch","dinner"],["brunch","breakfast"],["brunch","fruits"],["own","have"],["own","possess"],["keep","have"],["keep","possess"],["very","super"],["very","actually"],["really","super"],["really","actually"],["extremely","super"],["extremely","actually"]]

["actually"]
["very"]
[["actually","very"]]

["very"]
["actually"]
[["very","super"],["very","actually"]]

Runtime: 9 ms
Sorry. We do not have enough accepted submissions to show runtime distribution chart.

*/

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        // instead of creating symetric hash_table, search both words1&words2
        if(words1.size()!=words2.size())    return false;
        
        unordered_map<string, unordered_set<string>> um;
        unordered_map<string, unordered_set<string>>::iterator umi;
        unordered_set<string> us;
        unordered_set<string>::iterator usi;
        for(vector<pair<string, string>>::iterator it=pairs.begin(); it!=pairs.end(); it++){
            umi=um.find(it->first);
            if( umi!=um.end() ){
                usi=umi->second.find(it->second);
                if( usi==umi->second.end() )    umi->second.emplace(it->second);                                
            }else{
                us.empty();
                us.emplace(it->second);
                um.emplace(it->first,us);
            }                        
        }
        
        for(int i=0; i!=words1.size(); i++){
            if(words1[i]==words2[i])    continue;
            umi=um.find(words1[i]);
            if( !(umi!=um.end() && umi->second.find(words2[i])!=umi->second.end()) ){
                umi=um.find(words2[i]);
                if( !(umi!=um.end() && umi->second.find(words1[i])!=umi->second.end()) ){   
                    //cout<<(umi!=um.end())<<endl;                    
                    //cout<<(umi->second.find(words1[i])!=umi->second.end())<<endl;//cout this may cause runtime err
                    //cout<<words1[i]<<" "<<words2[i]<<endl;
                    return false;
                }
            }
        }
        
        return true;
    }    
};
