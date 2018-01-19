
/*
Leetcode 335. Self Crossing

Related Topics 
Math

Test Cases:
[2,1,1,2]
[1,2,3,4]
[1,1,1,1]
[12,3,4,5,3,3]
[3,3,4,2,2]
[1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1]

Runtime: 2 ms
Your runtime beats 28.45 % of cpp submissions.

*/

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        // O(n) time, O(1) space
        // You are given an array x of n positive numbers.
        // my guess is if it crosses @i, it must cross i-3 or i-5
        // draw it!
        if(x.size()<4)  return false;
        
        int i=0;
        if(!(x[i]<x[i+2]||x[i+3]<x[i+1]))   return true;//x[i+2]<=x[i]&&x[i+1]<=x[i+3]
        
        i=3;
        while( ++i<x.size() ){// 4<=i
            if(x[i-1]<=x[i-3]&&(x[i-2]<=x[i]||
                        (x[i-2]-x[i-4]<=x[i]&&x[i-4]<=x[i-2]&&x[i-3]-x[i-5]<=x[i-1]))){
                // cross i-3 || cross i-5
                // cout<<i<<" "<<x[i]<<endl;
                return true;                
            }
        }
        
        return false;
    }
};
