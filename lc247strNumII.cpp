
/*
Leetcode 247. Strobogrammatic Number II

Companies 
Google
Related Topics 
Math, Recursion
Similar Questions 
Strobogrammatic NumberStrobogrammatic Number III

Next challenges: Strobogrammatic Number III

Test Cases:
0
1
2
3
5

Runtime: 20 ms
Your runtime beats 65.40 % of cpp submissions.

*/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        //0,1,8,6-9 
        vector<char> vc={'0','1','8'};        
        
        if(n<1) return {};
        else if(n<2)    return {"0","1","8"};
        
        int len, i, j, k, l, r;
        if(n%2!=1)  for( len=4, i=0; i<(n-1)>>1; i++)    len=len*5;
        else    for( len=12, i=0; i<(n-3)>>1; i++) len=len*5;
        string s(n, ' ');
        vector<string> rt(len, s);

        // first column: non-0
        len=len/4;
        for( i=0, j=n-1, r=0; r<rt.size(); ){
            for( k=1; k<3; k++){
                for( l=0; l<len; l++, r++){
                    rt[r][i]=vc[k];
                    rt[r][j]=vc[k];
                }
            }
            for( l=0; l<len; l++, r++){
                rt[r][i]='6';
                rt[r][j]='9';
            }
            for( l=0; l<len; l++, r++){
                rt[r][i]='9';
                rt[r][j]='6';
            }
        }
        
        for( i=1, j=n-2; i<j; i++, j--){
            len=len/5;
            for( r=0; r<rt.size(); ){
                for( k=0; k<3; k++){
                    for( l=0; l<len; l++, r++){
                        rt[r][i]=vc[k];
                        rt[r][j]=vc[k];
                    }
                }
                for( l=0; l<len; l++, r++){
                    rt[r][i]='6';
                    rt[r][j]='9';
                }
                for( l=0; l<len; l++, r++){
                    rt[r][i]='9';
                    rt[r][j]='6';
                }
            }
        }
        
        // middle column: 0,1,8
        if(i==j){
            for( r=0; r<rt.size(); ){
                for( k=0; k<3; k++, r++)    rt[r][i]=vc[k];                
            }
        }
        
        return rt;
    }
};