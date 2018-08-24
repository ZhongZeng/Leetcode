
/*
Leetcode 795. Number of Subarrays with Bounded Maximum

Companies   
Adobe 
Related Topics 
Array 

Next challenges: Best Time to Buy and Sell Stock with Transaction Fee, 
Range Module, My Calendar II

[2,1,4,3]
2
3
[73,55,36,5,55,14,9,7,72,52]
32
69
[73,55,36,5,55,14]
32
69
[876,880,482,260,132,421,732,703,795,420,871,445,400,291,358,589,617,202,755,810,227,813,549,791,418,528,835,401,526,584,873,662,13,314,988,101,299,816,833,224,160,852,179,769,646,558,661,808,651,982,878,918,406,551,467,87,139,387,16,531,307,389,939,551,613,36,528,460,404,314,66,111,458,531,944,461,951,419,82,896,467,353,704,905,705,760,61,422,395,298,127,516,153,299,801,341,668,598,98,241]
658
719
[769,646,558,661]
658
719

Runtime: 24 ms
Your runtime beats 98.64 % of cpp submissions.

*/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        // O(n) time, array, 2-pointer; # continuous&non-empty subarray
		int sum=0;
		
		for( int b=-1, e=-2, i=0; i<A.size(); i++){ // count subarray ending @ i; b: 1st A[b]<=R; e: last A[e] in [L,R]
			if(A[i]<L){
				if(b<0||R<A[b])	b=i;
				if(b<=e)	sum+=e-b+1;// all subarrys ending @ i & starting @ [b,e] 
			}else if(R<A[i]){// strike breaks 
				b=i;
				e=i-1;
			}else{// A[i] in [L,R] 
				e=i;
				if(b<0||R<A[b])	b=i;
				sum+=i-b+1;// all subarrays ending @ i & starting @ [b,i] 
			}
			//cout<<sum<<" ";
		}
		
		return sum;
    }
};

