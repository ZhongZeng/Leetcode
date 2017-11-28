

/*
Leetcode 304. Range Sum Query 2D - Immutable

Related Topics 
Dynamic Programming 
Similar Questions 
Range Sum Query - Immutable, Range Sum Query 2D - Mutable 

Next challenges: Range Sum Query - Immutable, Range Sum Query 2D - Mutable

Test Case:
["NumMatrix","sumRegion","sumRegion","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]

["NumMatrix","sumRegion","sumRegion","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[1,1,3,3],[1,1,2,2],[1,2,2,4]]

Runtime: 32 ms
Your runtime beats 10.14 % of cpp submissions. 

Runtime: 23 ms
Your runtime beats 34.99 % of cpp submissions.

*/

class NumMatrix {
public:
    // inspired by a glance at solution
    // The trick is that sumRegion will be called 
	// O(n) time&space @ construction
	// O(1) time&space @ function call 
    int r, c;
    vector<vector<int>> mx;
    
    NumMatrix(vector<vector<int>> matrix) {
        r=matrix.size();
        c=0<r?matrix[0].size():0;
        
        vector<int> vc(c+1,0);
        mx.push_back(vc);
        
        int sum;
        for(int i=0; i!=r; i++){
            sum=0;
            for(int j=0; j!=c; j++){
                sum+=matrix[i][j];
                vc[j+1]=sum+mx[i][j+1];
                //cout<<vc[j+1]<<" ";
            }
            //cout<<endl;
            mx.push_back(vc);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //cout<<mx[row2+1][col2+1]<<" "<<mx[row1][col1]<<" "<<mx[row2+1][col1]<<" "<<mx[row1][col2+1]<<endl;
        return mx[row2+1][col2+1]+mx[row1][col1]-mx[row2+1][col1]-mx[row1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

/*
// Brute Force Method
// Runtime: 223 ms
// Your runtime beats 0.40 % of cpp submissions.

class NumMatrix {
public:
    
    vector<vector<int>> mx;
    
    NumMatrix(vector<vector<int>> matrix) {
        mx=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1; i!=row2+1; i++){
            for(int j=col1; j!=col2+1; j++){
                sum+=mx[i][j];
            }
        }
        return sum;
    }
};

*/
