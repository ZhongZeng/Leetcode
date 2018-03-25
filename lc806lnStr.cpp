
/*
Leetcode 806. Number of Lines To Write String

Weekly Contest 77  

Test Cases:
[10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
"abcdefghijklmnopqrstuvwxyz"
[4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
"bbbcccdddaaa"

*/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        // The length of S will be in the range [1, 1000].
        // S will only contain lowercase letters.
        vector<int> vc(2,1);
        int i, t=0, l=0;
        for( i=0; i<S.size(); i++ ){
            l=widths[S[i]-'a'];
            if(t+l<101){
                t+=l;
            }else{
                vc[0]+=1;
                t=l;
            }
        }
        vc[1]=t;
        return vc;
    }
};