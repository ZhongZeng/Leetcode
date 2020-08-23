/*
1563. Stone Game V

Hard
Related Topics	Dynamic Programming
Similar Questions	Stone Game, Stone Game II, Stone Game III, Stone Game IV

Tetst Cases:
[1,1,2]
[6,2,3,4,5,5]
[7,7,7,7,7,7,7]
[4]

Runtime: 364 ms	Your runtime beats 37.50 % of cpp submissions.
Memory Usage: 23.5 MB

https://leetcode.com/problems/stone-game-v/discuss/807101/C++-DP-Memorization
*/

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        // minmax; DP+memorization; stoneValue in [1,10**6]
        vector<int> sums={0};// sum of [0,i)
        vector<vector<int>> scores(stoneValue.size()+1, vector<int> (stoneValue.size()+1, -1));
        
        for( int i=0; i<stoneValue.size(); i++) sums.push_back(sums.back()+stoneValue[i]);
        
        return maxScore( sums, scores, 0, stoneValue.size());
    }
    
protected:
    int maxScore(vector<int> & sums, vector<vector<int>> & scores, int b, int e){// [b,e)
        if(b==e-1)  return 0;
        if(scores[b][e]!=-1)    return scores[b][e];
        int mx=0;
        for( int i=b+1; i<=e; i++){// [b,i) v.s. [i,e)
            int left=sums[i]-sums[b], right=sums[e]-sums[i], t;
            if(left<right){
                t=left+maxScore( sums, scores, b, i);
            }else if(right<left){
                t=right+maxScore( sums, scores, i, e);
            }else{
                int left_score=left+maxScore( sums, scores, b, i), right_score=right+maxScore( sums, scores, i, e);
                t=left_score<right_score?right_score:left_score;
            }
            mx=mx<t?t:mx;
        }
        scores[b][e]=mx;
        return mx;
    }
};