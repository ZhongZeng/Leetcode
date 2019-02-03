
/*
985. Sum of Even Numbers After Queries

Ranking of Weekly Contest 122:	1268 / 3482

Related Topics:	Array 

Test Cases:
[1,2,3,4]
[[1,0],[-3,1],[-4,0],[2,3]]

Runtime: 96 ms
*/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> rt;
        int ans=0;
        
        for(int i=0; i<A.size(); i++)   ans+=A[i]%2==0?A[i]:0;
        
        for( int i=0, p; i<queries.size(); i++){
            p=queries[i][1];
            if(A[p]%2==0)   ans+=(queries[i][0]%2==0)?queries[i][0]:(-A[p]);
            else    ans+=(queries[i][0]%2==0)?0:A[p]+queries[i][0];
            
            A[p]+=queries[i][0];
            rt.push_back(ans);
        }
        
        return rt;
    }
};
