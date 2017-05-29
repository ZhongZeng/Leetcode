
/*
You are here! 
Your runtime beats 41.13% of cpp submissions.

The explanation is of 1 and -1 is important. 
There are two comparisons in each loop. 
*/

#include<vector>
#include<iostream>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

int guess(int num){	
	int i=6;
	if(num>i)	return -1;
	else if(num<i)	return 1;
	else 	return 0;
}

class Solution {
public:
    int guessNumber(int n) {

		int lo=1,hi=n+1,mid;
		while(true){
			mid = ((hi-lo) >>1)+lo;
			//cout<<lo<<" "<<mid<<" "<<hi<< endl;
			if (guess(mid)==-1)		hi=mid;
			else if (guess(mid)==1)lo=mid;
			else return mid;
		}
    }
};

int main(){
	Solution s;
	cout << s.guessNumber(100) << endl;
	return 0;
}