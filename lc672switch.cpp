
/*

Leetcode 672. Bulb Switcher II

Related Topics: Math 
Similar Questions: Bulb Switcher 

Runtime: 3 ms
You are here! 
Your runtime beats 22.95 % of cpp submissions.

*/

class Solution {
public:
    int flipLights(int n, int m) {
        /*
        n==0 || m==0: return 1;
        n==1 && 0<m: return 2;
        n==2: m==1, 3; 1<m, 4
        2<n: m==1, 4; m==2(0), 7; m==3(1), 8        
        */
        if(m<1)    return 1;
        switch(n){
            case 0: return 0;
                    break;
            case 1: return 2;
                    break;
            case 2: return (1<m) ? 4 : 3;
                    break;
            default: switch (m){
                case 1: return 4;
                        break;
                case 2: return 7;
                        break;
                default: return 8;
                        break;
            }
                    break;
        }
            
    }
};
