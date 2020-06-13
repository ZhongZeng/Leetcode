/*
1476. Subrectangle Queries

Medium
Companies	Nuro
Related Topics	Array

Test Cases:
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue","getValue"]
[[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],[3,0,3,2,10],[3,1],[0,2]]
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue"]
[[[[1,1,1],[2,2,2],[3,3,3]]],[0,0],[0,0,2,2,100],[0,0],[2,2],[1,1,2,2,20],[2,2]]
*/

/*
Runtime: 124 ms, faster than 100.00% of C++ online submissions for Subrectangle Queries.
Memory Usage: 19.1 MB, less than 33.33% of C++ online submissions for Subrectangle Queries.
Next challenges: Pour Water, Day of the Week, Cells with Odd Values in a Matrix
*/
class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
		rec=rectangle;
	}
	
	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		queries.push_back(vector<int> {row1, col1, row2, col2, newValue});
		return ;
	}
	    
    int getValue(int row, int col) {
        for( int i=queries.size()-1; -1<i; i--){
			if(queries[i][0]<=row&&row<=queries[i][2]&&
				queries[i][1]<=col&&col<=queries[i][3])
				return queries[i][4];
		}
		return rec[row][col];
    }
protected:
    vector<vector<int>> queries, rec;
};

/*
Runtime: 164 ms	Your runtime beats 66.67 % of cpp submissions.
Memory Usage: 18.6 MB
*/
class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for( int i=row1; i<=row2; i++){
            for( int j=col1; j<=col2; j++){
                rec[i][j]=newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rec[row][col];
    }
protected:
    vector<vector<int>> rec;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */