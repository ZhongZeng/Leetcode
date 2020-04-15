/*
1338. Reduce Array Size to The Half

Companies	Akuna Capital
Related Topics	Array, Greedy

Test Cases:
[3,3,3,3,5,5,5,2,2,7]
[7,7,7,7,7,7]
[1,9]
[1000,1000,3,7]
[1,2,3,4,5,6,7,8,9,10]

Runtime: 344 ms, faster than 41.81% of C++ online submissions for Reduce Array Size to The Half.
Memory Usage: 36.9 MB, less than 100.00% of C++ online submissions for Reduce Array Size to The Half.
Next challenges: Queens That Can Attack the King, 
Number of Burgers with No Waste of Ingredients, Maximum Performance of a Team
*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // hash table, sort; arr.size in [1,10**5]
        unordered_map<int,int> counts;
        vector<int> vc;
        int removed=0;
        
        for( int i=0; i<arr.size(); i++){
            unordered_map<int,int>::iterator it=counts.find(arr[i]);
            if(it!=counts.end())    it->second+=1;
            else    counts.emplace(arr[i], 1);
        }
        
        for( unordered_map<int,int>::iterator it=counts.begin(); it!=counts.end(); it++)
            vc.push_back(it->second);
        
        sort(vc.begin(), vc.end());        
        for( int i=vc.size()-1; -1<i; i--){
            removed+=vc[i];
            if(arr.size()/2<=removed)   return vc.size()-i;
        }
        
        return vc.size();
    }
};