

/*
Leetcode 581. Shortest Unsorted Continuous Subarray

Tags: Array
Next challenges: (H) Maximal Rectangle(M) Construct Binary Tree from Preorder and Inorder Traversal(M) Combination Sum III

You are here! 
Your runtime beats 53.92 % of cpp submissions.
Runtime: 49 ms

Test Cases: 
[2,6,4,8,10,9,15,16,17,20,19]
10
[1,2,3,4,5]
0
[2,3,3,2,4]
3

*/


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