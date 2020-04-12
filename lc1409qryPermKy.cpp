/*
1409. Queries on a Permutation With Key

Companies	Amazon
Related Topics	Array

Test Cases:
[3,1,2,1]
5
[4,1,2,2]
4
[7,5,5,8,3]
8

Runtime: 56 ms
Memory Usage: 8.4 MB
*/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        // brute force, O(n*m) time
        vector<int> location, values;
        for( int i=1; i<=m; i++)    values.push_back(i);
        
        for( int i=0; i<queries.size(); i++){
            for( int j=0; j<values.size(); j++){
                if(values[j]==queries[i]){
                    location.push_back(j);
                    values.erase(values.begin()+j);
                    values.insert(values.begin(), queries[i]);
                    break;
                }
            }
        }
        
        return location;
    }
};