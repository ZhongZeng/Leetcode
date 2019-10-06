/*
1207. Unique Number of Occurrences

Companies	Google
Related Topics	Hash Table

Test Cases:
[1,2,2,1,1,3]
[1,2]

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 8.9 MB
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> us;
        unordered_map<int,int> ct;
        for(int i=0; i<arr.size(); i++){
            unordered_map<int,int>::iterator it=ct.find(arr[i]);
            if(it!=ct.end())    it->second+=1;
            else    ct.emplace(arr[i],1);
        }
        for(unordered_map<int,int>::iterator it=ct.begin(); it!=ct.end(); it++){
            unordered_set<int>::iterator iu=us.find(it->second);
            if(iu!=us.end())    return false;
            else    us.emplace(it->second);
        }
        return true;
    }
};