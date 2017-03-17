
/*
Runtime: 66 ms
You are here! 
Your runtime beats 25.17% of cpp submissions.
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { 
        if (matrix.size()==0) return;
        if (matrix[0].size()==0) return;
        bool firstRow = false, firstColumn = false;
		/*
		int fm=-1, fn=-1;
        for (int i=0; i<matrix.size(); i++){
            if (fm!=-1) break;
            for (int j=0; j<matrix[0].size; j++){
                if (matrix[i][j]==0) {fm=i; fn=j;}
            }
        }
        
        for (; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size; j++){
                if (matrix[i][j]==0) matrix[]
            }
        }
		*/
		
		for (int i=0;i<matrix[0].size(); i++)
			if(matrix[0][i]==0) {firstRow = true; break;}
		
		for (int i=0;i<matrix.size(); i++)
			if(matrix[i][0]==0) {firstColumn = true; break;}		
		
		for (int i=1;i<matrix.size(); i++){
			for (int j=1; j<matrix[0].size(); j++){
				//cout<< "i "<<i<<" j "<<j<<endl;
				if (matrix[i][j]==0) {					
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
			}
		}
		
		for (int i=1; i<matrix[0].size(); i++)
			if (matrix[0][i]==0) setColumnZero(matrix, i);
		
		for (int i=1; i<matrix.size(); i++)
			if (matrix[i][0]==0) setRowZero(matrix, i);
		
		if (firstRow == 1) setRowZero(matrix, 0);
		if (firstColumn == 1) setColumnZero(matrix, 0);
	}

protected:	
	void setRowZero(vector<vector<int>>& matrix, int j){
		for (int i=0; i<matrix[0].size(); i++) matrix[j][i] = 0;
	}
	
	void setColumnZero(vector<vector<int>>& matrix, int j){
		for (int i=0; i<matrix.size(); i++) matrix[i][j] = 0;
	}
};

int main(){
	Solution s;
	vector<vector<int>> arr1 = {{1,2,3},{2,0,3},{2,3,0}};
	s.setZeroes(arr1);
	
	vector<vector<int>> arr2 = {{1,3,2,0,3}};
	s.setZeroes(arr2);
	for(int i=0; i<arr2.size(); i++) {
		for(int j=0; j<arr2[0].size(); j++){
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}