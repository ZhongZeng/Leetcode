/*
1640. Check Array Formation Through Concatenation

Easy

Companies:	Uber
Related Topics:	Array, Hash Table, Sort

Runtime: 4 ms	Your runtime beats 85.74 % of cpp submissions.
Memory Usage: 10.4 MB	Your memory usage beats 37.85 % of cpp submissions.
*/

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // elements in arr is distinct 
        unordered_map<int,int> positions;
        for( int i=0; i<pieces.size(); i++){
            positions[pieces[i][0]]=i;
        }
        
        for( int i=0; i<arr.size(); ){
            unordered_map<int,int>::iterator it=positions.find(arr[i]);
            if(it!=positions.end()){
                int position=it->second;
                for( int j=1; j<pieces[position].size(); j++){
                    if(arr.size()<=i+j || arr[i+j]!=pieces[position][j])
                        return false;
                }
                i+=pieces[position].size();
            }else{
                return false;
            }
        }
        
        return true;
    }
};