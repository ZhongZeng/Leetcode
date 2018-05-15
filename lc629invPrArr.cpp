
/*

Leetcode 629. K Inverse Pairs Array

Companies 
Works Applications
Related Topics 
Dynamic Programming

Next challenges: Guess Number Higher or Lower II, Largest Sum of Averages, Race Car

Test Cases:
3
0
100
60
1000
1000

Runtime: 21 ms
Your runtime beats 80.49 % of cpp submissions.

*/


class Solution {
public:
    int kInversePairs(int n, int k) {
        // DP, O(n*k) time 
        // The integer n is in the range [1, 1000] and k is in the range [0, 1000]. 
		int t; 
        vector<int> vk(k+1, 0), uk;// # permutations of [:i] w/ j inverse pairs 
        vk[0]=1;
        
        for(int i=1; i<n; i++){
            uk={1};
            t=1;
            for(int j=1; j<k+1; j++){
                t=(t+vk[j])%1000000007;// inverst i in an permutation of [:i-1]
				if(0<j-i)	t=(t-vk[j-i-1]+1000000007)%1000000007;//-1<j-i-1
                //cout<<t<<" ";
				uk.push_back(t);
            }
            vk=uk;
        }
            
        return vk.back();
    }
};
