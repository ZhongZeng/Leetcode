
/*
Leetcode 724. Find Pivot Index

Related Topics 
Array 
Similar Questions 
Subarray Sum Equals K 

Next challenges: Construct Binary Tree from Preorder and Inorder Traversal,
Wiggle Sort, Range Addition

Test Cases:
[-1,-1,-1,0,1,1]
[]
[0,0,0,0]
[-1,1,-3,3]
[1,7,3,6,5,6]

Runtime: 35 ms
You are here! 
Your runtime beats 72.36 % of cpp submissions. 

*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0)  return -1;
        int sum=0;
        for(vector<int>::iterator it=nums.begin()+1; it!=nums.end(); it++)    sum+=*it;    
        // sum is the diff b/t 2 sums
        //cout<<sum<<endl;
        if(sum==0)  return 0;
        for(int i=1; i!=nums.size(); i++){
            sum-=nums[i-1]+nums[i];
            if(sum==0){
                return i;
            }
        }
        return -1;            
    }
};
