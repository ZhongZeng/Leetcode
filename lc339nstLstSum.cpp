
/*
Leetcode 339. Nested List Weight Sum

Companies 
LinkedIn
Related Topics 
Depth-first Search (Suggested: recursion)
Similar Questions 
Nested List Weight Sum IIArray NestingEmployee Importance

Next challenges: Nested List Weight Sum II

Test Case:
[[1,1],2,[1,1]]

Runtime: 3 ms
Your runtime beats 98.64 % of cpp submissions.

*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum=depthSum( nestedList, 1);
        
        return sum;
    }
    
    int depthSum(vector<NestedInteger>& nestedList, int dp) {
        int sum=0;
        for(int i=0; i<nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                sum+=nestedList[i].getInteger()*dp;
            }else{
                sum+=depthSum(nestedList[i].getList(), dp+1);
            }
        }
        return sum;
    }    
};
