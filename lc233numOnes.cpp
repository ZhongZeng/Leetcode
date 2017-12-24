
/*

Leetcode 233. Number of Digit One

Related Topics 
Math
Similar Questions 
Factorial Trailing Zeroes

Next challenges: Valid Number, Largest Divisible Subset, Fraction Addition and Subtraction

Test Cases:
0
1
56
156
999
43678

Runtime: 0 ms
Your runtime beats 24.18 % of cpp submissions.

*/

class Solution {
public:
    int countDigitOne(int n) {
        // use the same logic from 1s in binary expression; DP
        // count 1 by digits
        // O(lg(n)) time&space
        if(n<1) return 0;
        
        int t, i, sum, num;
        vector<int> vs={0,1}, dg={n%10};
        
        for(i=10, t=n/10, sum=1; t!=0; t/=10, i*=10){
            dg.push_back(t%10);
            sum=sum*10+i;
            vs.push_back(sum);
        }
        
        // for(auto ele:vs)    cout<<ele<<" ";
        // 0 1 20 300 4000 50000
        // 0 1 99 999 9999 (coresponding to)
         
        
        for(t=0, i=1, sum=0, num=0; t!=dg.size(); t++, i=i*10){
            // DP:  till that number
            // t: 10s; i: 10...; sum: 1s; num: number
            if(dg[t]!=0){
                if(dg[t]!=1){// dg[t]!=1&&dg[t]!=0
                    // sum = dg[t]...: 1s on all previous digits
                    sum+=i; // 1: 1s on this digit
                    sum+=vs[t]*dg[t]; // 0 thru dg[t]-1...: 1s on all previous digits
                }else{// dg[t]==1
                    // sum = dg[t]...: 1s on all previous digits
                    sum+=num+1+vs[t]; // 1:1s on that dighit + 1s on all previous digits less than 1...
                }
            }
            num+=dg[t]*i;
        }
        
        return sum;
    }
};
