
/* 
Leetcode # 50
Brute force method will run exceeding time limit. 
Represent an integer as 2-bit wise. 
The algo is O(lg(n)).

Be cautious!
NT_MIN	Minimum value for a variable of type int .	–2147483647 – 1
INT_MAX	Maximum value for a variable of type int .	2147483647

You are here! 
Your runtime beats 25.37% of cpp submissions.

Try to think about what if n is not integer. 
*/

#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x==0) return 0;
        double res = 1.0;      
		int m = n;
		while(  m!=0 ) {
			// cout << m << endl;
			if (m % 2 !=0) res *= x;			
			x *= x;		
			m = m / 2;				
		}
		
        return (n>0) ? res : 1.0 / res;        
    }
};


int main(){
	Solution s;
	cout << s.myPow( 2, 3) << endl;
	cout << s.myPow( 2, -3) << endl;
	cout << s.myPow( 0, 0) << endl;
	cout << s.myPow( 0, 1) << endl;
	cout << s.myPow( 3, 0) << endl;
	cout << s.myPow( 2.0, -2147483648) << endl;
	cout << s.myPow(0.00001, 2147483647) << endl;
	// cout << (-10/2) << " "<<(-1/2) << endl;
	// cout << (-10%2) << " "<<(-1%2) << endl;
	
	return 0;
}