/*
1002. Find Common Characters

Related Topics:	Array; suggested: Hash Table 

Test Cases:
["bella","label","roller"]
["cool","lock","cook"]

Ranking of Weekly Contest 126:	800 / 4563	
Less than 100 contest participantes solved the hard problem 

*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        // array A of strings made only from lowercase letters
        unordered_map<char,int> um;
        unordered_map<char,int>::iterator umi, uni;
        vector<string> vs;
        
        for( int j=0; j<A[0].size(); j++){
            umi=um.find(A[0][j]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(A[0][j],1);
        }
        
        for( int i=1; i<A.size(); i++){
            unordered_map<char,int> un;
            for( int j=0; j<A[i].size(); j++){
                uni=un.find(A[i][j]);
                if(uni!=un.end())   uni->second+=1;
                else    un.emplace(A[i][j],1);
            }
            
            for( umi=um.begin(); umi!=um.end(); umi++){
                uni=un.find(umi->first);
                if(uni!=un.end())   umi->second=(uni->second<umi->second)?uni->second:umi->second;
                else    umi->second=0;
            }
        }
        
        for( umi=um.begin(); umi!=um.end(); umi++ ){
            string s;
            s.push_back(umi->first);
            for( int i=0; i<umi->second; i++)   vs.push_back(s);
        }
        
        return vs;
    }
};
