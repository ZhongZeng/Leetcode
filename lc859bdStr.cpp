
/*
Leetcode 859. Buddy Strings

Test Cases: 
"ab"
"ba"
"aa"
"aa"
"abc"
"abc"

Runtime: 10 ms

*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        // O(n) time&space
        if(A.size()!=B.size())  return false;
        vector<char> vc;
        int ct=0;
        
        for( int i=0; i<A.size(); i++ ){
            if(A[i]!=B[i]){
                if(1<ct){
                    return false;
                }else{
                    vc.push_back(A[i]);
                    vc.push_back(B[i]);
                    ct++;
                }
            }
        }
        
        if(ct==0){// same string 
            unordered_set<char> us;
            unordered_set<char>::iterator usi;
            for( int i=0; i<A.size(); i++ ){
                usi=us.find(A[i]);
                if(usi!=us.end()){
                    return true;
                }else{
                    us.emplace(A[i]);
                }
            }
        }
        
        if(vc.size()!=4)    return false;
        if(vc[0]!=vc.back()||vc[1]!=vc[2])  return false;
        
        return true;
    }
};

