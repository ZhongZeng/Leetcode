
/*
Leetcode 155. Min Stack

Related Topics 
Stack, Design
Similar Questions 
Sliding Window Maximum, Max Stack

Next challenges: Sliding Window MaximumMax Stack

Test Case:
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Runtime: 29 ms
Your runtime beats 30.08 % of cpp submissions.

*/


class MinStack {
public:
    /** initialize your data structure here. */
    
    MinStack() {
        stack<int> vc, mn;
    }
    
    void push(int x) {// Push element x onto stack.
        if(mn.empty()||x<=mn.top()) mn.push(x);
        vc.push(x);
    }
    
    void pop() {// Removes the element on top of the stack.
        if(vc.top()==mn.top())  mn.pop();
        vc.pop();
    }
    
    int top() {
        return vc.top();
    }
    
    int getMin() {
        return mn.top();
    }

protected:
    stack<int> vc, mn;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */