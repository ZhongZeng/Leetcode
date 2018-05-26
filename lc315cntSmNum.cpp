

/*
Leetcode 315. Count of Smaller Numbers After Self

Companies 
Google
Related Topics 
Divide and Conquer, Binary Indexed Tree, Segment Tree, Binary Search Tree 
Similar Questions 
Count of Range Sum, Queue Reconstruction by Height, Reverse Pairs

Next challenges: Count of Range Sum

Test Cases:
[5,2,6,1]
[4,3]
[1]
[]

Runtime: 37 ms
Your runtime beats 63.38 % of cpp submissions.

*/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // O(n*log(n)) time, O(n) space: similar to merge sort, lc 493; O(n^2) is trivial 
        int b=0, e=nums.size(), m=b+(e-b)/2;
        vector<int> rt(nums.size(), 0), vl;
        if(nums.size()<2)   return rt;
        for(int i=0; i<nums.size(); i++)    vl.push_back(i);//original locations
        
        dv(nums, vl, rt, b, m);
        dv(nums, vl, rt, m, e);
        mge(nums, vl, rt, b, m, e);
        //for(auto e:nums)    cout<<e<<" ";   cout<<endl;
        //for(auto e:vl)  cout<<e<<" ";   cout<<endl;
        
        return rt;
    }
    
    void dv(vector<int>& nums, vector<int>& vl, vector<int>& rt, int b, int e){
        if(b==e-1)  return;
        
        int m=b+(e-b)/2;
        dv(nums, vl, rt, b, m);
        dv(nums, vl, rt, m, e);
        mge(nums, vl, rt, b, m, e);
        
        return ;
    }
    
    void mge(vector<int>& nums, vector<int>& vl, vector<int>& rt, int b, int m, int e){
        vector<int> vc, vd;
        for(int i=b; i<m; i++)  vc.push_back(nums[i]);
        for(int i=b; i<m; i++)  vd.push_back(vl[i]);
        
        for(int i=0, j=m, k=b; i<vc.size(); k++){
            if(j<e&&nums[j]<vc[i]){
                nums[k]=nums[j];
                vl[k]=vl[j++];
            }else{//vc[i]<=nums[j], nums[j] guranteed to be smallest element larger than/equal to vc[i] 
                rt[vd[i]]+=j-m;// vd[i] not vl[i]
                nums[k]=vc[i];
                vl[k]=vd[i++];
            }
        }
        
        return ;
    }
};
