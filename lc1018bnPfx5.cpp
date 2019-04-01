/*
1018. Binary Prefix Divisible By 5

Ranking of Weekly Contest 130	754 / 3984

Test Cases:
[0,1,1]
[0,1,1,1,1,1]
[1,1,1,0,1]
[1,1,0,0,0,1,0,0,1]

Related Topics	Array

Runtime: 16 ms
Memory Usage: 10.7 MB

Your runtime beats 87.50 % of cpp submissions.
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        // A[0] to A[i], from most to leaast significant 
        vector<bool> vc;
        int t, i;
        for( i=0, t=0; i<A.size(); i++){// t<5 
            t=(t<<1)+(A[i]==0?0:1);
            if(4<t) t-=5;
            vc.push_back(t!=0?false:true);
        }
        return vc;
    }
};