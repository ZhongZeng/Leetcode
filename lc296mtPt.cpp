
/*
Leetcode 296. Best Meeting Point

Companies 
Twitter
Related Topics 
Math, Sort
Similar Questions 
Shortest Distance from All Buildings, Minimum Moves to Equal Array Elements II

Next challenges: Shortest Distance from All Buildings, 
Minimum Moves to Equal Array Elements II

Test Case:
[[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]

Runtime: 6 ms
Your runtime beats 25.64 % of cpp submissions.

*/

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        // find all home spots, median of x and y respectively; O(n*m) time
        int mid=0, i, j, c, x, y, sum=0;
        vector<pair<int,int>> vc;
        for( i=0; i<grid.size(); i++){
            for( j=0; j<grid[0].size(); j++){
                if(grid[i][j]!=0){
                    vc.push_back(make_pair(i,j));
                    mid++;
                }
            }
        }

        mid=(mid>>1)+1;
        // find median point (x,y) 
        for( i=0, c=0; i<grid.size(); i++){
            for( j=0; j<grid[0].size(); j++){
                if(grid[i][j]!=0)   c++;
                if(c==mid)  break;
            }
            if(c==mid)  break;
        }
        x=i;
        
        for( j=0, c=0; j<grid[0].size(); j++){
            for(int i=0; i<grid.size(); i++){
                if(grid[i][j]!=0)   c++;
                if(c==mid)  break;
            }
            if(c==mid)  break;
        }
        y=j;

        // calculate distance 
        for( i=0; i<vc.size(); i++){
            sum+=(vc[i].first<x?x-vc[i].first:vc[i].first-x)+(vc[i].second<y?y-vc[i].second:vc[i].second-y);
        }
        
        return sum;
    }
};