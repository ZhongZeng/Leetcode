
/*

Leetcode 784. Letter Case Permutation

Weekly Contest 72  

Test Cases:
"a1b2"
"12345"
"abc"
"3z"
""

*/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        // string, BFS
        vector<string> vs={S};
        letTra(vs, 0);
        return vs;
    }
    
    void letTra(vector<string>& vs, int i){
        for( int t; i<vs[0].size(); i++){
            t=vs[0][i]-'A';
            if(-1<t&&t<26){// upper case
                for(int j=0, z=vs.size(); j<z; j++){
                    vs.push_back(vs[j]);
                    vs.back()[i]+=32;
                }
                break;
            }else if(31<t&&t<58){// lower case
                for(int j=0, z=vs.size(); j<z; j++){
                    vs.push_back(vs[j]);
                    vs.back()[i]-=32;
                }
                break;
            }
        }
        
        if(i<vs[0].size())  return letTra(vs, i+1);
        else    return ;
    }
};