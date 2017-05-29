
/*

Leetcode 169. Majority Element

Tags: Array, Divide and Conquer, Bit Manipulation
Similar Problems: (M) Majority Element II
Next challenges: (M) Majority Element II

You are here! 
Your runtime beats 38.64 % of cpp submissions.
Runtime: 23 ms

Test Cases:
[8,8,7,7,7]

*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		// this solution is also inspired by others' solution; hash tabel
		// O(n) time, O(1) space
		if(nums.size()<2){
		    return nums[0];
		}
		
		unordered_map<int,int> m;
		unordered_map<int,int>::iterator ifd;
		int n=nums.size()/2;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
			ifd = m.find(*it);
			if(ifd!=m.end()){
			    if(ifd->second < n){
					ifd->second += 1;
    			}else{
    				return ifd->first;
    			}
			}else{
			    m.emplace(*it,1);
			}
		}
    }
};

int main(){
	vector<int> vec = {1, 2, 3, 4, 5};
	Solution s;
	s.majorityElement(vec);
}