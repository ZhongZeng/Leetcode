
/*
893. Groups of Special-Equivalent Strings

Companies   
Facebook 
Related Topics 
String 

Test Cases:
["a","b","c","a","c","c"]
["aa","bb","ab","ba"]
["abc","acb","bac","bca","cab","cba"]
["abcd","cdab","adcb","cbad"]

Runtime: 20 ms

*/

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        // same length, only lowercase letters in A[i]; special-equivalent is transitive 
		// O(n*n*l) time 
        vector<vector<int>> vv;// hash table is more effective 
        bool b;
        int i, j, k, l;
        
        for( i=0; i<A.size(); i++){
            b=true;
            vector<int> vc(52,0);
            for( j=0; j<A[i].size(); j+=2)  vc[A[i][j]-'a']+=1;
            for( j=1; j<A[i].size(); j+=2)  vc[A[i][j]-'a'+26]+=1;
            
            for( k=0; k<vv.size(); k++){
                for( l=0; l<vc.size(); l++){
                    if(vv[k][l]!=vc[l]) break;
                }
                if(l==vc.size())    break;
            }
            if(k==vv.size())    vv.push_back(vc);
        }
        
        return vv.size();
    }
};