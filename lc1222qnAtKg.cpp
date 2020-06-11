/*
1222. Queens That Can Attack the King

Medium
Companies	Media.net
Related Topics	Array

Test Cases:
[[1,3],[0,7],[5,1],[2,5],[7,2],[1,2],[6,7],[3,3],[5,5],[1,5],[5,0],[0,4],[4,1],[1,1],[3,2],[2,3],[4,2],[1,0],[6,5],[2,7],[3,1],[4,3],[3,4]]
[0,2]
[[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]]
[0,0]

Runtime: 12 ms, faster than 28.53% of C++ online submissions for Queens That Can Attack the King.
Memory Usage: 10.9 MB, less than 65.72% of C++ online submissions for Queens That Can Attack the King.
Next challenges: Previous Permutation With One Swap, Minimum Time Visiting All Points, Rank Teams by Votes
*/

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // math; at most 8 queens
        vector<vector<int>> aq(8,vector<int> {-1,-1}), rt;
        
        for( int i=0; i<queens.size(); i++){
            int d=-1;
            if(queens[i][0]==king[0])    d=queens[i][1]<king[1]?0:1;
            else if(queens[i][1]==king[1])  d=queens[i][0]<king[0]?2:3;
            else if(queens[i][0]+queens[i][1]==king[0]+king[1])
                d=queens[i][0]<king[0]?4:5;
            else if(queens[i][0]-queens[i][1]==king[0]-king[1])
                d=queens[i][0]<king[0]?6:7;
            if(d!=-1 && ( aq[d][0]==-1||abs(queens[i][0]-king[0])+abs(queens[i][1]-king[1])
                         <abs(aq[d][0]-king[0])+abs(aq[d][1]-king[1]) ) )
                aq[d]=queens[i];
        }
        
        for( int i=0; i<aq.size(); i++)
            if(aq[i][0]!=-1)    rt.push_back(aq[i]);
        
        return rt;
    }
};