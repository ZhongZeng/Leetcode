/*
916. Word Subsets

Related Topics: String 

Test Cases:
["amazon","apple","facebook","google","leetcode"]
["e","o"]
["amazon","apple","facebook","google","leetcode"]
["ec","oc","ceo"]

Runtime: 128 ms, faster than 62.43% of C++ online submissions for Word Subsets.
*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        // O(m+n) time, m&n is total length of char in A&B
        vector<string> rt;
        vector<int> vc(26,0);
        
        for( int i=0; i<B.size(); i++){
            vector<int> vt(26,0);
            for( int j=0; j<B[i].size(); j++)   vt[B[i][j]-'a']+=1;
            for( int j=0; j<vt.size(); j++) if(vc[j]<vt[j]) vc[j]=vt[j];
        }
        
        for( int i=0; i<A.size(); i++){
            vector<int> vt=vc;
            for( int j=0; j<A[i].size(); j++)   vt[A[i][j]-'a']-=1;
            bool b=true;
            for( int j=0; j<vt.size(); j++){
                if(0<vt[j]){
                    b=false;
                    break;
                }
            }
            if(b)   rt.push_back(A[i]);
        }
        
        return rt;
    }
};
