/*
1041. Robot Bounded In Circle

Related Topics	Math 

Test Cases:
"GGLLGG"
"GG"
"GL"

Runtime: 0 ms
Memory Usage: 8.3 MB

Next challenges: Poor Pigs, Prime Palindrome, Broken Calculator

After 4 repetitions, the robot will turn back to its original direction and move x0 in x and y0 in y. 
If x0 or y0 is not 0, the robot will continue to move x0 in x and y0 in y. Thus, x0==0&&y0==0 is necessary. 
It's also sufficient based the problem description. 
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        // O(n) time; a set of instruction moves the robot the same movement/direction
        int d=0, x=0, y=0;
        
        for( int j=0; j<4; j++) move(x,y,d,instructions);
        
        return x==0&&y==0;// d==0 guranteed 
    }
    
protected:
    void move( int& x, int& y, int& d, string& instructions){
        for( int i=0; i<instructions.size(); i++){
            if(instructions[i]=='G'){
                if(d==0)    y++;
                else if(d==1)   x++;
                else if(d==2)   y--;
                else    x--;
            }else if(instructions[i]=='L'){
                d=(d!=0)?d-1:3;
            }else if(instructions[i]=='R'){
                d=(d!=3)?d+1:0;
            }
        }
        return ;
    }
};