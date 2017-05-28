

/*
Leetcode 35. Search Insert Position

Tags:  Array Binary Search
Similar Problems: (E) First Bad Version
Next challenges: (M) Combination Sum(H) Dungeon Game(M) Lonely Pixel I

You are here! 
Your runtime beats 42.01 % of cpp submissions.	Runtime: 6 ms
Your runtime beats 1.29 % of cpp submissions.	Runtime: 13 ms
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int a=-1, b=nums.size(), mid;
        while(a!=b-1){// (a,b]
            mid=(a+b)/2;
            if(nums[mid]<target){
                a=mid;
            }else{
                b=mid;
            }
            // cout<<a<<" "<<b<<endl;
        }
        return b;
    }
};
