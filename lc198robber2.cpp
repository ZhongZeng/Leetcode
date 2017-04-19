

/*
Leetcode 198. House Robber
Similar Problems:  
 (M) Maximum Product Subarray (M) House Robber II 
 (E) Paint House (E) Paint Fence (M) House Robber III

O(n) time, O(1) space
You are here! 
Your runtime beats 68.76% of cpp submissions. 0 ms
Your runtime beats 2.68% of cpp submissions. 3 ms

This solution is very close to my solution 1.
The only difference is the use of temp. 
However, their running time is signnificantly different,
according to Leetcode online judge. 
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        /*O(n) time, O(1) space*/
        int maxlst=0, maxsd=0, temp;
        /* the max value of the vector including last element (w/ or w/t the last element) 
         , the max value of the vector excluding the last element (w/t the last element)*/
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            temp = maxlst;
			maxlst = max(maxsd+*it, maxlst);
			maxsd = temp;
            // cout<<maxlst<<" "<<maxsd<<endl;
        }
        return maxlst;
    }
};

