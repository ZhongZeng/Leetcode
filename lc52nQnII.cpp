

/*

Leetcode 52. N-Queens II

Companies 
Zenefits 
Related Topics 
Backtracking 
Similar Questions 
N-Queens

Test Cases:
4
5
9

Next challenges: N-Queens

Runtime: 3 ms
Your runtime beats 97.66 % of cpp submissions.

*/

class Solution {
public:
    int totalNQueens(int n) {
        // backtrack, DFS 
        int sum=0;
        vector<int> vc, vs(2*n-1,-1), vd(2*n-1,-1);
        for( int i=0; i<n; i++) vc.push_back(i);// permutation of [0,n), no row/column attack 

        dfs( vc, vs, vd, sum, 0);// all permutation w/ backtrack
        
        return sum;
    }
    
    void dfs( vector<int>& vc, vector<int>& vs, vector<int>& vd, int& sum, int j){
        if(j==vc.size())    sum++;// j==vc.size()-1 is WRONG
        
        for( int i=j, t; i<vc.size(); i++){
            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;
            
            // no diagonal attack; math: represent a line in x,y-cordinate 
            if(vs[j+vc[j]]==-1&&vd[j-vc[j]+vc.size()-1]==-1){
                vs[j+vc[j]]=1;
                vd[j-vc[j]+vc.size()-1]=1;
                
                dfs(vc, vs, vd, sum, j+1);
                
                vs[j+vc[j]]=-1;
                vd[j-vc[j]+vc.size()-1]=-1;
            }
            
            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;            
        }
        
        return ;
    }
};

/*
// Runtime: 61 ms
// Your runtime beats 2.03 % of cpp submissions.
class Solution {
public:
    int totalNQueens(int n) {
        // backtrack, DFS 
        int sum=0;
        vector<int> vc;
        for( int i=0; i<n; i++) vc.push_back(i);// permutation of [0,n-1), no row/column attack 
        
        dfs( vc, 0, sum);
        
        return sum;
    }
    
    void dfs(vector<int>& vc, int j, int& sum){
        //for(auto e:vc)  cout<<e<<" ";   cout<<endl;
        if(j==vc.size())    sum++;
        
        for( int i=j, t; i<vc.size(); i++){
            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;
            
            if(isValid(vc,j))   dfs( vc, j+1, sum);

            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;
        }
        
        return ;
    }
    
    bool isValid(vector<int>& vc, int& j){
        int t;
        unordered_set<int> us, ud;
        unordered_set<int>::iterator usi;
        
        for( int i=0; i<=j; i++){
            t=vc[i]+i;// math: how to present a line in x,y-cordinate 
            usi=us.find(t);
            if(usi!=us.end())   return false;// no diagonal attack 
            else    us.emplace(t);
            
            t=vc[i]-i;
            usi=ud.find(t);
            if(usi!=ud.end())   return false;
            else    ud.emplace(t);
        }
        
        return true;
    }
};

*/