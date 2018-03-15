
/*
Leetcode 346. Moving Average from Data Stream

Companies 
Google
Related Topics 
Design, Queue 

Next challenges: Implement Queue using Stacks, 
Peeking Iterator, All O`one Data Structure

Test Case:
["MovingAverage","next","next","next","next"]
[[3],[1],[10],[3],[5]]

Runtime: 39 ms
Your runtime beats 34.71 % of cpp submissions.

*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz=size;
        sum=0;
    }
    
    double next(int val) {
        if(qu.size()<sz){
            sum+=val;
            qu.push(val);
            return sum*1.0/qu.size();
        }else{
            sum-=qu.front();
            sum+=val;
            qu.pop();
            qu.push(val);
            return sum*1.0/sz;
        }
    }
    
    queue<int> qu;
    int sz, sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
