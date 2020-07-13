/*
1512. Number of Good Pairs

Ranking of Weekly Contest 197  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
1550 / 13984	zhongzeng 	12	0:50:57	 0:03:14	 0:05:29	 0:50:57	

Easy
Companies	Activevideo
Related Topics	Array, Hash Table, Math

Test Cases:
[1,2,3,1,1,3]
[1,1,1,1]
[1,2,3]

Runtime: 4 ms	Your runtime beats 75.00 % of cpp submissions.
Memory Usage: 7.4 MB
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Hash Table, O(n) time
        int sum=0;
        unordered_map<int,int> counts;
        for( int i=0; i<nums.size(); i++){
            unordered_map<int,int>::iterator it=counts.find(nums[i]);
            if(it!=counts.end())    it->second+=1;
            else    counts[nums[i]]=1;
        }
        for( unordered_map<int,int>::iterator it=counts.begin(); it!=counts.end(); it++)
            sum+=it->second*(it->second-1)/2;
        return sum;
    }
};