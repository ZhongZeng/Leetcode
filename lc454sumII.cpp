
/*
Leetcode 454. 4Sum II

Related Topics 
Hash Table, Binary Search 
Similar Questions 
4Sum 

Next challenges: 4Sum

Test Case:
[1,2]
[-2,-1]
[-1,2]
[0,2]

Runtime: 268 ms
You are here! 
Your runtime beats 69.20 % of cpp submissions.

*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator umi;
        int sum=0;
        for(int i=0; i!=A.size(); i++){
            for(int j=0; j!=B.size(); j++){
                umi=um.find(A[i]+B[j]);
                if(umi!=um.end()){
                    umi->second++;
                }else{
                    um.emplace(A[i]+B[j],1);
                }
            }
        }

        for(int i=0; i!=C.size(); i++){
            for(int j=0; j!=D.size(); j++){
                umi=um.find(0-C[i]-D[j]);
                if(umi!=um.end()){
                    sum+=umi->second;
                }
            }
        }                
        
        return sum;
    }
};
