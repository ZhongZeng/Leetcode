/*
1389. Create Target Array in the Given Order

Weekly Contest 181
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
4596 / 6782	zhongzeng 	7	0:36:22	 0:04:01	 0:26:22  2	

Related Topic	Array

Test Cases:
[0,1,2,3,4]
[0,1,2,2,1]
[1,2,3,4,0]
[0,1,2,3,0]
[1]
[0]

Runtime: 0 ms
Memory Usage: 8.4 MB
*/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        // brute force, O(n*n) time
        vector<int> target;
        
        for( int i=0; i<nums.size(); i++){
            target.insert( target.begin()+index[i], nums[i]);
        }
        
        return target;
    }
};