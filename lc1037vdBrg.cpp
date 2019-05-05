/*
1037. Valid Boomerang

Companies	Google
Related Topics	Math 

Test Cases:
[[1,0],[1,1],[2,0]]
[[0,0],[0,2],[2,1]]
[[1,1],[2,3],[3,2]]
[[1,1],[2,2],[3,3]]
[[0,0],[1,2],[0,1]]
[[0,1],[1,1],[2,2]]
[[1,0],[1,1],[1,0]]
[[0,1],[1,0],[0,1]]
[[0,1],[0,1],[2,1]]

Runtime: 4 ms
Memory Usage: 8.6 MB

*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if(points[1][0]==points[0][0]){
            if(points[1][1]==points[0][1])  return false;// points[0]==points[1] 
            else    return (points[2][0]!=points[0][0]||points[2][1]!=points[0][1])&&points[2][0]!=points[0][0];// points[2]!=points[0] && points[2]&points[0] on diff x-axis 
        }else{
            if(points[2][0]==points[0][0])  return points[2][1]!=points[0][1];// points[0]?=points[2] 
            return 1.0*(points[1][1]-points[0][1])/(points[1][0]-points[0][0])!=1.0*(points[2][1]-points[0][1])/(points[2][0]-points[0][0]);// diff slopes
        }
    }
};