
/*
Leetcode 223 findInterval(A, C, E, G)
You are here! 
Your runtime beats 22.91% of cpp submissions. 22 ms
Your runtime beats 53.82% of cpp submissions. 16 ms
*/


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        /* rec1: (A-C, B-D), rec2: (E-G, F-H)
        Sum of two areas - overlapping area
        cout<<findInsection(A, C, E, G)<<endl;
        cout<<findInsection(B, D, F, H)<<endl;
        */
        return (D-B)*(C-A)+(H-F)*(G-E)-findIntersection(A, C, E, G)*findIntersection(B, D, F, H);
    }
    
    int findIntersection(int A, int C, int E, int G){
    //find the intersection of segment [A, C] and [E, G]
        if(G<A||C<E) return 0; 
        else return min(C, G)-max(A,E);
    }
    
};
