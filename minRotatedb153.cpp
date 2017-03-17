#include<vector>
#include<iostream>
using namespace std;

/*

You are here! 
Your runtime beats 36.74% of cpp submissions.

similar to Leetcode No. 33 Search in Rotated Sorted Array
I used the code from my solution to #33
To make the code more efficient, I change the way I define interval

Time complexity O(lg(n))
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
		int lo=0, hi=nums.size()-1, mid;
		while (lo!=hi){			
			mid = (lo+hi) >> 1 ;
			// cout << "before lo " << lo << " hi " << hi << " mid " << mid << endl;
			// cout << nums[lo] << " " << nums[mid] << " "<< nums[hi] << endl;
			if ( nums[hi] > nums[mid]) hi=mid;
			else lo=mid+1; // +1 here is critical!
			// cout << "after  lo " << lo << " hi " << hi << " mid " << mid << endl;
		}
		return nums[lo];
    }
};

int main(){
	vector<int> arr = {4,1,2,3};
	Solution s;
	cout << s.findMin(arr) << endl;
}
