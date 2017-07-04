

/*
Leetcode 172. Factorial Trailing Zeroes

You are here! 
Your runtime beats 17.74 % of cpp submissions.	3 ms

Test Cases:
0
Expected:
0

1808548329
Expected:
452137076

*/

class Solution {
public:
    int trailingZeroes(int n) {
        // track how many fives, since twos are more than fives
		
		int sum=0, i=1;
        while( 0<n ){
            sum += n/5*i;
			n = n/5;
            // cout<< sum <<" "<<" "<<n<<endl;
        }
        return sum;
		
		/*
		// Following solution is wrong when n is very large 
		// due to exceeding largest int
		int sum=0, f=5, i=1;
        while( f<=n ){
            sum += n/f*i;
			f=f*5;
        }
        return sum;
		*/
    }
};
