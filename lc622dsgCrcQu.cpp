
/*
622. Design Circular Queue

Related Topics:	Design, Queue 
Similiar Questions:	Design Circular Deque

Runtime: 24 ms, faster than 61.31% of C++ online submissions for Design Circular Queue.
*/

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        for(int i=0; i<k+1; i++)  cq.push_back(0);
        b=0;
        e=0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(this->isFull())  return false;
        cq[e]=value;
        if(e==cq.size()-1)  e=0;
        else    e++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(this->isEmpty())    return false;
        if(b==cq.size()-1)  b=0;// drop cq.back()
        else    b++;// drop cq[b]
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return b!=e?cq[b]:-1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(b==e)    return -1;
        else    return e==0?cq.back():cq[e-1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return b==e;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (b==e+1)||(b==0&&e==cq.size()-1);
    }
protected:
    vector<int> cq;
    int b, e;//[b,e) in [0,cq.size()-1] 0equivalent to cq.size()
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
