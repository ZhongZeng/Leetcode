/*
1460. Make Two Arrays Equal by Reversing Sub-arrays

Easy
Companies	Facebook
Related Topics	Array

Test Cases:
[1,2,3,4]
[2,4,1,3]
[3,7,9]
[3,7,11]

Runtime: 36 ms, faster than 48.45% of C++ online submissions for Make Two Arrays Equal by Reversing Sub-arrays.
Memory Usage: 15.6 MB, less than 22.98% of C++ online submissions for Make Two Arrays Equal by Reversing Sub-arrays.
Next challenges: Leftmost Column with at Least a One, Rank Teams by Votes, 
Minimum Value to Get Positive Step by Step Sum
*/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // O(n) time&space; Greedy, Array
        if(target.size()!=arr.size())   return false;
        unordered_map<int,int> um;
        for( int i=0; i<target.size(); i++){
            if(um.find(target[i])!=um.end())    um[target[i]]+=1;
            else    um[target[i]]=1;
        }
        for( int i=0; i<arr.size(); i++){
            if(um.find(arr[i])!=um.end()){
                um[arr[i]]-=1;
                if(um[arr[i]]<0)    return false;
            }else{
                return false;
            }
        }
        return true;
    }
};