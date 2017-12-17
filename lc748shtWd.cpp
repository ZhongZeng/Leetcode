

/*
Leetcode 748. Shortest Completing Word

Test Cases；
"1s3 PSt"
["step","steps","stripe","stepple"]
"1s3 456"
["looks", "pest", "stew", "show"]

Runtime: 19 ms

*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        // hash_table
        // licensePlate will be a string with length in range [1, 7].
        // It is guaranteed an answer exists.
        unordered_map<char,int> um, umt;
        unordered_map<char,int>::iterator umi;
        int ml, loc;
        vector<int> vc;
        char c;
        for(int i=0; i!=licensePlate.size(); i++){
            c=licensePlate[i];
            if(isUpper(c)){
                c=c+'z'-'Z';
            }else if(isLower(c)){
                
            }else{
                continue;
            }
            
            umi=um.find(c);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(c,1); 
        }
        
        //for(auto ele:um)    cout<<ele.first<<"-"<<ele.second<<" ";
        
        for(int i=0; i!=words.size(); i++){
            umt=um;
            for(int j=0; j!=words[i].size(); j++){
                c=words[i][j];
                if(isUpper(c)){
                    c=c+'z'-'Z';
                }else if(isLower(c)){
                    
                }else{
                    continue;
                }
                
                umi=umt.find(c);
                if(umi!=umt.end()){
                    if(umi->second!=1)  umi->second-=1;
                    else    umt.erase(umi);
                    if(umt.empty()){
                        vc.push_back(i);
                        break;
                    }
                }
            }
        }
        
        loc=vc[0];
        ml=words[loc].size();
        for(int i=1; i!=vc.size(); i++){
            if(words[vc[i]].size()<ml){
                loc=vc[i];
                ml=words[loc].size();
            }
        }
        
        return words[loc];
    }
    
protected:
    bool isLower(char & c){
        return -1<c-'a'&&-1<'z'-c;
    }
    
    bool isUpper(char & c){
        return -1<c-'A'&&-1<'Z'-c;
    }
    
};