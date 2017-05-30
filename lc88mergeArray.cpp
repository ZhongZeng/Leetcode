
/*
Leetcode 88. Merge Sorted Array

You are here! 
Your runtime beats 57.19 % of cpp submissions.
Runtime: 3 ms

Tags: Array Two Pointers
Similar Problems: (E) Merge Two Sorted Lists
Next challenges: (M) Word Search(H) Maximal Rectangle(E) Contains Duplicate II

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // think about merge sort
        // note that two arrays are sorted
		// I used the trick that I learned from THU Algo and Data Structure
        int it1=m-1, it2=n-1, it3=m+n-1;
        
        while(it2!=-1){
            if(nums2[it2]<nums1[it1] && it1!=-1){
                nums1[it3--]=nums1[it1--];
            }else{ // if(nums1[it1]<nums2[it2] || it1==-1)
                nums1[it3--]=nums2[it2--];
            }
        }
        
        return ;
    }
};
