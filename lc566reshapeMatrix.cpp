
/*
Leetcode 566. Reshape the Matrix

You are here! 
Your runtime beats 2.12 % of cpp submissions.	Runtime: 72 ms
Your runtime beats 37.44 % of cpp submissions.	Runtime: 43 ms

Tag:  Array
Next challenges: (M) Combination Sum II(E) Merge Sorted Array(E) Best Time to Buy and Sell Stock

*/


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r0 = nums.size(),c0;// original #rows
        if(r0!=0){
            c0 = nums[0].size();// original #columns; don't declare in if statement
        }else{
            return nums;
        }
        
        if(r0*c0!=r*c){
            return nums;
        }
        
        vector<vector<int>> vv;
        vector<int> v;
        int c1=0;
        for(int i=0; i!=r0; i++){
            for(vector<int>::iterator it=nums[i].begin(); it!=nums[i].end(); it++){
                // cout<<*it<<endl;
                v.push_back(*it);
                if(++c1==c){
                    vv.push_back(v);
                    v.clear();
                    c1=0;
                }
            }
        }
        return vv;
    }
};
