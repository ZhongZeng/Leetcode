
/*
Leetcode 80. Remove Duplicates from Sorted Array II

Related Topics 
Array, Two Pointers 

Next challenges: Combination Sum III, Summary Ranges, 
Shortest Word Distance III

Test Cases:
[]
[1,1,1,2,2,3,4,4,4,4,5]

Runtime: 12 ms
You are here! 
Your runtime beats 88.54 % of cpp submissions.


*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<1)   return 0;
        int c=1, i=0, j=0;        
        while( ++j!=nums.size() ){
            if( nums[j]!=nums[j-1] ){
                switch(c){
                    case 1:
                        nums[i]=nums[j-1];
                        i+=1;
                        break;
                    default:
                        nums[i]=nums[j-1];
                        nums[i+1]=nums[j-1];
                        i+=2;
                        break;
                }
                c=1;
            }else{
                c++;                
            }            
        }

        switch(c){
            case 1:
                nums[i]=nums[j-1];
                i+=1;
                break;
            default:
                nums[i]=nums[j-1];
                nums[i+1]=nums[j-1];
                i+=2;
                break;
        }        
        
        return i;
    }
};
