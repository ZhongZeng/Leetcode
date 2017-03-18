
/*
You are here! 
Your runtime beats 10.93% of cpp submissions.
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        bool isSquare = false;
		if(num==1) return true;
        int lo=2, hi=(num>>1)+1, mid;
        while (lo<hi-1){//close on the left & open on the right
            mid = lo + ((hi-lo)>>1);
			// cout<<lo<<" "<<mid<<" "<<hi<< endl;
            if ( num/mid < mid ) hi=mid; //num<mid*mid is too big
            else lo=mid;
        }
        return (lo*lo==num) ? true:false;
    }
};

int main(){
	Solution s;
	cout << s.isPerfectSquare(8082101) << endl<< endl;
	cout << s.isPerfectSquare(18) << endl<< endl;
	cout << s.isPerfectSquare(16) << endl<< endl;
	cout << s.isPerfectSquare(2) << endl<< endl;
}