/*
1404. Number of Steps to Reduce a Number in Binary Representation to One

Companies	Amazon
Related Topics	String, Bit Manipulation 

Test Cases:
"11001"
"1101"
"10"
"1"
"0"

Runtime: 4 ms	Your runtime beats 75.25 % of cpp submissions.
Memory Usage: 6.5 MB

https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/discuss/566102/C%2B%2B-O(n)-Time-Remove-Trailing-0s-when-Adding-1
*/

class Solution {
public:
    int numSteps(string s) {
        // easy, O(n) time 
        int step=0;
        
        for( ; 1<s.size(); step++ ){
            if(s.back()=='0'){
                s.pop_back();
            }else{
                for( ; 0<s.size()&&s.back()=='1'; step++){// step++ for pop 0 at back 
                    s.pop_back();
                }
                if(0<s.size())  s.back()='1';
                else    s='1';// return step+1
            }
        }
        
        return step;
    }
};