
/*
Leetcode 341. Flatten Nested List Iterator

Related Topics 
Stack, Design
Similar Questions 
Flatten 2D Vector, Zigzag Iterator, Mini Parser, Array Nesting

Next challenges: Flatten 2D Vector, Zigzag Iterator, Mini Parser

Test Cases:
[[1,1],2,[1,1]]
[1,[4,[6]]]

Runtime: 32 ms
Your runtime beats 3.70 % of cpp submissions.

*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    // O(n) time&space
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        nxtItr( nestedList );
        c=st.size();
    }

    int next() {
        return st[--c];
    }

    bool hasNext() {
        return 0<c;
    }
    
protected:
    vector<int> st;
    int c;
    
    void nxtItr(vector<NestedInteger> &nestedList) {
        NestedInteger ni;
        while(!nestedList.empty()){
            if(nestedList.back().isInteger()){
                st.push_back(nestedList.back().getInteger());
                nestedList.pop_back();
            }else{
                ni=nestedList.back();
                nestedList.pop_back();
                for(vector<NestedInteger>::iterator it=ni.getList().begin(); it!=ni.getList().end(); it++)
                    nestedList.push_back(*it);
                nxtItr( nestedList );
            }
        }
        return ;
    }    
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
