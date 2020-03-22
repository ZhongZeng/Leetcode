/*
1391. Check if There is a Valid Path in a Grid

Companies	Robinhood
Related Topics	Depth-first Search, Breadth-frist Search

Test Cases:
[[6,1,3],[4,1,5]]
[[4,1],[6,1]]
[[2,4,3],[6,5,2]]
[[1,2,1],[1,2,1]]
[[1,1,2]]
[[1,1,1,1,1,1,3]]
[[2],[2],[2],[2],[2],[2],[6]]

https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/discuss/547347/c-omn-time
*/

/*
Runtime: 168 ms, faster than 63.64% of C++ online submissions for Check if There is a Valid Path in a Grid.
Memory Usage: 21.1 MB, less than 100.00% of C++ online submissions for Check if There is a Valid Path in a Grid.
Next challenges:
Word Ladder II, Shortest Distance from All Buildings, Sort Items by Groups Respecting Dependencies
*/
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
		// recursion, O(m*n) time 
		if(grid.size()<1||grid[0].size()<1) return false;
        int i=0, j=0, d;// d: 0-down, 1-left, 2-up, 3-right 
        if(grid[0][0]==2||grid[0][0]==6)    d=0;
        else if(grid[0][0]==1||grid[0][0]==3)  d=3;
        else if(grid[0][0]==5)  return false;
        else if(grid[0][0]==4)  return reachDestionation( 0, 0, 1, grid)||reachDestionation( 0, 0, 2, grid);
        
        return reachDestionation( 0, 0, d, grid);
	}
	
public:
	bool reachDestionation( int i, int j, int d, vector<vector<int>>& grid){
		if(i<0||grid.size()<=i||j<0||grid[0].size()<j)	return false;
		if(grid[i][j]==-1)	return false;
		int s=grid[i][j], i0=i, j0=j;
		grid[i][j]=-1;
		
		switch(s){
			case 1:
				if(d==1)	j--;
				else if(d==3)	j++;
				else	return false;
				break;
			case 2:
				if(d==0)	i++;
				else if(d==2)	i--;
				else	return false;
				break;
			case 3:
                if(d==3){
                    i++;
                    d=0;
                }else if(d==2){
                    j--;
                    d=1;
                }else{
                    return false;
                }
                break;
            case 4:
                if(d==2){
                    j++;
                    d=3;
                }else if(d==1){
                    i++;
                    d=0;
                }else{
                    return false;
                }
                break;
            case 5:
                if(d==0){
                    j--;
                    d=1;
                }else if(d==3){
                    i--;
                    d=2;
                }else{
                    return false;
                }
                break;
            case 6:
                if(d==0){
                    j++;
                    d=3;
                }else if(d==1){
                    i--;
                    d=2;
                }else{
                    return false;
                }
                break;
		}
		if(i0==grid.size()-1&&j0==grid[0].size()-1)	return true;
		
		return reachDestionation( i, j, d, grid);
	}
};

/*
Runtime: 128 ms, faster than 100.00% of C++ online submissions for Check if There is a Valid Path in a Grid.
Memory Usage: 21 MB, less than 100.00% of C++ online submissions for Check if There is a Valid Path in a Grid.
*/
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        // array, iteration; O(m*n) time 
        if(grid.size()<1||grid[0].size()<1) return false;
        int i=0, j=0, d;// d: 0-down, 1-left, 2-up, 3-right 
        if(grid[0][0]==2||grid[0][0]==6)    d=0;
        else if(grid[0][0]==1||grid[0][0]==3)  d=3;
        else if(grid[0][0]==5)  return false;
        else if(grid[0][0]==4)  return findValidPath(grid, 1)||findValidPath(grid, 2);
        
        return findValidPath(grid, d);
    }
    
