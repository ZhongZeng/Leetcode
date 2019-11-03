/*
1248. Count Number of Nice Subarrays

Company	Roblox
Related Topics	Two Pointer

Test Cases:
[1]
1
[1,1,2,1,1]
3
[2,4,6]
1
[2,2,2,1,2,2,1,2,2,2]
2

Runtime: 288 ms	Your runtime beats 25.00 % of cpp submissions.
Memory Usage: 39.4 MB
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // O(n) time&space; suffix solution; Two Poinnter can optimize to O(n) time, O(1) space 
        int sum=0;
        unordered_map<int,int> um;// # odd, # arr starting @ nums[0]
        unordered_map<int,int>::iterator umi;
        um.emplace(0,1);
        for( int i=0, od=0; i<nums.size(); i++){// count # of nice arr ending @ nums[i]
            if(nums[i]%2==1)    od++;
            umi=um.find(od);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(od,1);
            
            umi=um.find(od-k);
            if(umi!=um.end())   sum+=umi->second;
        }
        return sum;
    }
};