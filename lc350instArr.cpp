

/*
Leetcode 350. Intersection of Two Arrays II

Related Topics 
Hash Table, Two Pointers, Binary Search, Sort 
Similar Questions 
Intersection of Two Arrays 

Next challenges: Intersection of Two Arrays

Test Cases:
[]
[]
[1,2,2,1]
[1,1]


Runtime: 6 ms
Your runtime beats 27.20 % of cpp submissions.

*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // if sorted, 2-pointer
        // if nums1.size()<<nums2.size(), same as following
        vector<int> vc;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi;
        for(int i=0; i!=nums1.size(); i++){
            umi=um.find(nums1[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(nums1[i],1);
        }
        
        for(int i=0; i!=nums2.size(); i++){
            umi=um.find(nums2[i]);
            if(umi!=um.end()&&umi->second!=0){
                vc.push_back(nums2[i]);
                umi->second-=1;
            }
        }
        
        return vc;
    }
};

