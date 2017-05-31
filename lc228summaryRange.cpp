

/*
Leetcode 228. Summary Ranges

You are here! 
Your runtime beats 0.55 % of cpp submissions.	3 ms
You are here! 
Your runtime beats 37.89 % of cpp submissions.	0 ms

Test Cases:
[1,2,5,7,8.9,11]

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vs;
        if(nums.size()==0)  return vs;
        int i=1,ib=0;
        while(i!=nums.size()){
            if(nums[i]!=nums[i-1]+1){
                if(i-1!=ib){
                    vs.push_back(to_string(nums[ib]) + "->" + to_string(nums[i-1]));
                }else{
                    vs.push_back(to_string(nums[i-1]));
                }
                ib=i;
            }
            i++;
        }
        
        if(i-1!=ib){
            vs.push_back(to_string(nums[ib]) + "->" + to_string(nums[i-1]));
        }else{
            vs.push_back(to_string(nums[i-1]));
        }
        
        return vs;
    }
};
