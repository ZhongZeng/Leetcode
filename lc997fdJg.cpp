
/*
997. Find the Town Judge

Related Topics: Graph, suggested: Array 

Test Cases:
2
[[1,2]]
3
[[1,3],[2,3]]
3
[[1,2],[2,3]]
3
[[1,3],[2,3],[3,1]]

Runtime: 172 ms
Memory Usage: 43.1 MB

*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // if judge exists and can be identified; trust[i] are all different
        vector<int>  ta(N,0), tb(N,0);// trusted by how many people 
        
        for( int i=0; i<trust.size(); i++){
            ta[trust[i][0]-1]+=1;
            tb[trust[i][1]-1]+=1;
        }
        
        for( int i=0; i<tb.size(); i++) if(ta[i]==0&&tb[i]==N-1)  return i+1;// trust no one&&trusted by everyone
        
        return -1;
    }
};