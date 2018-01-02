
/*
Leetcode 457. Circular Array Loop

Next challenges: Poor PigsCoin Change 2

Test Cases:
[2, -1, 1, 2, 2]
[2, -1, 1, -2, -2]
[-1, 2]

Runtime: 0 ms
Your runtime beats 27.55 % of cpp submissions.

*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        // O(n) time, O(1) space
        // The given array is guaranteed to contain no element "0".
        int i, j, k, c;
        bool f;
        
        for(i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                for( c=0, j=i, f=0<nums[i]; nums[j]!=0; c++){
                    k=nextI(j, nums[j], nums);
                    if(nums[k]&&0<nums[k]^f) break; // The loop must be "forward" or "backward'!
                    nums[j]=0;
                    if(k==j)    break;
                    if(k!=i){
                        j=k;
                    }else{
                        if(0<c) return true;
                        else    break;                        
                    }
                }
            }
        }
        
        return false;
    }
    
protected:
    int nextI(int j, int s, vector<int>& nums){
        int t=j+s;
        if(t<0){
            return t%nums.size();
        }else if(nums.size()-1<t){
            return t%nums.size();
        }else{
            return t;
        }
    }
    
};
