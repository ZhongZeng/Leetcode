

/*
Leetcode 232. Implement Queue using Stacks

Companies 
Microsoft, Bloomberg 
Related Topics 
Stack, Design 
Similar Questions 
Implement Stack using Queues

Next challenges: Implement Stack using Queues

Test Case:
["MyQueue","empty"]
[[],[]]

Runtime: 3 ms
Your runtime beats 80.44 % of cpp submissions.

*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    // on average O(1) for all operations; pop() & peek() worst O(n) 
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
        return ;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
        int rt=b.top();
        b.pop();
        return rt;
    }
    
    /** Get the front element. */
    int peek() {
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty()&&b.empty();
    }
    
    stack<int> a, b;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
