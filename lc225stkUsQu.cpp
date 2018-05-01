

/*
Leetcode 225. Implement Stack using Queues

Companies 
Bloomberg 
Related Topics 
Stack, Design 
Similar Questions 
Implement Queue using Stacks

Next challenges: Design Hit Counter, Design Excel Sum Formula, Design Search Autocomplete System

Test Cases:
["MyStack","empty"]
[[],[]]
["MyStack","push","pop","empty"]
[[],[1],[],[]]

Runtime: 4 ms
Your runtime beats 14.84 % of cpp submissions.

*/

class MyStack {
public:
    /** Initialize your data structure here. */
    // leetcode 232. stack->queue is easier, since stack changes sequence. 
    // O(1) push&top, O(n) pop
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        t=x;
        qu.push(x);
        return ;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int rt;
        if(qu.size()==1){
            rt=qu.front();
            qu.pop();
        }else{
            for(int i=0; i<qu.size()-2; i++){
                qu.push(qu.front());
                qu.pop();
            }            
            t=qu.front();
            qu.push(qu.front());
            qu.pop();
            rt=qu.front();
            qu.pop();            
        }
        return rt;
    }
    
    /** Get the top element. */
    int top() {
        return t;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return qu.empty();
    }
    
    queue<int> qu;
    int t;// if using .back(), no need for t
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
