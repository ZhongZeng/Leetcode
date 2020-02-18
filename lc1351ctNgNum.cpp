/*
1351. Count Negative Numbers in a Sorted Matrix

Weekly Contest 176
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (5)	Q3 (5)	Q4 (6)
4751 / 8106	zhongzeng 	3	0:07:51	 0:07:51	

Company	Amazon
Related Topic	Array, Binary Search

Test Cases:
[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
[[3,2],[1,0]]

Runtime: 20 ms, faster than 65.26% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.

Next challenges:
Maximum Average Subarray II, Height Checker, Product of the Last K Numbers
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sum=0;
        for( int i=0; i<grid.size(); i++)   sum+=countNegativeNum(grid[i]);
        return sum;
    }
    
protected:
    int countNegativeNum(vector<int> & vc){// vc is non-inscreasing
        int b=-1, mid, e=vc.size();// 0<=vc[b], vc[e]<0
        
        while(1<e-b){
            mid=b+(e-b)/2;
            if(mid<0||vc[mid]<0)   e=mid;// imaginary 0<=vc[-1]
            else    b=mid;
        }
        
        return vc.size()-e;
    }
};