/*
410. Split Array Largest Sum

Related Topics: Binary Search, Dynamic Programming 

Test Cases:
[1,2147483647]
2
[7,2,5,10,8]
2
[0,0,0]
1

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split Array Largest Sum.

*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // binary search, O(n*log(sum/m)) time 
        long b=0, e=0, mid, cb=nums.size()+1, ce=1, cm;
        for(int i=0; i<nums.size(); i++)    e+=nums[i];
        
        while(b+1<e){// (b,e], m in [ce,cb) 
            mid=b+(e-b)/2;
            cm=countSubarray(nums,mid);
            if(m<cm){
                b=mid;
                cb=cm;
            }else{
                e=mid;
                ce=cm;
            }
        }
        
        return e;
    }
    
    long countSubarray( vector<int>& nums, long mid){// O(n) time
        long rt=1, t=0;
        for( int i=0; i<nums.size(); i++){
            if(t+nums[i]<=mid){
                t+=nums[i];
            }else{
                if(mid<nums[i]) return nums.size()+1;// edge case
                t=nums[i];
                rt++;
            }
        }
        return rt;
    }
};