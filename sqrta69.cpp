

/*
You are here! 
Your runtime beats 24.08% of cpp submissions.
*/

#include<iostream>
using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        int lo=0, hi=(x>>1)+2, mid;
        while (lo!=hi-1){// open on the left and close on the right
            mid = lo + ((hi-lo)>>1);
			// cout<<lo<<" "<<mid<<" "<<x/mid<<" "<<hi<< endl;
            if ( x/mid < mid ) hi=mid; //x<mid*mid is too big
            else lo=mid;
        }
        return lo;
    }
};

int main(){
	Solution s;
	cout << s.mySqrt(808201) << endl<< endl;  //899*899=808201
	cout << s.mySqrt(100) << endl<< endl;
	cout << s.mySqrt(18) << endl<< endl;
	cout << s.mySqrt(16) << endl<< endl;
	cout << s.mySqrt(2) << endl<< endl;
	cout << s.mySqrt(1) << endl<< endl;
	cout << s.mySqrt(0) << endl<< endl;
}