/*
Leetcode # 33
You are here! 
Your runtime beats 50.65% of cpp submissions.
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0) return -1;
		int pivot = findPivot(nums);
		int len = nums.size();
		int lo=0, hi=nums.size(), mid;
		while (lo!=hi-1){
			mid=(lo+hi)/2;		
			// cout << "before lo " << lo << " hi " << hi << " mid " << mid << " pivot " << pivot << endl;
			if ( target<nums[transRnk(mid, pivot,len)]) hi=mid;
			else lo=mid;
			// cout << "after  lo " << lo << " hi " << hi << " mid " << mid << " pivot " << pivot << endl;
		}		
		int res = transRnk(lo, pivot,len);
		return nums[res]!=target ? -1 : res;
    }	

protected:	
	int findPivot(vector<int> nums){
		if ( !nums[0]>nums[nums.size()-1]) return 0;
		int lo=0, hi=nums.size(), mid;
		while (lo!=hi-1){			
			mid = (lo+hi)/2;
			// cout << "befor  lo " << lo << " hi " << hi << " mid " << mid << endl;
			// cout << nums[lo] << " " << nums[mid] << " "<< nums[hi] << endl;
			if ( nums[lo] > nums[mid]) hi=mid;
			else lo=mid;
			// cout << "after  lo " << lo << " hi " << hi << " mid " << mid << endl;
		}
		return hi;
	}
	
	int transRnk(int org, int pivot, int size){
		return (org+pivot< size) ? (org+pivot) : (org+pivot-size);
	}
};

int main () {
	Solution s;
	vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};
	vector<int> arr2 = {3, 1};

	
	// cout << s.findPivot(arr2) << endl;
	// cout << arr2.size() << endl;
	// cout << s.transRnk(0, 1, 2) << endl;
	// cout << s.transRnk(0, s.findPivot(arr2), arr2.size()) << endl;
	for(int i=0; i<arr2.size(); i++) cout << arr2[i] << endl;
	// cout << "pivot " << s.findPivot(arr2) << endl;
	cout << s.search(arr2, 3) << endl;
	for(int i=0; i<arr2.size(); i++) cout << arr2[i] << endl;
	return 0;
}
