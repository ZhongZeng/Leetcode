
/*
Leetcode 573. Squirrel Simulation

Companies 
Square 
Related Topics 
Math

Next challenges: Basic Calculator, 4 Keys Keyboard, Cracking the Safe

Test Cases:
5
7
[2,2]
[4,4]
[[3,0], [2,5]]

Runtime: 21 ms
Your runtime beats 28.05 % of cpp submissions.

*/

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        // only need to determine 1st nut 
        int md=dist(nuts[0], squirrel)-dist(nuts[0], tree), sum=0, d, t;
        
        for(int i=0; i<nuts.size(); i++){
            d=dist(tree, nuts[i]);
            sum+=2*d;
            t=dist(nuts[i], squirrel)-dist(nuts[i], tree);
            if(t<md)    md=t;
        }    
        
        return sum+md;
    }

protected:    
    int dist(vector<int>& v1, vector<int>& v2){
        return (v1[0]<v2[0]?v2[0]-v1[0]:v1[0]-v2[0])+(v1[1]<v2[1]?v2[1]-v1[1]:v1[1]-v2[1]);
    }
};
