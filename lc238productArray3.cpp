

/*
Leetcode 238. Product of Array Except Self
Similar Problems:
(H) Trapping Rain Water (M) Maximum Product Subarray (H) Paint House II

You are here! 
Your runtime beats 72.88% of cpp submissions. 49 ms
Your runtime beats 50.98% of cpp submissions. 52 ms
Your runtime beats 26.11% of cpp submissions. 59 ms


*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // solution w/ O(n) time and O(1) space besides the return vector
		// my best solution to this problem
		// travse the vector twice
        vector<int> res;
        // pdctb-product vector starting from the end, res-return vector
        int pi=1;
        res.push_back(1);
        for(vector<int>::iterator it=nums.begin(); it!=--nums.end(); it++){
            pi *= *it;
            res.push_back(pi);
            // cout<<pi<<" ";
        }
        
        vector<int>::reverse_iterator it=nums.rbegin();
        vector<int>::reverse_iterator itb=++res.rbegin();
        pi=1;
        while(itb!=res.rend()){
            // cout<<pi<<" "<<*itb<<" "<<*itb*pi<<endl;
            pi *= *it++;
            *itb++ *= pi;
        }
        
        return res;
    }
};