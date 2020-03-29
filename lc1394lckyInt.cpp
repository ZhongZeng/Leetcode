/*
1394. Find Lucky Integer in an Array

Ranking of Weekly Contest 182  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (8)
4176 / 11695	zhongzeng 	12	1:19:26	 0:04:25	 1:19:26	 0:51:19

Companies	Microsoft
Related Topics	Array

Test Cases:
[2,2,3,4]
[1,2,2,3,3,3]
[2,2,2,3,3]
[5]
[7,7,7,7,7,7,7]

Runtime: 12 ms
Memory Usage: 10.5 MB

https://leetcode.com/problems/find-lucky-integer-in-an-array/discuss/555791/C%2B%2B-O(n)-TimeandSpace-Hash-table
*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int lucky=-1;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi;
        for( int i=0; i<arr.size(); i++){
            umi=um.find(arr[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(arr[i],1);
        }
        for( umi=um.begin(); umi!=um.end(); umi++){
            if(umi->first==umi->second&&lucky<umi->first)   lucky=umi->first;
        }
        return lucky;
    }
};