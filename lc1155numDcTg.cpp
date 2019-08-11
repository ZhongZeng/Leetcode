/*
1155. Number of Dice Rolls With Target Sum

Tag: Dynamic Programming (suggested)

Test Cases:
1
6
3
2
6
7
2
5
10
1
2
3
30
30
500

Runtime: 24 ms
Memory Usage: 14.2 MB
*/

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        // DP, O(d*f*target) time, O(target) space; Knapsack backpack problem 
        vector<int> vc(target+1,0);// ways=vc[target] 
        vc[0]=1;// 1 way for target==0
        for( int i=1; i<=d; i++){
            vector<int> vd={0};
            for( int j=1; j<=target; j++){// d==i && target==j 
                int ways=0;// no way for target==0 when d>=1
                for( int k=1; k<=f; k++){
                    if(-1<j-k)  ways=(1000000007<=ways+vc[j-k])?ways+vc[j-k]-1000000007:ways+vc[j-k];
                }
                vd.push_back(ways);
            }
            //for(auto e:vd)  cout<<e<<" ";   cout<<endl;
            vc=vd;
        }
        return vc.back();
    }
};