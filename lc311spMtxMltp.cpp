
/*
Leetcode 311. Sparse Matrix Multiplication

Companies 
Facebook, Linkedin
Related Topics 
Hash Table 

Next challenges: Longest Substring with At Most Two Distinct Characters, 
Two Sum III - Data structure design, Replace Words

Test Cases:
[[1,0,0],[-1,0,3]]
[[7,0,0],[0,0,0],[0,0,1]]
[[2]]
[[3]]
[[]]
[[]]

Runtime: 20 ms
Your runtime beats 29.75 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        // O((elements in A+B)+non-empty rows in A*non-empty cols in B)
        
        if(A.size()<1||A[0].size()<1||B.size()<1||B[0].size()<1){
            vector<vector<int>> rt;
            return rt;
        }
        vector<int> vc(B[0].size(),0);
        vector<vector<int>> rt(A.size(),vc);
        unordered_map<int,unordered_map<int,int>> ma, mb;
        unordered_map<int,unordered_map<int,int>>::iterator ai, bi;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator au, bu;
        int e;
        
        // store non-empty rows from A
        for(int i=0; i<A.size(); i++){
            um.clear();
            for(int j=0; j<A[0].size(); j++)    if(A[i][j]!=0)  um.emplace(j, A[i][j]);
            if(!um.empty()) ma.emplace(i,um);
        }
        
        // store non-empty columns from B; actually vector can also do B, doesn't need hash table 
        for(int j=0; j<B[0].size(); j++){
            um.clear();
            for(int i=0; i<B.size(); i++)   if(B[i][j]!=0)  um.emplace(i, B[i][j]);
            if(!um.empty()) mb.emplace(j,um);
        }
        
        // multiply non-empty rows from A with non-empty columns from B
        for(ai=ma.begin(); ai!=ma.end(); ai++){
            for(bi=mb.begin(); bi!=mb.end(); bi++){
                e=0;
                for(bu=bi->second.begin(); bu!=bi->second.end(); bu++){
                    au=ai->second.find(bu->first);
                    if(au!=ai->second.end())    e+=(bu->second)*(au->second);
                }
                rt[ai->first][bi->first]=e;
            }
        }
        
        return rt;
    }
};
