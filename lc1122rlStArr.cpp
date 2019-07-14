/*
1122. Relative Sort Array

Ranking of Weekly Contest 145  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (6)	Q3 (7)	Q4 (7)
1305 / 4931	zhongzeng 	9	0:50:32	 0:10:08	 0:50:32		

Companies	DE Shaw
Related Topics	Array, Sort 

Runtime: 4 ms
Memory Usage: 9 MB
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // hash table, O(m+n) time
        int len=0;
        vector<int> rt;
        unordered_map<int,int> um2, um1;
        unordered_map<int,int>::iterator umi;
        for( int i=0; i<arr2.size(); i++)   um2.emplace(arr2[i],0);// distinct elements in arr2
        
        for( int i=0; i<arr1.size(); i++){// record elements in arr1
            umi=um2.find(arr1[i]);
            if(umi!=um2.end()){
                umi->second+=1;
            }else{
                umi=um1.find(arr1[i]);
                if(umi!=um1.end())  umi->second+=1;
                else    um1.emplace(arr1[i], 1);
            }
        }
        
        for( int i=0; i<arr2.size(); i++){// elements in arr2
            umi=um2.find(arr2[i]);
            for( int j=0; j<umi->second; j++)   rt.push_back(umi->first);
        }
        len=rt.size();
        
        for( umi=um1.begin(); umi!=um1.end(); umi++){// elements not in arr2
            for( int j=0; j<umi->second; j++)   rt.push_back(umi->first);
        }
        sort( rt.begin()+len, rt.end());
        
        return rt;
    }
};