protected: 
    bool findValidPath(vector<vector<int>>& grid, int d){
        int i=0, j=0;
        while( true ){
            // cout<<i<<","<<j<<":"<<d<<" ";
            if(i<0||grid.size()<=i||j<0||grid[0].size()<=j) return false;
            if(i==grid.size()-1&&j==grid[0].size()-1)  return isValidAndMove( i, j, d, grid[i][j]);
            
            int t=grid[i][j], i0=i, j0=j;
            if(grid[i][j]==-1)  return false;
            else    grid[i][j]=-1;
            
            if(!isValidAndMove( i, j, d, t))	return false;
        }
        return true;
    }
    
    bool isValidAndMove( int & i, int & j, int & d, int t){// is moving to this cell valid and then move to next 
        switch(t){
            case 1:
                if(d==1)    j--;
                else if(d==3)   j++;
                else    return false;
                break;
            case 2:
                if(d==0)    i++;
                else if(d==2)   i--;
                else    return false;
                break;
            case 3:
                if(d==3){
                    i++;
                    d=0;
                }else if(d==2){
                    j--;
                    d=1;
                }else{
                    return false;
                }
                break;
            case 4:
                if(d==2){
                    j++;
                    d=3;
                }else if(d==1){
                    i++;
                    d=0;
                }else{
                    return false;
                }
                break;
            case 5:
                if(d==0){
                    j--;
                    d=1;
                }else if(d==3){
                    i--;
                    d=2;
                }else{
                    return false;
                }
                break;
            default:// 6
                if(d==0){
                    j++;
                    d=3;
                }else if(d==1){
                    i--;
                    d=2;
                }else{
                    return false;
                }
                break;
        }
        return true;
    }
};


/*
Runtime: 208 ms	Your runtime beats 54.55 % of cpp submissions.
Memory Usage: 21.3 MB
*/
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        // array; O(n) time
        if(grid.size()<1||grid[0].size()<1) return false;
        int i=0, j=0, d;// d: 0-down, 1-left, 2-up, 3-right 
        if(grid[0][0]==2||grid[0][0]==6)    d=0;
        else if(grid[0][0]==1||grid[0][0]==3)  d=3;
        else if(grid[0][0]==5)  return false;
        else if(grid[0][0]==4)  return findValidPath(grid, 1)||findValidPath(grid, 2);
        
        return findValidPath(grid, d);
    }
    
protected: 
    bool findValidPath(vector<vector<int>>& grid, int d){
        int i=0, j=0;
        while( true ){
            // cout<<i<<","<<j<<":"<<d<<" ";
            if(i<0||grid.size()<=i||j<0||grid[0].size()<=j) return false;
            if(i==grid.size()-1&&j==grid[0].size()-1)  return isValidAndMove( i, j, d, grid[i][j]);
            
            int t=grid[i][j];
            if(grid[i][j]==-1)  return false;
            else    grid[i][j]=-1;
            
            isValidAndMove( i, j, d, t);
        }
        return true;
    }
    
    bool isValidAndMove( int & i, int & j, int & d, int t){// is moving to this cell valid and then move to next 
        switch(t){
            case 1:
                if(d==1)    j--;
                else if(d==3)   j++;
                else    return false;
                break;
            case 2:
                if(d==0)    i++;
                else if(d==2)   i--;
                else    return false;
                break;
            case 3:
                if(d==3){
                    i++;
                    d=0;
                }else if(d==2){
                    j--;
                    d=1;
                }else{
                    return false;
                }
                break;
            case 4:
                if(d==2){
                    j++;
                    d=3;
                }else if(d==1){
                    i++;
                    d=0;
                }else{
                    return false;
                }
                break;
            case 5:
                if(d==0){
                    j--;
                    d=1;
                }else if(d==3){
                    i--;
                    d=2;
                }else{
                    return false;
                }
                break;
            default:// 6
                if(d==0){
                    j++;
                    d=3;
                }else if(d==1){
                    i--;
                    d=2;
                }else{
                    return false;
                }
                break;
        }
        return true;
    }
};