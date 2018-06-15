
/*
Leetcode 154. Find Minimum in Rotated Sorted Array II

Related Topics 
Array, Binary Search 
Similar Questions 
Find Minimum in Rotated Sorted Array

Test Cases:
[10,1,10,10,10]
[1,3]
[1,3,5]
[2,2,2,0,1]

Next challenges: Dungeon Game, Pour Water, Minimize Max Distance to Gas Station

Runtime: 7 ms
Your runtime beats 95.38 % of cpp submissions.

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        // worst case O(n)
        int mn=nums[0];
        
        findMin( 0, nums.size()-1, mn, nums);
        
        return mn;
    }
    
    void findMin( int b, int e, int& mn, vector<int>& nums){
        // pivot in [b,e] if not sorted; capture nums[b] if sorted 
        int mid=b+(e-b)/2;
        
        while(b+1<e){
            mid=b+(e-b)/2;
            if(nums[mid]<nums[b]){// pivot in [b,mid]
                e=mid;
            }else if(nums[b]<nums[mid]){// pivot not in [b,mid]
                if(nums[e]<nums[mid]){// pivot in [mid,e]
                    b=mid;
                }else{// sorted: nums[b]<nums[mid]<=nums[e]
                    mn=nums[b]<mn?nums[b]:mn;
                    return ;
                }
            }else{// nums[b]==nums[mid]
                if(nums[e]<nums[mid]){// pivot in [mid,e]
                    b=mid;
                }else if(nums[mid]<nums[e]){// sorted: nums[b]==nums[mid]<nums[e]
                    mn=nums[b]<mn?nums[b]:mn;
                    return ;
                }else{
                    findMin(b,mid-1,mn,nums);
                    findMin(mid,e,mn,nums);
                    return ;
                }
            }
            //cout<<b<<","<<e<<" ";
        }
        if(nums[b]<nums[e]) mn=nums[b]<mn?nums[b]:mn;
        else    mn=nums[e]<mn?nums[e]:mn;
        
        return ;
    }
};
