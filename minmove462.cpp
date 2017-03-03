
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        for (vector<int>::iterator it=nums.begin(); it<nums.end(); it++){
            sum += *it;
        }
        int avg = round (sum /1.0 / len);
        int inc=0;
        for (vector<int>::iterator it=nums.begin(); it<nums.end(); it++){
            inc += (*it > avg) ? (*it - avg):(avg - *it);
        }
        return inc;
    }
};

int main(){
	Solution s;
	vector<int> arr = { 1,0,0,8,6};
	cout << s.minMoves2(arr) << endl;
	return 0;
}