
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

Runtime: 16 ms, faster than 47.70% of C++ online submissions for Divide Two Integers.

*/

// O(1) space is possible, if we calculate largest vc first and use >>1 (divided by 2) each time,
// or just use <<1 (multiplied by the exponential of 2), in trade of of linear time 

class Solution {
public:
    int divide(int dividend, int divisor) {
        // O(n) time&space, n=log(dividend/divisor)<=32, solution without long 
        // -7,-3: 2; -7,3:-2; 7,-3:-2
        if(dividend==INT_MIN&&divisor==-1)   return INT_MAX;// the only result overflow
        
        // use negative to avoid overflow 
        if(0<dividend){
            if(0<divisor)   return divideNegative(-dividend,-divisor);
            else    return -divideNegative(-dividend,divisor);
        }else{
            if(0<divisor)   return -divideNegative(dividend,-divisor);
            else    return divideNegative(dividend,divisor);
        }
        
        return 0;
    }
    
protected:    
    int divideNegative(int dividend, int divisor){// both input are non-positive 
        int q=0;
        vector<int> vb={-1}, vc={divisor};
        
        // generate vector of int 
        while(dividend-vc.back()<=vc.back()){// avoid overflow 
            vb.push_back(vb.back()+vb.back());
            vc.push_back(vc.back()+vc.back());
        }
        
        // binary conversion 
        for( int i=vc.size()-1; -1<i&&dividend<0; i--){
            if(dividend<=vc[i]){
                dividend-=vc[i];
                q+=vb[i];
            }
        }
        
        return -q;        
    }
};

/*
// Runtime: 32 ms	Your runtime beats 7.76 % of cpp submissions.
// Runtime: 25 ms	Your runtime beats 18.48 % of cpp submissions.
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
*/