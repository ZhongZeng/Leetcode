/*
Leetcode 303. Range Sum Query - Immutable

Related Topics 
Dynamic Programming 
Similar Questions 
Range Sum Query 2D - Immutable, Range Sum Query - Mutable,
Maximum Size Subarray Sum Equals k 

Next challenges: Range Sum Query 2D - Immutable, 
Range Sum Query - Mutable, Maximum Size Subarray Sum Equals k

Runtime: 185 ms
You are here! 
Your runtime beats 35.54 % of cpp submissions.

*/

class NumArray {
public:
    // This is similar to but easier than lc304. Range Sum Query 2D - Immutable. 
	// O(n) time&space @ construction
	// O(1) time&space @ function call 
    vector<int> vc;
    
    NumArray(vector<int> nums) {
        int sum=0;
        vc.push_back(0);
        for(int i=0; i!=nums.size(); i++){
            sum+=nums[i];
            vc.push_back(sum);
        }        
    }
    
    int sumRange(int i, int j) {
        return vc[j+1]-vc[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
