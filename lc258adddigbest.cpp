
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
	// a1 = 9*n + r, where r<9 && -1<r
	// a1*10 = 90*n + 9*r + r = 9*(10*n+r) + r, where r<9 && -1<r 
		int rem, sum;
		if (num == 0 ) sum = 0;
        else {rem = num % 9; sum = (rem == 0) ? 9 : rem;}
        return sum;
    }
};

int main(){
	Solution s;
	cout << s.addDigits(0) << endl << endl;
	cout << s.addDigits(10) << endl << endl;
	cout << s.addDigits(1234) << endl << endl;
	// cout << (99 < 2) << endl << endl;
	return 0;
}
