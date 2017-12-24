
/*
Leetcode 338. Counting Bits

Related Topics 
Dynamic Programming, Bit Manipulation
Similar Questions 
Number of 1 Bits

Next challenges: Single Number II, Word Break, 4 Keys Keyboard

Test Cases:
0
1
2
3
4
5
20

Runtime: 66 ms
Your runtime beats 73.40 % of cpp submissions.

*/

class Solution {
public:
    vector<int> countBits(int num) {
        // use existing #s
        if(num<1)  return {0};
        vector<int> vc={0,1};
        for(int i=2, j=1, two=1; i<num+1; i++){
            if(i!=two<<1){
                vc.push_back(vc[j]+1);
                j++;
            }else{
                vc.push_back(1);
                j=1;
                two=two<<1;
            }
        }
        return vc;
    }
};
