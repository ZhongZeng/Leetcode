

/*
Leetcode 27. Remove Element

You are here! 
Your runtime beats 2.77% of cpp submissions. 
Your runtime beats 78.54% of cpp submissions.


The order of elements can be changed. 
It doesn't matter what you leave beyond the new length.

*/


#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		if(nums.size()==0) return 0;
        vector<int>::iterator it=--nums.begin(), jt=nums.end();
		while(! (++it> jt)){
			if(*it== val){
				do{
					jt--;
				}while(*jt==val);
				*it = *jt;
			}
		}
		
		return --it-nums.begin();
    }
};

int main(){
	Solution s;
	vector<int> arr1 = {1, 1, 1, 2, 3, 4, 5};
	vector<int> arr2 = {};
	vector<int> arr3 = {3, 2, 2, 3};
	cout<<"arr1 "<<s.removeElement(arr1, 1)<<endl;
	cout<<"arr2 "<<s.removeElement(arr2, 1)<<endl;
	cout<<"arr3 "<<s.removeElement(arr3, 3)<<endl;
	for(int i=0; i!=arr3.size(); i++) cout<<arr3[i]<<endl;
	
	
	return 0;
}
