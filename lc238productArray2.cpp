

/*
Leetcode 238. Product of Array Except Self
Similar Problems:
(H) Trapping Rain Water (M) Maximum Product Subarray (H) Paint House II


You are here! 
Your runtime beats 59.80% of cpp submissions. 52 ms

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // solution w/ O(n) time and O(1) space besides the return vector
		// travse the vector twice
        vector<int> res;
        // pdctb-product vector starting from the end, res-return vector
        int pi=1;
        res.push_back(1);
        for(vector<int>::reverse_iterator it=nums.rbegin(); it!=--nums.rend(); it++){
            pi *= *it;
            res.push_back(pi);
            // cout<<pi<<" ";
        }
        
        vector<int>::iterator it=nums.begin();
        vector<int>::reverse_iterator itb=res.rbegin();
        pi=1;
        while(itb!=res.rend()){
            *itb *= pi;
            // cout<<pi<<" "<<*itb<<" "<<*itb*pi<<endl;
            pi *= *it;
            it++; 
            itb++;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};