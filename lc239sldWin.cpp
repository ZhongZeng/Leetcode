

/*
Leetcode 239. Sliding Window Maximum

Related Topics 
Heap
Similar Questions 
Minimum Window Substring, Min Stack, 
Longest Substring with At Most Two Distinct Characters, Paint House II

Test Cases:
[]
0
[1,3,7,5,2,6,10]
1
[1,3,7,5,2,6,10]
4

Runtime: 72 ms
Your runtime beats 43.32 % of cpp submissions.

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // stack+queue
        // You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array. [] 0 is a test case!!!
        if(nums.size()<1)   return {};
        vector<int> vc={nums[0]}, rt;
        int i=0, bg=0;
        
        while(++i<k){ // 0 to k
            if(vc.back()<nums[i]){
                while(bg<vc.size()&&vc.back()<nums[i]){
                    vc.pop_back();
                }
            }
            vc.push_back(nums[i]);
        }
        rt.push_back(vc[bg]);
        //for(auto ele:vc)    cout<<ele<<" "; cout<<endl;
        
        for(i=0; i<nums.size()-k; i++){
            if(nums[i]==vc[bg])   bg++;
            
            if(vc.back()<nums[i+k]){
                while(bg<vc.size()&&vc.back()<nums[i+k]){
                    vc.pop_back();
                }
            }
            vc.push_back(nums[i+k]); 
            
            rt.push_back(vc[bg]);
            //cout<<vc[bg]<<" "<<bg<<endl;
        }
        
        return rt;
    }
};