

/*
Leetcode # 189. Rotate Array
You are here! 
Your runtime beats 22.42% of cpp submissions. 29 ms
Your runtime beats 27.46% of cpp submissions. 26 ms
Your runtime beats 61.48% of cpp submissions. 19 ms
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /* this solution is in-space O(k), time complexity O(n)*/
        int len=nums.size();
        k = k%len;
        int * arr= new int[k];
        for(int i=0; i!=k; i++){
            arr[i]=nums[len-k+i];
            // cout<<arr[i]<<endl;
        }
        
        for(int i=len-1; i!=k-1; i--){
            nums[i]=nums[i-k];
        }
        
        for(int i=0; i!=k; i++){
            nums[i]=arr[i];
        }
        
        delete[] arr;
        return;
    }
};
