
/*assuming every internal vector is sorted 
treat the matrix like a 1D vector
You are here! 
Your runtime beats 14.05% of cpp submissions.
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (n==0) return false;// exclude[]
		int m = matrix[0].size();
		if (m==0) return false;// excluude [[]]
        int lo = 0, hi = n*m, mid;
        while(lo != hi-1){			
            mid = (lo+hi) >> 1;
			// cout<<"lo "<<lo<<" hi "<<hi<<" mid "<< mid<<endl;
            if ( matrix[mid/m][mid%m] > target ) hi=mid;
            else lo=mid;
			// cout<<"lo "<<lo<<" hi "<<hi<<" mid "<< mid<<endl;
        }
        return matrix[lo/m][lo%m]==target;
    }
};

int main(){
	vector<vector<int>> mar;
	mar.push_back({1, 2, 3});
	mar.push_back({4, 5, 6});
	cout << mar[1][1] << endl;
	// cout << mar[5] << endl; //return error
	Solution s;
	cout << s.searchMatrix (mar, 5) << endl;
	
	return 0;
}