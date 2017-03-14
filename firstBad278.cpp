/*
You are here! 
Your runtime beats 40.10% of cpp submissions
*/


#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

bool isBadVersion(int version){
	return (version > 1702766718) ? true : false;//1702766718
};

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) return 1;
        int lo=1, hi=n, mid = n / 2;
        while ( lo!=hi-1 ){
            if( isBadVersion(mid) ) hi=mid;
            else lo = mid;
            mid = lo + (hi-lo) / 2;
			/* can't usd mid = (hi+lo) / 2, 
			 because INT_MAX is 2147483647*/
        }
        return lo+1;
    }

};

int main(){
	Solution s;
	cout << s.firstBadVersion(2126753390) << endl;//2126753390
}