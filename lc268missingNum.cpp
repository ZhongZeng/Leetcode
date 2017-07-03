


/*
Leetcode 268 Missing Number

Next challenges: (H) First Missing Positive(E) Single Number(M) Find the Duplicate Number

You are here! 
Your runtime beats 69.83 % of cpp submissions.	23 ms

Test Cases:
[0]
1

[1]
0

[0,1,2]
3

[0,3,4,1]
2

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int m=0, sum=0, t, z=0;
		for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
			sum+=*it;
			if( m<*it ){
				m=*it;
			}else if( 0==*it){
				z=1;
			}
		}
		
		if(z==0){
			return 0;
		}else{ // z==1
			t=m*(m+1)/2-sum;		
			return t!=0 ? t : m+1 ;
		}
		
    }
};
