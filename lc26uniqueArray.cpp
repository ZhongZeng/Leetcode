
/*
Leetcode 26 


Your runtime beats 78.65% of cpp submissions.
Your runtime beats 36.90% of cpp submissions.
Your runtime beats 95.28% of cpp submissions.
Data Structure and ALgorithm - Tsinghua University @edX 
Ch2 Vector
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size()==0) return 0;
		vector<int>::iterator it=nums.begin(), jt=nums.begin();
        while( it!=nums.end()){
            if( *it != *jt){
				// cout << nums[it]<<" "<<nums[jt] << endl;
                *(++jt) = *it;
            }           
			it++;
        }
		// nums.resize(jt+1);
		return ++jt-nums.begin();
    }
};

/*
// Your runtime beats 22.46% of cpp submissions.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size()==0) return 0;
		int it=0, jt=0;
        while( it!=nums.size()){
            if( nums[it] != nums[jt]){
				// cout << nums[it]<<" "<<nums[jt] << endl;
                nums[++jt] = nums[it];  						
            }           
			it++;
        }
		// nums.resize(jt+1);
		return ++jt;
    }
};

*/

int main(){
	Solution s;
	
	vector<int> vec1 = {1,1,2,3,4,4,5};
	vector<int> vec2 = {};
	int len1=s.removeDuplicates(vec1);
	int len2=s.removeDuplicates(vec2);
	for(int i=0; i!=len1; i++){
		cout << vec1[i] << endl;
	}
	
}
