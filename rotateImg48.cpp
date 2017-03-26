
/*
Leetcode 48. Rotate Image
You are here! 
Your runtime beats 12.77% of cpp submissions.
Your runtime beats 63.84% of cpp submissions.
*/

#include<vector>
#include<iostream>
using namespace std;

/*
(i, j) -> 
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(), len=n-1;
        int tem;
        for(int i=0; i!=n/2; i++){
            for(int j=0; j!=(n+1)/2; j++){
                tem=matrix[i][j];
                matrix[i][j]=matrix[len-j][i];
                matrix[len-j][i]=matrix[len-i][len-j];
                matrix[len-i][len-j]=matrix[j][len-i];
                matrix[j][len-i]=tem;
            }
        }
        return;
    }
};

int main(){
	vector<vector<int>> m1={{1,2},{3,4}};
	Solution s;
	s.rotate(m1);
	for(int i=0; i!=m1.size(); i++){
		for(int j=0; j!=m1.size(); j++){
			cout << m1[i][j] <<" ";
		}
		cout << endl;
	}
}

