#include<vector>
#include<iostream>
using namespace std;

/*
You are here! 
Your runtime beats 3.84% of cpp submissions.

similar to Leetcode No. 33 Search in Rotated Sorted Array
I used the code from my solution to #33
Time complexity O(lg(n))
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if ( !(nums.back()<nums[0])) return nums[0];

		int lo=0, hi=nums.size(), mid;
		while (lo!=hi-1){			
			mid = (lo+hi) >> 1;
			// cout << "befor  lo " << lo << " hi " << hi << " mid " << mid << endl;
			// cout << nums[lo] << " " << nums[mid] << " "<< nums[hi] << endl;
			if ( nums[lo] > nums[mid]) hi=mid;
			else lo=mid;
			// cout << "after  lo " << lo << " hi " << hi << " mid " << mid << endl;
		}
		return nums[hi];
    }
};

int main(){
	vector<int> arr = {1,2,3};
	Solution s;
	cout << s.findMin(arr) << endl;
}
