/*
Leetcode 733. Flood Fill

Related Topics 
Depth-first Search 
Similar Questions 
Island Perimeter 

Next challenges: Recover Binary Search Tree, 
Sum Root to Leaf Numbers, Freedom Trail

Test Case:
[[1,1,1],[1,1,0],[1,0,1]]
1
1
2

Runtime: 32 ms
Sorry. We do not have enough accepted submissions to show runtime distribution chart.

*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // DFS,BFS
        if(image[sr][sc]==newColor) return image;
        int r=image.size(), c=image[0].size(),cl=image[sr][sc];
        queue<int> qr,qc;
        qr.push(sr);
        qc.push(sc);
        image[sr][sc]=newColor;
        while(!qr.empty()){            
            sr=qr.front();
            sc=qc.front();
            //cout<<sr<<" "<<sc<<endl;
            if(0<sr&&image[sr-1][sc]==cl){                
                qr.push(sr-1);
                qc.push(sc);
                image[sr-1][sc]=newColor;
            }
            if(sr<r-1&&image[sr+1][sc]==cl){
                qr.push(sr+1);
                qc.push(sc);
                image[sr+1][sc]=newColor;
            }            
            if(0<sc&&image[sr][sc-1]==cl){
                qr.push(sr);
                qc.push(sc-1);
                image[sr][sc-1]=newColor;
            }
            if(sc<c-1&&image[sr][sc+1]==cl){
                qr.push(sr);
                qc.push(sc+1);
                image[sr][sc+1]=newColor;
            }
            qr.pop();
            qc.pop();
        }
        
        return image;
    }
};
