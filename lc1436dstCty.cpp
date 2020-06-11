/*
1436. Destination City

Easy
Companies	Yelp
Related Topics	String

Test Cases:
[["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]

Runtime: 28 ms, faster than 61.04% of C++ online submissions for Destination City.
Memory Usage: 10.8 MB, less than 80.17% of C++ online submissions for Destination City.
Next challenges: Stamping The Sequence, Remove Sub-Folders from the Filesystem,
Search Suggestions System
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
		// O(n) time; Hash Table, Bit Manipulation
        unordered_map<string,int> um;// city, position: 1, 2, 3=1&2
        for( int i=0; i<paths.size(); i++){
            if(um.find(paths[i][0])==um.end())  um.emplace(paths[i][0],1);
            else    um[paths[i][0]]=um[paths[i][0]]&1;
            if(um.find(paths[i][1])==um.end())  um.emplace(paths[i][1],2);
            else    um[paths[i][1]]=um[paths[i][1]]&2;
        }
        
        for( unordered_map<string,int>::iterator it=um.begin(); it!=um.end(); it++)
            if(it->second==2)   return it->first;
        
        return "";
    }
};