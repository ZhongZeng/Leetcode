



/*

Leetcode 628. Maximum Product of Three Numbers

Next challenges: (M) Maximum Product Subarray

You are here! 
Your runtime beats 72.15 % of cpp submissions.	66 ms

Test Cases:
[-1,-2,-3,-4,-5]

[1,2,3,4]

[1,2,3]

*/


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // bubble sort
        int t;        
        if(nums[0]<nums[1]){    t=nums[0];  nums[0]=nums[1];    nums[1]=t;}
        if(nums[1]<nums[2]){    t=nums[1];  nums[1]=nums[2];    nums[2]=t;}
        if(nums[0]<nums[1]){    t=nums[0];  nums[0]=nums[1];    nums[1]=t;}
        int max1=nums[0], max2=nums[1], max3=nums[2], min1=nums[2], min2=nums[1];

        for(vector<int>::iterator it=nums.begin()+3; it!=nums.end(); it++){
            // cout<<max1<<" "<<max2<<" "<<max3<<" "<<min1<<" "<<min2<<endl;
            if(max1<*it){   max3=max2;  max2=max1;  max1=*it;}
            else if(max2<*it){  max3=max2;  max2=*it;}
            else if(max3<*it){  max3=*it;}
            
            if(*it<min1){   min2=min1;   min1=*it;}
            else if(*it<min2){  min2=*it;}         
            // cout<<max1<<" "<<max2<<" "<<max3<<" "<<min1<<" "<<min2<<endl<<endl;
        }
        
        int a=max1*max2*max3, b=min1*min2*max1;
        return a<b ? b : a;
    }
};
