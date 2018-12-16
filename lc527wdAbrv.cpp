
/*
527. Word Abbreviation

Related Topics: String, Sort 

Similiar Questions: Valid Word Abbreviation, Minimum Unique Word Abbreviation

Test Cases:
["like","god","internal","me","internet","interval","intension","face","intrusion"]
["abcdefg","abccefg","abcckkg"]

Runtime: 80 ms, faster than 29.31% of C++ online submissions for Word Abbreviation.
*/

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
	    // O(n*m*n) time; assuming no duplicates in dict; edited in Google Doc 
        int i, j, k, d;
        bool b;
        string s;
        vector<string> rt;
        unordered_map<string,vector<int>> um;// using trie might be too expensive 

        for( i=0; i<dict.size(); i++){
            if(3<dict[i].size()){
                s=buildStr(dict[i],0);
                unordered_map<string,vector<int>>::iterator umi=um.find(s);
                if(umi!=um.end()){
                    d=0;
                    for( k=0; k<umi->second.size(); k++){
                        for( j=0; j<dict[i].size(); j++){
                            if(dict[i][j]!=dict[umi->second[k]][j])	break;
                        }
                        if(d<j) d=j;
                        // no other rt[!=i] match dict[i] 
                        s=buildStr(dict[umi->second[k]],j);
                        if(rt[umi->second[k]].size()<s.size())  rt[umi->second[k]]=s;
                    }
                    // no other dict[!=i] match rt[i] 
                    rt.push_back(buildStr(dict[i], d));
                    umi->second.push_back(i);
                }else{// no conflict 
                    rt.push_back(s);
                    vector<int> vc={i};
                    um.emplace(s,vc);
                }
            }else{// length <= 3
                rt.push_back(dict[i]);
            }
        }
        
        return rt;
    }
    
    string buildStr(string & s, int j){// s[0:j]+length(substr)+s[-1] 
        if(j<s.size()-3){// 1<s.size()-(j+1)-1
            string t;
            for( int k=0; k<=j; k++)	t.push_back(s[k]);
            t.append(to_string(s.size()-j-2));
            t.push_back(s.back());
            return t;
        }
        return s;
    }
};

