/*
1252. Cells with Odd Values in a Matrix

Related Topics	Array

Test Case:
2
3
[[0,1],[1,1]]
2
2
[[1,1],[0,0]]

Runtime: 4 ms	Your runtime beats 82.76 % of cpp submissions.
Memory Usage: 9.2 MB
*/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        // O(n*m+k) time&space; array, hash table 
        int t=0;
        unordered_map<int,int> ur, uc;
        unordered_map<int,int>::iterator ui;
        
        for( int i=0; i<indices.size(); i++){
            ui=ur.find(indices[i][0]);
            if(ui!=ur.end())    ui->second+=1;
            else    ur.emplace(indices[i][0], 1);
            
            ui=uc.find(indices[i][1]);
            if(ui!=uc.end())    ui->second+=1;
            else    uc.emplace(indices[i][1], 1);
        }
        
        for( int i=0; i<n; i++){
            for( int j=0; j<m; j++){
                int r=0;
                ui=ur.find(i);
                if(ui!=ur.end())    r+=ui->second;
                ui=uc.find(j);
                if(ui!=uc.end())    r+=ui->second;
                if(r%2==1)  t++;
            }
        }
        
        return t;
    }
};