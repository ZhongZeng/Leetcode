
/*
Leetcode 674. Longest Continuous Increasing Subsequence

Related Topics 
Array 
Similar Questions 
Number of Longest Increasing Subsequence 

Runtime: 16 ms

You are here! 
Your runtime beats 22.05 % of cpp submissions.

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<1)  return 0;
        int len=1, maxlen=1;
        for(vector<int>::iterator it=nums.begin(); it!=nums.end()-1; ){
            //cout<< *it << ' ' << len << endl;
            if( *it++ < *it){
                len++;
            }else{
                if(maxlen<len)  maxlen = len;
                len = 1;
            }
            //cout<< *it << ' ' << len << endl;
        }
        if(maxlen<len)  maxlen = len;
        
        return maxlen;
    }
};

int main(){
	Solution s;
	vector<int> a,b,c,d;
	a={};
	b={1};
	c={1,2};
	d={1,2,4,5,2,3};
	cout << s.findLengthOfLCIS(a) << endl;
	cout << s.findLengthOfLCIS(b) << endl;
	cout << s.findLengthOfLCIS(c) << endl;
	cout << s.findLengthOfLCIS(d) << endl;	
	
	return 0;
}

