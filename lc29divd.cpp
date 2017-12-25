


/*
Leetcode 29. Divide Two Integers

Related Topics 
Math, Binary Search

Next challenges: Roman to Integer, 
Find Minimum in Rotated Sorted Array II, Super Pow

Test Cases:
23424
59
0
23
3
3
-1
1
4
-1
5
-3
-2147483648
-1
-2147483648
1
-2147483648
2
2147483647
3

Runtime: 32 ms
Your runtime beats 7.76 % of cpp submissions.
Runtime: 25 ms
Your runtime beats 18.48 % of cpp submissions.

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // dividend/divisor
        // [-2147483648,2147483647]
        // O(log(divided)/log(divisor)) time/space
        // lots of overflow problem 
        if(dividend==-2147483648){
            if(divisor==-1) return 2147483647;
            else if(divisor==1) return -2147483648;
        }  
        
        if(0<dividend){
            if(0<divisor){
                return divide(0-dividend,0-divisor);
            }else{
                return 0-divide(0-dividend,divisor);
            }
        }else{
            if(0<divisor){
                return 0-divide(dividend,0-divisor);
            }
        }
        
        int d=0, t=1, num=divisor, i;
        vector<int> vc, vt;
        if(dividend==num)   return t;
        while(dividend<num){
            vc.push_back(num);
            vt.push_back(t);
            if(num<-1073741824) break;
            num+=num;
            t=t+t;
            if(dividend==num)   return t;
        }
        
        num=dividend;
        for(i=vc.size()-1; -1<i; i--){
            if(num<vc[i]){
                num-=vc[i];
                d+=vt[i];
            }else if(num==vc[i]){
                d+=vt[i];
                return d;
            }
            //cout<<vc[i]<<" ";
        }
        
        return d;
    }
};
