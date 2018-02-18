
/*
164. Maximum Gap

Related Topics 
Sort 

Next challenges: Sort List, Best Meeting Point, 
Longest Word in Dictionary through Deleting

Test Cases:
[]
[10]
[1,1,1,2,2]
[1,1,1]
[1,2,4,6,9,13]
[1,1,1,2,2,2,2,4]

Runtime: 8 ms
Your runtime beats 60.37 % of cpp submissions.

*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // bucket sort; O(n) space&time 
        // this should be Medium not Hard
        if(nums.size()<2)   return 0;
        int mn=nums[0], mx=nums[0], gp=0;
        
        // find max&min
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<mn)  mn=nums[i];
            else if(mx<nums[i]) mx=nums[i];
        }
        
        // bucket sort
        int d=(mx-mn)/(nums.size()+1); 
        if(d<1) d=1;// mx-mn<nums.size()+1
        int len=(mx-mn)/d+1;// if(d!=1)   len==(mx-mn)/d>=nums.size()+1
        vector<int> vb(len, mx), ve(len, mn);// pigeon hole principal
        for(int i=0, l; i<nums.size(); i++){
            l=(nums[i]-mn)/d;
            if(nums[i]<vb[l])   vb[l]=nums[i];//smallest in this range
            if(ve[l]<nums[i])   ve[l]=nums[i];//largest in this range
        }
        //cout<<len<<" "<<d<<endl;
        //for(auto e:vb)  cout<<e<<" ";   cout<<endl;
        //for(auto e:ve)  cout<<e<<" ";   cout<<endl;
        
        // find max gap 
        int lt=ve[0]!=mn?ve[0]:mn;
        for(int i=1; i<len-1; i++){
            if(vb[i]!=mx)   gp=gp<vb[i]-lt?vb[i]-lt:gp;
            if(ve[i]!=mn)   lt=ve[i];
        }
        gp=gp<vb.back()-lt?vb.back()-lt:gp;
        
        return gp;
    }
};