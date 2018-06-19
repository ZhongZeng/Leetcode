
/*
302. Smallest Rectangle Enclosing Black Pixels

Companies 
Google
Related Topics 
Binary Search

Test Case:
[["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]]
0
2

Next challenges: Median of Two Sorted Arrays, Smallest Good Base, Find K-th Smallest Pair Distance

Runtime: 64 ms
Your runtime beats 22.67 % of cpp submissions.

*/


class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        // DFS
        // The black pixels are connected, i.e., there is only one black region.
        int u=x, d=x, l=y, r=y, row, col;
        vector<pair<int,int>> vc;
        vc.push_back(make_pair(x,y));
        
        while(!vc.empty()){
            row=vc.back().first;
            col=vc.back().second;
            vc.pop_back();
            image[row][col]='2';
            if(row<u)   u=row;
            else if(d<row)  d=row;
            if(col<l)   l=col;
            else if(r<col)  r=col;
            
            if(0<row&&image[row-1][col]=='1')   vc.push_back(make_pair(row-1,col));
            if(0<col&&image[row][col-1]=='1')   vc.push_back(make_pair(row,col-1));
            if(row<image.size()-1&&image[row+1][col]=='1')  vc.push_back(make_pair(row+1,col));
            if(col<image[0].size()-1&&image[row][col+1]=='1')   vc.push_back(make_pair(row,col+1));
        }
        //cout<<r<<" "<<l<<" "<<d<<" "<<u<<endl;
        
        return (r-l+1)*(d-u+1);
    }
};
