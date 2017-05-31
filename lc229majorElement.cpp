
/*
Leetcode 229. Majority Element II

Tag: Array
Next challenges: (M) Combination Sum(H) Trapping Rain Water(M) Minimum Size Subarray Sum

You are here! 
Your runtime beats 45.95 % of cpp submissions.	13 ms

Test Cases:
[1]
[1,2]
[1,1,1]
[3,2,3]

CHECK OTHERS' VERY INTERESTING SOLUTION. 

*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // use hash table, O(n) time
        // You can also sort the array, but it's O(nlog(n)) time
        vector<int> v;
        if(nums.size()<3){
            if(nums.size()==2 && nums[0]==nums[1]){
                return {nums[0]};
            }else{
                return nums;
            }
        }
        int n=nums.size()/3;
        
        map<int,int> m;
        map<int,int>::iterator im;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            im=m.find(*it);
            if(im!=m.end()){
                if(im->second < n){
                    im->second+=1;
                }else if(im->second==n){
                    v.push_back(im->first);
                }
            }else{
                m.emplace(*it,1);
            }
        }
        return v;
    }
};
