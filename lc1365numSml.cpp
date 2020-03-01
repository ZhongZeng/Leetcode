/*
1365. How Many Numbers Are Smaller Than the Current Number

Ranking of Weekly Contest 178  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
2149 / 9210	zhongzeng 	8	0:39:09	 0:07:49		 0:39:09

Company	Google
Related Topics	Array, Hash Table

Test Cases:
[8,1,2,2,3]
[6,5,4,8]
[7,7,7,7]

Runtime: 16 ms	Your runtime beats 93.75 % of cpp submissions.
Memory Usage: 9.4 MB
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count_smaller(nums.size(),0);
        unordered_map<int,vector<int>> um;
        
        for( int i=0; i<nums.size(); i++){
            unordered_map<int,vector<int>>::iterator umi=um.find(nums[i]);
            if(umi!=um.end()){
                umi->second.push_back(i);
            }else{
                vector<int> vc={i};
                um.emplace(nums[i], vc);
            }
        }
        
        sort( nums.begin(), nums.end());
        
        for( int i=0; i<nums.size(); ){
            unordered_map<int,vector<int>>::iterator umi=um.find(nums[i]);
            for( int j=0; j<umi->second.size(); j++)    count_smaller[umi->second[j]]=i;
            i+=umi->second.size();
        }
        
        return count_smaller;
    }
};