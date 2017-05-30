

/*
Leetcode 219. Contains Duplicate II

You are here! 
Your runtime beats 44.44 % of cpp submissions.	32 ms

Tags: Array, Hash Table
Similar Problems: (E) Contains Duplicate (M) Contains Duplicate III
Next challenges: (E) Contains Duplicate(M) Contains Duplicate III

*/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // at least two indicies satisfy the condition
        unordered_map<int,vector<int>> um;
        unordered_map<int,vector<int>>::iterator uit;
        vector<int> v;
        for(int i=0; i!=nums.size(); i++){// note that i is increasing
            // cout<<i<<" "<<nums[i]<<endl;
            uit=um.find(nums[i]);
            if(uit!=um.end()){
                uit->second.push_back(i);
                // cout<<uit->second[0]<<uit->second[1]<<endl;
            }else{
                v.clear();
                v.push_back(i);
                um.emplace(nums[i],v);
            }
        }
        
        for(unordered_map<int,vector<int>>::iterator it=um.begin();it!=um.end();it++){
            vector<int>::iterator vit=it->second.begin();
            for(int vit=0; vit!=it->second.size()-1;vit++){
                if( it->second[vit+1] - it->second[vit] <=k){
                    // cout<<it->second[vit+1]<<" "<<it->second[vit]<<endl;
                    return true;
                }
            }
            
        }
        
        return false;
    }
};