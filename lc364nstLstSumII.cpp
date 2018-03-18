
/*
Leetcode 364. Nested List Weight Sum II

Companies 
LinkedIn
Related Topics 
Depth-first Search 
Similar Questions 
Nested List Weight Sum, Array Nesting

Next challenges: Binary Tree Maximum Path Sum, 
Number of Connected Components in an Undirected Graph, Number of Distinct Islands

Test Cases: 
[[1,1],2,[1,1]]
[1,[4,[6]]]

Runtime: 4 ms
Your runtime beats 39.49 % of cpp submissions.

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
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> vc;
        int sum=0;
        depthSumInverse( nestedList, vc, 0) ;
        for(int i=0; i<vc.size(); i++)  sum+=vc[i]*(vc.size()-i);
        return sum;
    }
    
    void depthSumInverse(vector<NestedInteger>& nestedList, vector<int>& vc, int d) {
        // DFS, post-order traversal; BFS may take too much space 
        for(int i=0; i<nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                while(vc.size()<d+1)    vc.push_back(0);
                vc[d]+=nestedList[i].getInteger();
            }else{
                depthSumInverse( nestedList[i].getList(), vc, d+1);
            }
        }
        return ;
    }
};
