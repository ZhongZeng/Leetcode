/*
1033. Moving Stones Until Consecutive

Companies	Facebook
Related Topics	Brainteaser

Next challenges: Remove Duplicate Letters, LFU Cache, Three Equal Parts

Test Cases:
1
3
5
1
2
5
4
3
2
3
5
1

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 8.4 MB	Your memory usage beats 60.41 % of cpp submissions.

Sort a, b, c in ascending order such that a<b<c. 
To make maximium number of moves:
First, move a towards b by 1 (increase a by 1) in each step until a==b-1. 
Second, move c towards b by 1 (decrease c by 1) in each step until c==b+1. 
Thus, the maximium number of moves is (b-a-1)+(c-b-1)=c-a-2. 
To make minium number of moves:
Scenario 1: a==b-1==c-2. 0 move is required. 
Scenario 2: there are two adjacent stones that are 1 away from each other (excluding scenario 1)(Ex. a==b-1). 1 move required (Ex. move c to b+1).
Scenario 3: there are two adjacent stones that are 2 away from each other. 1 move is required (Ex. a==b-2). 1 move required (Ex. move c to b-1).
Scenario 4: all scenarios other than 1, 2, and 3. 2 move required. Move a to b-1, and move c to b+1. 

*/

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        // min=0||1||2, max=z-x-2
        vector<int> rt;
        
        // bubble sort a, b, c 
        if(b<a) swap2( b, a);
        if(c<b) swap2( c, b);// c is max in {a,b,c}
        if(b<a) swap2( b, a);// b is max in {a,b}
        
        if(a==b-1&&a==c-2)  rt.push_back(0);
        else if(a==b-2||a==b-1||b==c-2||b==c-1) rt.push_back(1);
        else    rt.push_back(2);
        
        rt.push_back(c-a-2);
        
        return rt;
    }
    
protected: 
    void swap2(int& a, int& b){
        int t=a;
        a=b;
        b=t;
        return ;
    }
};