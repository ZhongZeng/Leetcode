#include<vector>
#include<iostream>
using namespace std;


class Solution {

public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for (int i=0; i<len; i++) {
			while(nums[i] != nums[nums[i]-1]) swap(nums, i, nums[i]-1);
		}// this loop is tricky and crucial, which makes sure that
		// every element corresponds to its rank or is duplicated
        vector<int> arr;
        for (int i=0; i<len; i++)  if (nums[i] != i+1) arr.push_back(i+1);
        return arr;
    }

protected:    
    void swap (vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main(){
	vector<int> arr= {4,3,2,7,8,2,3,1};
	vector<int> arr1;
	Solution s;
	arr1 = s.findDisappearedNumbers(arr);
	int i;
	while ( i < arr1.size()) cout << arr1[i++] << endl;
	return 0;
}