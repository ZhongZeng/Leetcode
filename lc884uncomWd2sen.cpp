

/*
Leetcode 884. Uncommon Words from Two Sentences

Related Topics 
Hash Table 

Test Cases:
"this apple is sweet"
"this apple is sour"
"apple apple"
"banana"

Runtime: 4 ms

*/


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        // hash table, string, O(n) time 
        unordered_map<string,int> uma, umb;
        vector<string> rt;
        
        intoMap( A, uma);
        intoMap( B, umb);
        
        intoVs( uma, umb, rt);
        intoVs( umb, uma, rt);
        
        return rt;
    }
    
    void intoVs(unordered_map<string,int>& uma, unordered_map<string,int>& umb, vector<string>& rt){
        for( unordered_map<string,int>::iterator umi=uma.begin(); umi!=uma.end(); umi++){
            if(umi->second==1){
                if(umb.find(umi->first)==umb.end()) rt.push_back(umi->first);
            }
        }        
        
        return ;
    }
    
    void intoMap(string& A, unordered_map<string,int>& uma){
        unordered_map<string,int>::iterator umi;
        string s;
        
        for( int i=0; i<A.size(); i++){
            if(A[i]!=' '){
                s.push_back(A[i]);
            }else{
                umi=uma.find(s);
                if(umi!=uma.end())  umi->second+=1;
                else    uma.emplace(s,1);
                s.clear();
            }
        }
        umi=uma.find(s);
        if(umi!=uma.end())  umi->second+=1;
        else    uma.emplace(s,1);        
        
        return ;
    }
};
