
/*
Leetcode 238. Product of Array Except Self

You are here! 
Your runtime beats 3.55% of cpp submissions. 89 ms
Your runtime beats 35.17% of cpp submissions. 56 ms
Your runtime beats 46.06% of cpp submissions. 55 ms
Your runtime beats 59.80% of cpp submissions. 52 ms

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // solution w/ O(n) time and O(n) space
        vector<int> pdctb, res;
        // pdctb-product vector starting from the end, res-return vector
        int pi=1;
        pdctb.push_back(1);
        for(vector<int>::reverse_iterator it=nums.rbegin(); it!=--nums.rend(); it++){
            pi *= *it;
            pdctb.push_back(pi);
            // cout<<pi<<" ";
        }
        
        vector<int>::iterator it=nums.begin();
        vector<int>::reverse_iterator itb=pdctb.rbegin();
        res.push_back(*itb++);
        pi=1;
        while(itb!=pdctb.rend()){
            pi *= *it;
            res.push_back(*itb*pi);
            // cout<<pi<<" "<<*itb<<" "<<*itb*pi<<endl;
            it++; 
            itb++;
        }
        
        return res;
    }
};

