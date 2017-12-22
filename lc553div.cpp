

/*
Leetcode 553. Optimal Division

Related Topics 
Math, String

Next challenges: Count and Say, Number of Digit One, Group Shifted Strings

Test Cases:
[1000,100,10,2]
[1000,2,100,100,10]
[100]
[100,3]

Runtime: 3 ms
Your runtime beats 9.92 % of cpp submissions.

*/

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        // Given a list of positive integers
        // this should be labeled as Easy 
        string s;
        s.append(to_string(nums[0]));
        if(nums.size()<2){
            return s;
        }else if(nums.size()<3){
            s.append("/");
            s.append(to_string(nums[1]));
            return s;
        } 
        s.append("/(");
        
        for(int i=1; i!=nums.size()-1; i++){
            s.append(to_string(nums[i]));
            s.append("/");
        }
        
        s.append(to_string(nums.back()));
        s.append(")");
        
        return s;
    }
};
