
/*
Leetcode 649. Dota2 Senate

Related Topics 
Greedy
Similar Questions 
Teemo Attacking

Next challenges: Patching Array, 
Find Permutation, Monotone Increasing Digits

Test Cases:
"RD"
"DR"
"RDDR"
"RDDDR"
"RDDDDRR"
"RRDDD"

Runtime: 6 ms
Your runtime beats 83.85 % of cpp submissions.

*/

class Solution {
public:
    string predictPartyVictory(string senate) {
        int r=senate[0]!='D'?1:-1;
        for(string::iterator it=senate.begin()+1; it<senate.end(); it++){
            if(*it!='D'){ // 'R'
                if(0<r) r++;
                r++;
            }else{ // 'D' 
                if(r<0) r--;
                r--;
            }
        }
        
        return 0<r?"Radiant":"Dire";
    }
};
