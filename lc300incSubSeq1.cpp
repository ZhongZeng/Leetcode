
/*
Leetcode 300. Longest Increasing Subsequence

Related Topics 
Binary Search, Dynamic Programming 
Similar Questions 
Increasing Triplet Subsequence, Russian Doll Envelopes,
Maximum Length of Pair Chain, Number of Longest Increasing Subsequence

Next challenges: 
Increasing Triplet Subsequence, Russian Doll Envelopes, 
Maximum Length of Pair Chain, Number of Longest Increasing Subsequence

Test Cases:
[]
[1]
[1,2,3,4,5,6,7]
[10,9,2,5,3,7,101,18]

Runtime: 19 ms
You are here! 
Your runtime beats 55.97 % of cpp submissions.

*/

#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		// Dynamic Programming
		// O(n^2) time, O(n) space
        if(nums.size()<1)	return 0;
		vector<int> pre={ 0 };
		int cl=0, ml=0; // current length, max length
		for(int i=1; i!=nums.size(); i++){
			cl = 0;
			for(int j=0; j!=i; j++){
				if( nums[j]<nums[i] ){
					if( cl < pre[j]+1 ){
						cl = pre[j]+1 ; 
					}
				}				
			}
            // cout << cl << endl;
			pre.push_back( cl );
			if( ml<cl )	ml=cl;
		}
        
		return ml+1;
    }
};


int main(){
	Solution s;
	vector<int> a1,a2,a3,a4,a5,a6;
	a1={};
	a2={1};
	a3={1,2,3,4,5,6,7};
	a4={10,9,2,5,3,7,101,18};
	cout<< s.lengthOfLIS(a1) << endl; 
	cout<< s.lengthOfLIS(a2) << endl; 
	cout<< s.lengthOfLIS(a3) << endl; 
	cout<< s.lengthOfLIS(a4) << endl; 
	
	return 0;	
}


