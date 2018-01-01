
/*

Leetcode 365. Water and Jug Problem

Related Topics 
Math

Test Cases:
See at the end of the code. 

Runtime: 0 ms
Your runtime beats 28.69 % of cpp submissions.

*/

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        // 3,5,18-false
        // if x, y, d is true, y-(x-d) can also be measured (assuming all positive)
        if(z==0)    return true;
        if(x+y<z)   return false; 
        
        // x<=y
        if(y<x){
            int t;
            t=y;
            y=x;
            x=t;
        }
        
        // x!=0&&y!=0
        if(y==0)    return false;
        if(x==0)    return z==y;
        
        // z<y&&z<x
        if(y<z) z=z%y; // if true, z must be less then y 
        if(x<z) z=z%x; // if true, z must be less then x 
        
        if(z==0)    return true;
        
        int d=y%x;
        while(d!=0){
            y=x;
            x=d;// d<x            
            if(z%d==0)  return true;
            d=y%x;
        }
        return z==x;
    }
};


/*

Test Cases:
1
0
0
0
2
1
3
5
8
2
6
5
89
76
26
3
5
4
34
5
6
76
89
26
100
113
6
4
4
8
3
5
8
3
6
6
*/
