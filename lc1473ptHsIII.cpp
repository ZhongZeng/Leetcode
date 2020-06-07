/*
1473. Paint House III

Hard
Companies	Paypal
Related Topics	Dynamic Programming

Test Cases:
[0,1,0,0,1,2,0,0,2,1]
[[4,5,2,6],[8,3,2,9],[6,7,3,1],[10,10,2,7],[6,5,2,4],[4,4,3,9],[9,8,3,5],[7,9,10,3],[8,5,9,10],[10,7,4,6]]
10
4
6
[0,0,0,0,0]
[[1,10],[10,1],[10,1],[1,10],[5,1]]
5
2
3
[0,2,1,2,0]
[[1,10],[10,1],[10,1],[1,10],[5,1]]
5
2
3
[0,0,0,0,0]
[[1,10],[10,1],[1,10],[10,1],[1,10]]
5
2
5
[3,1,2,3]
[[1,1,1],[1,1,1],[1,1,1],[1,1,1]]
4
3
3

Runtime: 32 ms	our runtime beats 100.00 % of cpp submissions.
Memory Usage: 15.8 MB

https://leetcode.com/problems/paint-house-iii/discuss/676219/C++-DP-O(m*target*n)-time
*/

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // DP; O(m*target*n) time; m houses, n colors (1-indexed)
        int mn=-1;
        vector<int> neighbor(target+1,-1);
        neighbor[0]=0;
        vector<vector<int>> costs0( n, neighbor);// costs0[color][target]: house m w/ color & target neighborhoods
        
        for( int i=0; i<m; i++){// O(m) iterations
            vector<vector<int>> costs1(n, vector<int> (target+1,-1));
            for( int j=1; j<=target; j++){// target is j; O(target) iterations
                int color1=-1, color2=-1, cost1=-1, cost2=-1;// find color1, color2 w/ min cost1, cost2 for target==j-1
                for( int k=1; k<=n; k++){// O(k) iterations
                    if(costs0[k-1][j-1]==-1)    continue;
                    if(cost1==-1||costs0[k-1][j-1]<cost1){
                        color2=color1;
                        color1=k;
                        cost2=cost1;
                        cost1=costs0[k-1][j-1];
                    }else if(color2==-1||costs0[k-1][j-1]<cost2){
                        color2=k;
                        cost2=costs0[k-1][j-1];
                    }
                }
                
                if(houses[i]==0){
                    for( int k=1; k<=n; k++){// color of house[i] is k; O(k) iterations
                        int cost0=color1!=k?cost1:cost2;// color of house[i-1] == color1 or color2
                        if(cost0==-1||(costs0[k-1][j]!=-1&&costs0[k-1][j]<cost0))   cost0=costs0[k-1][j];// color of house[i-1] == house[i] 
                        if(cost0!=-1)    costs1[k-1][j]=cost[i][k-1]+cost0;
                    }
                }else{
                    int k=houses[i], cost0=color1!=k?cost1:cost2;// color of house[i-1] == color1 or color2
                    if(cost0==-1||(costs0[k-1][j]!=-1&&costs0[k-1][j]<cost0))   cost0=costs0[k-1][j];// color of house[i-1] == house[i] 
                    if(cost0!=-1)    costs1[k-1][j]=cost0;// already painted
                }
            }
            costs0=costs1;
        }
        
        for( int i=0; i<n; i++)
            if(costs0[i].back()!=-1&&(mn==-1||costs0[i].back()<mn)) mn=costs0[i].back();
        
        return mn;
    }
};