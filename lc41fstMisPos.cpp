


/*
Leetcode 41. First Missing Positive

Related Topics 
Array 
Similar Questions 
Missing Number, Find the Duplicate Number, Find All Numbers Disappeared in an Array 

Next challenges: Missing Number, Find the Duplicate Number,
Find All Numbers Disappeared in an Array

Test Cases:
[1,2,0]
[3,4,-1,1]
[1]
[0,3]
[2,1]

Runtime: 3 ms
You are here! 
Your runtime beats 59.19 % of cpp submissions.

*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()<1)   return 1;
        
        int tmp, pos;
        for(int i=0; i!=nums.size(); i++){
            pos = nums[i];            
            while( 0<pos && pos<nums.size() ){
                //cout<<pos<<' '<<nums[pos]<<' ';
                if( pos!=nums[pos-1] ){                       
                    tmp = nums[pos-1];
                    nums[pos-1] = pos;
                    pos = tmp;       
                }else{
                    break;
                }
            }
        }
        
        for(int i=0; i!=nums.size(); i++){
            //cout<<nums[i]<<' ';
            if( nums[i]!=i+1 ){
                return i+1;
            }            
        }
                
        return nums.size()+1 ;
    }
};

int main() {
	Solution s;
	vector<int> n1={2, 1};
	cout << s.firstMissingPositive( n1 ) << endl;
	
	return 0;
}