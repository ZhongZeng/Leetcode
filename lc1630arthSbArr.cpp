/*
1630. Arithmetic Subarrays

Companies:	Google
Related Topics:	Sort 
Similar Questions:	Arithmetic Slices, Can Make Arithmetic Progression From Sequence

Runtime: 84 ms	Your runtime beats 37.96 % of cpp submissions.
Memory Usage: 26.1 MB	Your memory usage beats 49.35 % of cpp submissions.
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> results;
        for( int i=0; i<l.size(); i++){
            results.push_back(canArrangeArithmeticArray( nums, l[i], r[i]));
        }
        return results;
    }
    
protected:
    bool canArrangeArithmeticArray( vector<int>& nums, int b, int e){
        int max=nums[b], min=nums[b], d;
        vector seq(e-b+1, 0);
        for( int i=b; i<=e; i++){
            max=max<nums[i]?nums[i]:max;
            min=min<nums[i]?min:nums[i];
        }
        
        if((max-min)%(e-b)!=0)  return false;
        if(max==min)    return true;
        d=(max-min)/(e-b);
        for( int i=b; i<=e; i++){
            if((nums[i]-min)%d!=0)  return false;
            int index=(nums[i]-min)/d;
            if(0<=index&&index<=e-b&&seq[index]==0) seq[index]=1;
            else    return false;
        }
        return true;
    }
};