
/*
You are here! 
Your runtime beats 24.83% of cpp submissions.
assuming all elements are unique
*/


#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

/*
// brute force method
// You are here! 
// Your runtime beats 7.21% of cpp submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if (m==0) return false;
        int n=matrix[0].size();
        if (n==0) return false;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++)
                if(matrix [i][j]==target)   return true;
        }
        return false;
    }
};
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
		if (m==0) return false;
		int n = matrix[0].size();
		if (n==0) return false;
		int mlo=0, mhi=m, nlo=0, nhi=n;
		return searchSubMatrix(matrix, target, mlo, mhi, nlo, nhi);			
    }

// protected:	
	bool searchSubMatrix(vector<vector<int>>& matrix, int target, 
		int mlo0, int mhi0, int nlo0, int nhi0){
		
		
		if ( mhi0 < mlo0+2){
			for (int i=nlo0; i<nhi0 ;i++){
				//cout << matrix[mlo0][i] << " ";
				if(matrix[mlo0][i]==target) return true;
			}
			//cout << endl;
			return false;
		} 
		if (nhi0 < nlo0+2){
			for (int i=mlo0; i<mhi0 ;i++){
				//cout << matrix[mlo0][i] << " ";	
				if(matrix[i][nlo0]==target) return true;			
			}
			//cout << endl;
			return false;
		}
		
		int mlo=mlo0, mhi=mhi0, nlo=nlo0, nhi=nhi0;
		int mmid, nmid;
		while ( mlo+1 < mhi || nlo+1 < nhi ){
			mmid=(mlo+mhi)>>1;nmid=(nlo+nhi)>>1;
			//cout << "before " << "mmid " << mmid << " nmid " << nmid << " mlo " << mlo << " nlo " << nlo << " mhi " << mhi << " nhi " << nhi << endl;
			if( target < matrix[mmid][nmid] ){
				//if (mhi-mlo>1) 
					mhi = mmid; 
				//if (nhi-nlo>1) 
					nhi = nmid;
			}else{
				//if (mhi-mlo>1) 
					mlo = mmid; 
				//if (nhi-nlo>1) 
					nlo = nmid;
			}
			//cout << "after  " << "mmid " << mmid << " nmid " << nmid << " mlo " << mlo << " nlo " << nlo << " mhi " << mhi << " nhi " << nhi << endl << endl;
		}
		bool subMatrix1=false, subMatrix2=false;
		if (mlo0<mhi && nhi<nhi0) 
			subMatrix1=searchSubMatrix(matrix, target, mlo0, mhi, nlo, nhi0);
		if (mlo<mhi0) 
			subMatrix2=searchSubMatrix(matrix, target, mlo, mhi0, nlo0, nhi);
		return  subMatrix1 || subMatrix2;
	}
};

int main(){
	vector<vector<int>> matrix;
	matrix.push_back({1,   4,  7, 11, 15});
	matrix.push_back({2,   5,  8, 12, 19});
	// matrix.push_back({3,   6,  9, 16, 22});
	//matrix.push_back({10, 13, 14, 17, 24});
	//matrix.push_back({18, 21, 23, 26, 30});
	Solution s;
	cout <<endl<< s.searchMatrix(matrix, 12) << endl;
	//cout << s.searchMatrix(matrix, 20) << endl;// return 0
	
	vector<vector<int>> matrix1;
	matrix1.push_back({1,   4});
	matrix1.push_back({2,   5});
	cout <<endl<< s.searchMatrix(matrix1, 6) << endl;
	
	return 0;
}
