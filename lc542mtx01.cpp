

/*
Leetcode 542. 01 Matrix

Related Topics 
Depth-first Search, Breadth-first Search

Next challenges: Clone Graph, Freedom Trail, Cut Off Trees for Golf Event

Test Cases:
See after the code. 

Runtime: 212 ms
Your runtime beats 73.23 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // BFS in this solution; I think BFS is faster. 
        
        queue<pair<int,int>> st;
        int r, c, d, md=matrix.size()+matrix[0].size();
        for(r=0; r<matrix.size(); r++){
            for(c=0; c<matrix[0].size(); c++){
                if(matrix[r][c]!=0){
                    if((0<r&&matrix[r-1][c]==0)||(0<c&&matrix[r][c-1]==0)
                       ||(r<matrix.size()-1&&matrix[r+1][c]==0)||(c<matrix[0].size()-1&&matrix[r][c+1]==0)){
                        st.emplace(make_pair(r,c));
                    }else{
                        matrix[r][c]=md;
                    }
                }
                //cout<<matrix[r][c]<<" ";
            }
            //cout<<endl;
        }
        
        while(!st.empty()){
            r=st.front().first;
            c=st.front().second;
            d=matrix[r][c];
            st.pop();
            if(0<r&&d+1<matrix[r-1][c]){
                matrix[r-1][c]=d+1;
                st.emplace(make_pair(r-1,c));
            }
            if(0<c&&d+1<matrix[r][c-1]){
                matrix[r][c-1]=d+1;
                st.emplace(make_pair(r,c-1));
            }
            if(r<matrix.size()-1&&d+1<matrix[r+1][c]){
                matrix[r+1][c]=d+1;
                st.emplace(make_pair(r+1,c));
            }
            if(c<matrix[0].size()-1&&d+1<matrix[r][c+1]){
                matrix[r][c+1]=d+1;
                st.emplace(make_pair(r,c+1));
            }
        }
        
        return matrix;
    }
};

/*
// Runtime: 1373 ms
// Your runtime beats 1.95 % of cpp submissions.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // BFS/DFS; DFS in this solution
        
        stack<pair<int,int>> st;
        int r, c, d, ml=matrix.size()+matrix[0].size()+1;
        for(int i=0; i!=matrix.size(); i++){
            for(int j=0; j!=matrix[0].size(); j++){ 
                if(matrix[i][j]!=0) matrix[i][j]=ml;
            }
        }
        //cout<<matrix.size()<<" "<<matrix[0].size()<<endl;
        
        for(int i=0; i!=matrix.size(); i++){
            for(int j=0; j!=matrix[0].size(); j++){                
                if(matrix[i][j]!=1){
                    st.push(make_pair(i,j));
                    while(!st.empty()){
                        r=st.top().first;
                        c=st.top().second;
                        d=matrix[r][c];
                        st.pop();
                        if(0<r&&d+1<matrix[r-1][c]){
                            matrix[r-1][c]=d+1;
                            st.push(make_pair(r-1,c));
                        }
                        if(0<c&&d+1<matrix[r][c-1]){
                            matrix[r][c-1]=d+1;
                            st.push(make_pair(r,c-1));
                        }
                        if(r<matrix.size()-1&&d+1<matrix[r+1][c]){
                            matrix[r+1][c]=d+1;
                            st.push(make_pair(r+1,c));
                        }
                        if(c<matrix[0].size()-1&&d+1<matrix[r][c+1]){
                            matrix[r][c+1]=d+1;
                            st.push(make_pair(r,c+1));
                        }
                    }
                }
            }
        }
        
        return matrix;
    }
};
*/

/*
Test Cases:
[[0,0,0],[0,1,0],[0,0,0]]
[[0,0,1,0],[0,1,0,0],[0,0,1,0],[0,1,1,0]]
[[0,1,1,1,0],[0,1,1,1,0],[0,1,1,1,0],[0,1,0,1,0]]
[[1,0,1,1,0,0,1,0,0,1],[0,1,1,0,1,0,1,0,1,1],[0,0,1,0,1,0,0,1,0,0],[1,0,1,0,1,1,1,1,1,1],[0,1,0,1,1,0,0,0,0,1],[0,0,1,0,1,1,1,0,1,0],[0,1,0,1,0,1,0,0,1,1],[1,0,0,0,1,1,1,1,0,1],[1,1,1,1,1,1,1,0,1,0],[1,1,1,1,0,1,0,0,1,1]]
[[1
0
1
1
0
0
1
0
0
1]
[0
1
1
0
1
0
1
0
1
1]
[0
0
1
0
1
0
0
1
0
0]
[1
0
1
0
1
1
1
1
1
1]
[0
1
0
1
1
0
0
0
0
1]
[0
0
1
0
1
1
1
0
1
0]
[0
1
0
1
0
1
0
0
1
1]
[1
0
0
0
1
1
1
1
0
1]
[1
1
1
1
1
1
1
0
1
0]
[1
1
1
1
0
1
0
0
1
1]]



*/