

/*
Leetcode 581. Shortest Unsorted Continuous Subarray

Tags: Array
Next challenges: 
(H) Maximal Rectangle(M) Construct Binary Tree from Preorder and Inorder Traversal(M) Combination Sum III

Next challenges: 
Word Search, Maximum Sum of 3 Non-Overlapping Subarrays, Find K-th Smallest Pair Distance


Test Cases: 
[2,6,4,8,10,9,15,16,17,20,19]
[1,2,3,4,5]
[2,3,3,2,4]
[2,6,4,8,10,9,15]
[1,2,4,3,5,6]
[1,2,3,4,5,6]
[1,3,2,2,2]
[4,3,1]
[1,3,2,3,3]
[2,5,4,3,1]

*/

// Solution 1: Your runtime beats 61.58 % of cpp submissions. Runtime: 44 ms
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // O(n) time, O(1) space 
        // ascending order here means <=
        int b, e, i, mx, mn, ba, ea;
        
        // find 1st unsorted element 
        for( i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                b=i-1;
                break;
            }
        }
        if(i==nums.size())  return 0;
        
        // find last unsorted element 
        for( i=nums.size()-1; 0<i; i--){
            if(nums[i]<nums[i-1]){
                e=i;
                break;
            }
        }
        
        // find max & min elements in unsorted array 
        mx=nums[b];//b!=e
        mn=nums[e];
        for(i=b; i<=e; i++){
            if(nums[i]<mn)  mn=nums[i];
            else if(mx<nums[i]) mx=nums[i];
        }
        
        // find begin & end of subarray 
        for(ba=0; nums[ba]<=mn; ba++){}
        for(ea=nums.size()-1; mx<=nums[ea]; ea--){}
        // cout<<mn<<" "<<mx<<"; "<<ba<<" "<<ea<<endl;
        
        return ea-ba+1;
    }
};

// Solution 2: Your runtime beats 53.92 % of cpp submissions. Runtime: 49 ms 
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // note the array should be continuous
		// this solution travse the vector twice
        if(nums.size()<2){
            return 0;
        }
        vector<int>::iterator em=nums.begin(),le=nums.begin();
        vector<int>::reverse_iterator es=nums.rbegin(),fe=nums.rbegin();
        // em-largest element, le-last element in unsorted array
        // es-smallest element, fe-first element in unsorted array
        for(vector<int>::iterator it=++nums.begin(); it!=nums.end(); it++){
            if(*it<*em){
                le=it;
            }else if(*em<*it){
                em=it;
            }
        }
        
        if(le==nums.begin()){
            return 0;
        }
        
        for(vector<int>::reverse_iterator rit=++nums.rbegin(); rit!=nums.rend(); rit++){
            if(*es<*rit){
                fe=rit;
            }else if(*rit<*es){
                es=rit;
            }
        }
        
        // int f=nums.rend()-fe-1;
        // int l=le-nums.begin();
        // cout<<f<<" "<<l<<endl;
        return (le-nums.begin())-(nums.rend()-fe)+2;
    }
};




/*
//WRONG solution

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // note the array should be continuous
        if(nums.size()<2){
            return 0;
        }
        vector<int>::iterator em=nums.begin(),es=nums.begin(),fe,le=nums.begin();
        // em-largest element, es-smallest element, fe-first element in unsorted array, le-last element in unsorted array
        for(vector<int>::iterator it=++nums.begin(); it!=nums.end(); it++){
            if(*it<*em){
                fe=em;
                le=it;
                break;
            }else if(*em<*it){
                em=it;
            }
        }
        
        if(le!=nums.begin()){
            for(vector<int>::iterator it=fe+1; it!=nums.end(); it++){
                if(*it<*em){
                    le=it;
                }else{
                    em=it;
                }
            }
        }else{
            return 0;
        }
        
        
        
        return (le-fe+1);
    }
};

*/