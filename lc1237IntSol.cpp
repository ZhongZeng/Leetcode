/*
1237. Find Positive Integer Solution for a Given Equation

Companies	Google
Related Topics	Math, Binary Search 

Test Cases:
1
5
2
5

Runtime: 4 ms
Memory Usage: 8.4 MB
Your runtime beats 78.59 % of cpp submissions.
*/
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        // O(n*log(n)) time, O(1) space; binary search; z in [1,100], x,y in [1,1000]
        vector<vector<int>> rt;// rt.size()<=2
        
        for( int i=1; i<1001; i++){
            int b=1, e=1001, mid;// z in [customFunction(i,b), customFunction(i,e))
            while(1<e-b){
                mid=b+(e-b)/2;
                if(z<customfunction.f(i,mid)) e=mid;
                else    b=mid;
            }
            if(customfunction.f(i,b)==z)  rt.push_back({i,b});
        }
        
        return rt;
    }
};