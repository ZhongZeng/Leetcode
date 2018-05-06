

/*
Leetcode 830. Positions of Large Groups


Test Cases:
"abbxxxxzzy"
"abc"
"abcdddeeeeaabbbcd"
"aaa"

*/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<int> vc;
        vector<vector<int>> rt;
        int c=0, i, s;
        
        for( i=1; i<S.size(); i++){
            if(S[i-1]!=S[i]){
                if(c<3){
                    c=0;
                }else{
                    vc={s, i-1};
                    rt.push_back(vc);
                    c=0;
                }
            }else{
                if(c!=0){
                    c++;
                }else{
                    s=i-1;
                    c=2;
                }
            }
        }
        
        if(2<c){
            vc={s, i-1};
            rt.push_back(vc);
        }        
        
        return rt;
    }
};
