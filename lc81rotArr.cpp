
/*
Leetcode 81. Search in Rotated Sorted Array II

Related Topics 
Array, Binary Search 
Similar Questions 
Search in Rotated Sorted Array

Next challenges: Word Search, Lonely Pixel II, Best Time to Buy and Sell Stock with Transaction Fee

Test Cases:
[1]
1
[0,0,1,1,2,0]
2
[1,3,1,1,1]
3
[1,3]
1
[]
5
[2,5,6,0,0,1,2]
0
[2,5,6,0,0,1,2]
3

Runtime: 9 ms
Your runtime beats 31.35 % of cpp submissions.

*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()<1)   return false;
        
        return search(nums,target,0,nums.size()-1);
    }
    
    bool search( vector<int>& nums, int& target, int b, int e){//[b,e]
        // Binary search: sorted, pivot in [b,mid], [mid,e]
        if(e-b<1)   return nums[b]==target;
        int mid=b+(e-b)/2;
        
        while(b+1<e){// b!=e
            //cout<<b<<","<<e<<" ";
            mid=b+(e-b)/2;
            if(nums[mid]<target){
                if(nums[b]<nums[e]){// sorted 
                    b=mid;
                }else{
                    if(nums[mid]<nums[b]){// pivot in [b,mid] 
                        if(nums[e]<target)  e=mid;
                        else    b=mid;
                    }else if(nums[b]<nums[mid]){// pivot in [mid,e] 
                        b=mid;
                    }else{
                        if(nums[b]==nums[e])    
                            return search(nums,target,b,mid-1)||search(nums,target,mid,e);// nums[b]==nums[e]==nums[mid] 
                        else    b=mid;// pivot in [b,mid], nums[b]==nums[mid]>=nums[e] 
                    }
                }
            }else if(target<nums[mid]){
                if(nums[b]<nums[e]){// sorted 
                    e=mid;
                }else{
                    if(nums[mid]<nums[b]){// pivot in [b,mid] 
                        e=mid;
                    }else if(nums[b]<nums[mid]){// pivot in [mid,e] 
                        if(target<nums[b])  b=mid;
                        else    e=mid;
                    }else{
                        if(nums[b]==nums[e])
                            return search(nums,target,b,mid-1)||search(nums,target,mid,e);// nums[b]==nums[e]==nums[mid] 
                        else    b=mid;// pivot in [mid,e], nums[b]==nums[mid]>=nums[e]
                    }
                }
            }else{
                return true;
            }
        }
        //cout<<b<<","<<e<<" ";
        
        return nums[b]==target||nums[e]==target;        
    }
};
