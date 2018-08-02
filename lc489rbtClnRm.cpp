
/*
Leetcode 489. Robot Room Cleaner

Companies  
Google, Facebook 
Related Topics 
Depth-first Search 
Similar Questions 
Walls and Gates

Test Case:
[[1,1,1,1,1,0,1,1],[1,1,1,1,1,0,1,1],[1,0,1,1,1,1,1,1],[0,0,0,1,0,0,0,0],[1,1,1,1,1,1,1,1]]
1
3

Next challenges: Matchsticks to Square, Increasing Subsequences, Contain Virus

Runtime: 4 ms
Your runtime beats 100.00 % of cpp submissions.

*/

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        // DFS, O(n) time; the shape of boarder doesn't matter
        unordered_map<int,unordered_set<int>> um;// x, y, status 
        unordered_set<int> us;
        us.emplace(0);
        um.emplace(0,us);
        
        dfs( 0, 0, 0, um, robot);
        
        return ;
    }
    
    void dfs( int x, int y, int d, unordered_map<int,unordered_set<int>>& um, Robot& robot){
        // d:0-up,1-right,2-down,3-left 
        unordered_map<int,unordered_set<int>>::iterator umi;
        robot.clean();
        //cout<<x<<","<<y<<" ";
        
        switch(d){
            case 0:  break;
            case 1:  robot.turnLeft();
                break;
            case 2:  robot.turnLeft();
                robot.turnLeft();
                break;
            case 3:  robot.turnRight();
                break;
        }
        
        umi=um.find(x);// 0-facing up
        if(umi->second.find(y+1)==umi->second.end()&&robot.move()){// unvisited
            umi->second.emplace(y+1);
            dfs( x, y+1, 0, um, robot);
        }
        
        robot.turnRight();// 1-facing right
        umi=um.find(x+1);
        if(umi!=um.end()){
            if(umi->second.find(y)==umi->second.end()&&robot.move()){
                umi->second.emplace(y);
                dfs( x+1, y, 1, um, robot);
            }
        }else{
            if(robot.move()){
                unordered_set<int> us;
                us.emplace(y);
                um.emplace(x+1, us);
                dfs( x+1, y, 1, um, robot);
            }
        }
        
        robot.turnRight();// 2-facing down
        umi=um.find(x);
        if(umi->second.find(y-1)==umi->second.end()&&robot.move()){// unvisited
            umi->second.emplace(y-1);
            dfs( x, y-1, 2, um, robot);
        }
        
        robot.turnRight();// 3-facing left
        umi=um.find(x-1);
        if(umi!=um.end()){
            if(umi->second.find(y)==umi->second.end()&&robot.move()){
                umi->second.emplace(y);
                dfs( x-1, y, 3, um, robot);
            }
        }else{
            if(robot.move()){
                unordered_set<int> us;
                us.emplace(y);
                um.emplace(x-1, us);
                dfs( x-1, y, 3, um, robot);
            }
        }
        
        // facing left now; return to previous position & facing original (this is tricky)
        switch(d){
            case 0: robot.turnLeft();
                break;
            case 1: break;
            case 2: robot.turnRight();
                break;
            case 3: robot.turnRight();
                robot.turnRight();
                break;
        }
        robot.move();
        robot.turnLeft();
        robot.turnLeft();        
        
        return ;
    }
};
