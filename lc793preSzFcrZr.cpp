
/*
Leetcode 793. Preimage Size of Factorial Zeroes Function

Companies   
Adobe 
Related Topics 
Binary Search 
Similar Questions 
Factorial Trailing Zeroes

Next challenges: Dungeon Game, Find K-th Smallest Pair Distance, Super Egg Drop

Test Cases:
0
1000
1000000000

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    int preimageSizeFZF(int K) {
		// K==(t-1)/4 
		long b, e, mid, tb, te, tm, tg, i1, i2;// [b,e):K,K+1 ; INT_MAX:536870902 
		
		for( b=-1, e=10000000000, tg=K; b+1<e; ){
			mid=b+(e-b)/2;
			tm=trialZero(mid);
			
			if(tg<tm){
				e=mid;
				te=tm;
			}else{
				b=mid;
				tb=tm;
			}
		}
		i1=b;
		
		for( b=-1, e=i1+2, tg=K-1; b+1<e; ){
			mid=b+(e-b)/2;
			tm=trialZero(mid);
			
			if(tg<tm){
				e=mid;
				te=tm;
			}else{
				b=mid;
				tb=tm;
			}
		}
		i2=b;
		
		return i1-i2;
    }

protected:
	long trialZero( long n ){
        if(n<0) return -1;
		else if(n<5) return 0;
		
		long sum=0;
		while(0<n){
			n=n/5;
			sum+=n;
		}
		return sum;
	}
};
