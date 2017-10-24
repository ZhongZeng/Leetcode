
/*
Leetcode 633. Sum of Square Numbers

Related Topics 
Math 
Similar Questions 
Valid Perfect Square 

Next challenges: Valid Perfect Square

Test Cases:
4
5
8
97
99
100000

Runtime: 3 ms
You are here! 
Your runtime beats 65.74 % of cpp submissions.

*/

#include<vector>
#include<iostream>

using namespace std; 

class Solution {
public:
    bool judgeSquareSum(int c) {
        // 2-point method; O(n) time
        // c-2*a*b=(a-b)*(a-b) 
        
        if(c<3) return true; // 1=1+0, 2=1+1
        int a=0, b=squrt(c), d; // [a,b]; b=c/2 gives the wrong answer
        while( a-1!=b ){
            d = a*a+b*b;
            if( d<c ){
                a++;
            }else if( c<d ){
                b--;
            }else{
                return true;
            }              
            cout<<a<<' '<<b<<endl;
        }
        
        return false;
    }
    
protected:
    int squrt(int s){
        int lo=0, hi=s/2+1, mid ;// [lo, hi)
        while( lo!=hi-1 ){
            mid = lo+(hi-lo)/2;
            if( s/mid<mid ){
                hi = mid;
            }else{
                lo = mid;
            }            
        }
        return lo;
    }
    
};

int main(){
	Solution s;
	cout << s.judgeSquareSum( 100000 ) <<endl;
	
	return 0;
}

