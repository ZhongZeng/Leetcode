

/*
Leetcode 532. K-diff Pairs in an Array

You are here! 
Your runtime beats 77.80 % of cpp submissions.	33 ms

Comments:
So many corner cases!!

Test Cases:
[1,3,1,5,4]
0
Expected:
1

[1,1,1,1,1]
0
Expected:
1

[1,1,1,2,2]
1
Expected:
1

[1,1,1,2,2]
0
Expected:
2

[1,2,3,4,5]
-1
Expected:
0

*/


class Solution {
public:	
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()<2)	return 0;
        
		sort(nums.begin(), nums.end());
		// mergeSort(nums, 0, nums.size());
		
		int c=0;
		int it=0,jt=1;
		if( 0<k ){
			while( jt!=nums.size() ){
				
				if( nums[jt]-nums[it] < k ){
					jt=nextNum(jt, nums);
				}else if( nums[jt]-nums[it] == k ){
					c++;
					it=nextNum(it, nums);
					jt=nextNum(jt, nums);
				}else{
					it=nextNum(it, nums);
				}			

				if( it==jt ){
					jt=nextNum(jt, nums);
				}            
			}
		}else if(k==0){
			while( it!=nums.size() ){
				if(nums[jt]==nums[it]){
					c++;
				}
				it=nextNum(it, nums);
				jt=it+1;
			}
		}else{
			return 0;
		}
		
		return c;		
    }
	
protected:
	int nextNum(int i, vector<int> & nums){
		while( i<nums.size()-1 ){
			if( nums[i+1]==nums[i] ){
				i++;
			}else{
				return i+1;
			}
		}		
		return nums.size();
	}

	void mergeSort(vector<int> v, int b, int e ){
		
		
		return ;
	}
	
	void merge(vector<int> v, int b, int e ){
		
		
		return ;
	}
	
};