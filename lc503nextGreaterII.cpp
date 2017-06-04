

/*
Leetcode 503. Next Greater Element II

You are here! 
Your runtime beats 42.14 % of cpp submissions.	132 ms

Tag: Stack
Similar Problems: (E) Next Greater Element I (M) Next Greater Element III
Next challenges: (M) Next Greater Element III

*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // since -1 is returned for not found, I may assume there are only positive numbers
		// very similar to lc 496 Next Greater Element, except do it twice with a little modification
        stack<int> sn, si; // stacks of element value and its index
        vector<int> v(nums.size(), 0);
        for(int i=0; i!=nums.size(); i++){
            while ( !sn.empty() && sn.top()<nums[i] ){
                v[si.top()]=nums[i];
                sn.pop();
                si.pop();
            }
            sn.push(nums[i]);
            si.push(i);
        }
        
        for(int i=0; i!=nums.size(); i++){
            while ( !sn.empty() && sn.top()<nums[i] ){
                v[si.top()]=nums[i];
                sn.pop();
                si.pop();
            }
        }
        
        while(!sn.empty()){
            v[si.top()]=-1;
            sn.pop();
            si.pop();
        }
        
        return v;
    }
};
