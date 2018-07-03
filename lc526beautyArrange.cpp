
/*
Leetcode 526. Beautiful Arrangement

Companies 
Google
Related Topics 
Backtracking
Similar Questions 
Beautiful Arrangement II

Test Cases:
2
5

Next challenges: Palindrome Partitioning, 
Add and Search Word - Data structure design, Flip Game II

Runtime: 78 ms
Your runtime beats 58.77 % of cpp submissions.

*/

class Solution {
public:
    int countArrangement(int N) {
        // DFS, permutation 
        int sum=0;
        vector<int> vc;
        for( int i=1; i<=N; i++)    vc.push_back(i);
        
        dfs( 0, vc, sum);
        
        return sum;
    }
    
    void dfs( int j, vector<int>& vc, int& sum){
        if(j==vc.size()){
            sum++;
            return ;
        }
        
        for( int i=j, t; i<vc.size(); i++){
            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;
            
            if(vc[j]%(j+1)==0||(j+1)%vc[j]==0)  dfs( j+1, vc, sum);
            
            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;            
        }
        
        return ;
    }
};
