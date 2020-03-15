/*
1381. Design a Stack With Increment Operation

Company	endurance
Related Topics	Stack, Design 

Test Case:
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]

Runtime: 36 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 19.9 MB
*/

class CustomStack {
public:
    // stack, design 
    CustomStack(int maxSize) {
        max_size=maxSize;
    }
    
    void push(int x) {
        if(ele.size()<max_size){
            ele.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        if(0<ele.size()){
            int inc_val=inc.back(), val=ele.back();
            inc.pop_back();
            if(0<inc.size())    inc.back()+=inc_val;
            ele.pop_back();
            return val+inc_val;
        }else{
            return -1;
        }
    }
    
    void increment(int k, int val) {
        if(0<ele.size()){
            inc[(k<inc.size()?k:inc.size())-1]+=val;
        }
    }
    
protected:
    int max_size;
    vector<int> ele, inc;// inc[i]: ele[j] for j<=i needs to be increased by sum of inc[i,inc.size())
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */