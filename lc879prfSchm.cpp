
/*
Leetcode 879. Profitable Schemes

Companies  
Google 
Related Topics 
Dynamic Programming 

Test Cases:
5
3
[2,2]
[2,3]
10
5
[2,3,5]
[6,7,8]

Next challenges: Guess Number Higher or Lower II, Super Washing Machines, Palindromic Substrings

Runtime: 52 ms
24 ms, 100% 

*/

class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        // DP on G&P; O(G*P*n) time, O(G*P) space 
        // 1 <= G <= 100; 0 <= P <= 100
        vector<int> vc(G+1,0);
        vector<vector<int>> vv(P+1,vc);// # ways of exact G people&p profit 
        for( int j=0; j<vv[0].size(); j++)  vv[0][j]=1;
        
        int g, p, sum=0;
        
        for( int i=0; i<group.size(); i++){
            for( int j=vv.size()-1; -1<j; j--){// P 
                for( int k=vv[0].size()-1; -1<k; k--){// G 
                    if(vv[j][k]!=0){
                        p=j+profit[i]<P?j+profit[i]:P;
                        g=k+group[i];
                        if(g<=G)    vv[p][g]=(vv[p][g]+vv[j][k])%1000000007;                        
                    }
                }
            }
        }
        
        return vv.back().back();
    }
};
