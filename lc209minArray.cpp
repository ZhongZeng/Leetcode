

/*
Leetcode 209. Minimum Size Subarray Sum

You are here! 
Your runtime beats 20.22 % of cpp submissions.	16 ms

Tags: Array Two Pointers Binary Search
Similar Problems: (H) Minimum Window Substring (M) Maximum Size Subarray Sum Equals k
Next challenges: (H) Minimum Window Substring(M) Maximum Size Subarray Sum Equals k

*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // if(nums.size==0){return 0;}
        // note that all elements are positive intergers
        // for prove, think about each element and all its previous elements
        if(nums.size()==0) return 0;
        vector<int>::iterator it1=nums.begin(),it2=nums.begin();
        int n=1, mn=nums.size()+1;
        int sum=nums[0];
        
        while(it2!=nums.end()){
            // cout<<*it1<<" "<<*it2<<" n:"<<n<<" sum:"<<sum<<endl;
            if(it1!=it2){
                if(sum<s){
                    it2++;
                    sum+=*it2;
                    n++;
                }else{
                    mn = n<mn ? n : mn;
                    sum-=*it1;
                    n--;
                    it1++;
                }
            }else{
                if(sum<s){
                    it2++;
                    sum+=*it2;
                    n++;
                }else{
                    return 1;
                }
            }
        }
        // cout<<"test"<<endl;
        return mn!=nums.size()+1 ? mn:0;
    }
};
