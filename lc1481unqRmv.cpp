/*
5454. Least Number of Unique Integers after K Removals

Companies	Dosh
Related Topics	Array, Sort

Test Cases:
[2,1,1,3,3,3]
3
[5,5,4]
1
[4,3,1,1,3,3,2]
3

Runtime: 696 ms
Memory Usage: 62.4 MB
*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int unq=0;
        vector<int> ct;
        unordered_map<int,int> counts;
        for( int i=0; i<arr.size(); i++){
            if(counts.find(arr[i])!=counts.end())   counts[arr[i]]+=1;
            else    counts[arr[i]]=1;
        }
        unq=counts.size();
        
        for( unordered_map<int,int>::iterator it=counts.begin(); it!=counts.end(); it++)
            ct.push_back(it->second);
        sort( ct.begin(), ct.end());
        for( int i=0; 0<k&&i<ct.size(); k-=ct[i], i++)
            if(ct[i]<=k)    unq--;
        
        return unq;
    }
};