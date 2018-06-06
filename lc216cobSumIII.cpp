
/*
Leetcode 216. Combination Sum III

Related Topics 
Array, Backtracking 
Similar Questions 
Combination Sum

Next challenges: Subsets II, Construct Binary Tree from Inorder and Postorder Traversal, 
Transform to Chessboard

Test Cases:
3
7
3
9
3
15

Runtime: 2 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // DFS backtracking, similiar to combination
        // 1-9 can be used only once
        vector<vector<int>> rt;
        vector<int> v;
        int i=1;
        if(9<k) return rt;
        
        dfs( i, k, n, v, rt);
        
        return rt;
    }
    
    void dfs( int i, int& k, int& n, vector<int>& v, vector<vector<int>>& rt){
        
        for( int j=i; j<10; j++){
            v.push_back(j);
            k--;
            n-=j;
            //for(auto e:v)   cout<<e<<" ";   cout<<endl;
            
            if(0<n&&0<k&&j<9)   dfs( j+1, k, n, v, rt);
            else if(n==0&&k==0) rt.push_back(v);
            
            v.pop_back();
            k++;
            n+=j;
        }
        
        return ;
    }
};
