

/*
Leetcode 593. Valid Square

Tag: Math
Next challenges: (E) Happy Number(H) Basic Calculator(E) Minimum Moves to Equal Array Elements

You are here! 
Your runtime beats 24.44 % of cpp submissions.	6 ms

Test Cases:
[0,0]
[0,0]
[0,0]
[0,0]

[0,0]
[1,1]
[1,0]
[0,1]

[1,0]
[0,1]
[0,-1]
[-1,0]

*/



class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // note that the square can be in any angel
        // the sufficient and necessary codition is that 
        // each node has two other nodes at the same distance and the diagonal is sqrt(2) times length
        // combination of 2 out of 4 is 6
        vector<int> vs;
        vs.push_back(edgeLenSq(p1,p2)); // 0
        vs.push_back(edgeLenSq(p1,p3)); // 1
        vs.push_back(edgeLenSq(p1,p4)); // 2
        vs.push_back(edgeLenSq(p2,p3)); // 3
        vs.push_back(edgeLenSq(p2,p4)); // 4
        vs.push_back(edgeLenSq(p3,p4)); // 5
        for(int num:vs){ 
            if(num==0) return false;
            // cout<<num<<endl;
        }
        
        if(vs[0]==vs[1]){ // p1 and p4 are NOT adjacent
            // cout<<"test1"<<endl;
            return isSquare(vs[0], vs[1], vs[4], vs[5], vs[2], vs[3]);
        }else if(vs[0]==vs[2]){ // p1 and p3 are NOT adjacent
            // cout<<"test2"<<endl;
            return isSquare(vs[0], vs[3], vs[5], vs[2], vs[1], vs[4]);
        }else{ // p1 and p2 are NOT adjacent
            // cout<<"test3"<<endl;
            return isSquare(vs[1], vs[3], vs[4], vs[2], vs[0], vs[5]);
        }
        
    }
    
protected:
    int isSquare(int & a1, int & a2, int & a3, int & a4, int & a5, int & a6){
        // sequence: 4 lengths, then 2 diagonals
        // cout<<(a1==a2)<<endl;
        return (a1==a2 && a2==a3 && a3==a4 && a1*2==a5 && a5==a6);
    }
    
    int edgeLenSq(vector<int> & p1, vector<int> & p2){
        // return the square of the length b/t two points
        // cout<<(p1[0]-p2[0])*(p1[0]-p2[0])<<" "<<(p1[1]-p2[1])*(p1[1]-p2[1])<<endl;
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    
};

