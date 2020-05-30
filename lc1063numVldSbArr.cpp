/*
1063. Number of Valid Subarrays

Companies	Hulu
Related Topics	Stack

Runtime: 176 ms, faster than 35.00% of C++ online submissions for Number of Valid Subarrays.
Memory Usage: 43.3 MB, less than 20.00% of C++ online submissions for Number of Valid Subarrays.
Next challenges: Closest Binary Search Tree Value II, Decoded String at Index,
Remove All Adjacent Duplicates in String II

Test Cases:
[1,4,2,5,3]
[3,2,1]
[2,2,2]
*/

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
		// Array, Stack; O(2*n) time&space 
        int sum=0;// nums[i] as subarray
		stack<pair<int,int>> value_and_index;// strictly ascending value and index from top/right to bottom/left
		for( int i=nums.size()-1; -1<i; i--){// calculate valid subarrays beginning @ i
			while( 0<value_and_index.size()&& nums[i]<=value_and_index.top().first )
				value_and_index.pop();
			sum+=(0<value_and_index.size()?value_and_index.top().second:nums.size())-i;
			value_and_index.push(make_pair(nums[i], i));
		}
		return sum;
    }
};

/*
O(n*n) is travial
Why saving travsered values O(n*log(n)) doesn't work? All values & indexes are needed, not just most closest one. 
*/