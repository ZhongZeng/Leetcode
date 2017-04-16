
/*
Leetcode 223 findInterval(A, C, E, G)
You are here! 
Your runtime beats 22.91% of cpp submissions. 22 ms
*/


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        /* rec1: (A-C, B-D), rec2: (E-G, F-H)
        Sum of two areas - overlapping area
        cout<<findInsection(A, C, E, G)<<endl;
        cout<<findInsection(B, D, F, H)<<endl;
        */
        return (D-B)*(C-A)+(H-F)*(G-E)-findInsection(A, C, E, G)*findInsection(B, D, F, H);
    }
    
    int findInsection(int A, int C, int E, int G){
    //find the interval of segment [A, C] and [E, G]
        if(G<A||C<E) return 0; 
        else return min(C, G)-max(A,E);
    }
    
};
