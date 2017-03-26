
/*
Leetcode 283. Move Zeroes

You are here! 
Your runtime beats 29.65% of cpp submissions.
Your runtime beats 48.38% of cpp submissions.
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		vector<int>::iterator it=--nums.begin(),jt=nums.begin();
        while( ++it!=nums.end()){
            // cout<<*it<<endl;
			if(*it!=0){
                *jt++ = *it;
            }
        }
		while(jt != nums.end()){
			*jt++ = 0;
		}
		// cout<<endl;
        return;
    }
};

int main(){
	Solution s;
	vector<int> arr1={0,2,0,4,5};
	s.moveZeroes(arr1);
	for(int i=0;i!=arr1.size();i++)
		cout<<arr1[i]<<endl;
	
	return 0;
}