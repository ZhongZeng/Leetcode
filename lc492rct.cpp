
/*
Leetcode 492. Construct the Rectangle

Next challenges: Paint Fence, Pacific Atlantic Water Flow, Reverse Pairs

Test Cases:
1
100
102

Runtime: 3 ms
Your runtime beats 30.65 % of cpp submissions.

*/

class Solution {
public:
    vector<int> constructRectangle(int area) {
        // O(n^0.5) time
        int w=1,l=area;
        vector<int> vc={area,1};
        while(w<l+1){
            if(area==w*l){
                vc[0]=l;
                vc[1]=w;
            }
            w++;
            l=area/w;
        }
        return vc;
    }
};
