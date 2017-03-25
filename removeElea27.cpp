

/*
Leetcode 27. Remove Element

You are here! 
Your runtime beats 2.77% of cpp submissions. 
Your runtime beats 17.69% of cpp submissions.

The order of elements can be changed. 
It doesn't matter what you leave beyond the new length.

*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it=nums.begin()--, jt=nums.begin();
		while (it!=nums.end()){
			if(*it!=val){
				*jt++ = *it;
			}
			it++;
		}
		
		return jt-nums.begin();
    }
};

int main(){
	Solution s;
	vector<int> arr1 = {1, 2, 3, 4, 5};
	vector<int> arr2 = {};
	s.removeElement(arr1, 1);
	s.removeElement(arr2, 1);
	for(int i=0; i!=arr1.size(); i++) cout<<arr1[i]<<endl;
	
	
	return 0;
}
