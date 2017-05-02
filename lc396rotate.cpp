/*
Leetcode 396
You are here! 
Your runtime beats 45.23% of cpp submissions.
*/


#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        int res=0; // result
        int sum=0; // sum of array elements
        int ele; // elements in the array
        for (int i = 0; i<len; i++){
            ele = A[i];
            res += i*ele;
            sum += ele;
        }
        
        int resi = res;// result in ith iteration
        for (int j = 1; j<len; j++){
            ele = A[len-j]; // the element weighing 0
            resi = resi + sum - ele*len; 			
            // resti = reti + (sum - ele) - ele*(len-1);
            // by looking into the relationship between adjcent two results
            if (resi > res) res = resi;
        }
        
        return res;
    }
};

int main(){
	vector<int> arr = {4,3,2,6};
	Solution s;
	cout << s.maxRotateFunction(arr) << endl;
	
}


