

/*
Leetcode 15. 3Sum

Tags: Array Two Pointers
Similar Problems: (E) Two Sum (M) 3Sum Closest (M) 4Sum (M) 3Sum Smaller
Next challenges: (E) Two Sum(M) 3Sum Closest(M) 4Sum(M) 3Sum Smaller

You are here! 
Your runtime beats 41.01 % of cpp submissions.	129 ms
Your runtime beats 45.35 % of cpp submissions.	126 ms

Test Cases:
[-1,0,1,2,-1,-4,5]
[-5,1,2,3,4,4]
[0,0,0,0]
[0,0,0]
[0,-1,1]
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){
            return {};
        }

        sort(nums.begin(), nums.end()); // for(int i=0;i!=nums.size();i++){cout<<nums[i]<<endl;}
        vector<vector<int>> vv;        
        int s,t=1-nums[0],ib,ie,b,e;
        for(int i=0; i!=nums.size()-2; i++){
            if(0<nums[i]){
                return vv;
            }
            
            if(nums[i]!=-t){ // tricky: no duplicate solutions
                t=0-nums[i];
                ib=i+1;
                ie=nums.size()-1;
                // cout<<"test"<<endl;
                while(ib!=ie){
                    // cout<<nums[ib]<<" "<<nums[ie]<<endl;
                    b=nums[ib];
                    e=nums[ie];
                    s=nums[ib]+nums[ie];
                    if(s<t){
                        do{
                            ++ib;
                        }while(nums[ib-1]==nums[ib] && ib!=ie);//++ib;
                    }else if(t<s){
                        do{
                            --ie;
                        }while(nums[ie]==nums[ie+1] && ib!=ie);//--ie;
                    }else{
                        vv.push_back({nums[i],nums[ib],nums[ie]});
                        do{
                            ++ib;
                        }while(nums[ib-1]==nums[ib] && ib!=ie);
                    }
                }
            }
        }
        return vv;
    }
/*    
    vector<int> mergeSort(vector<int> & nums){
        
        return nums;
    }
    
    vector<int> merge2(vector<int> nums1, vector<int> nums2){
        
        return nums1;
    }
*/
};