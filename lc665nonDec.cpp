
/*

Leetcode 665. Non-decreasing Array

Related Topics 
Array 

Next challenges: Word Ladder IIFind Peak ElementLonely Pixel II



You are here! 
Your runtime beats 90.64 % of cpp submissions.

*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> vc;
        int i=0, c;
        while( ++i!=nums.size()){
            if( nums[i]<nums[i-1] ){
                break; 
            }
        }
        if( i==nums.size() )   return true;
        c=i;
        while( ++i!=nums.size()){
            if( nums[i]<nums[i-1] ){
                return false;
            }
        }
        
        if( c<2 || c==nums.size()-1 ){
            return true;
        }else{
            if( nums[c]<nums[c-2] && nums[c+1]<nums[c-1] ){
                return false;
            }else{
                return true;
            }
        }
        
    }
};

