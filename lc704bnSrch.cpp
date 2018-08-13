
/*
Leetcode 704. Binary Search

Related Topics 
Binary Search 
Similar Questions 
Search in a Sorted Array of Unknown Size

Test Cases:
[-1,0,3,5,9,12]
9
[-1,0,3,5,9,12]
2

Next challenges: Search in a Sorted Array of Unknown Size

Runtime: 32 ms
Your runtime beats 96.88 % of cpp submissions. 

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b=0, e=nums.size(), mid; // [b,e)
		
		while(b+1<e){
			mid=b+(e-b)/2;
			if(target<nums[mid])	e=mid;
			else	b=mid;
		}
		
		return nums[b]!=target?-1:b;
    }
};
