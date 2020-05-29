/*
1359. Count All Valid Pickup and Delivery Options

Company	Doordash
Related Topics	Math, Dynamic Programming

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
Next challenges: Word Break II, 4 Keys Keyboard, Smallest Sufficient Team

https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/658386/C++-O(n)-Time-O(1)-Space-DP
*/
class Solution {
public:
    int countOrders(int n) {
        // Dynamic Programming, caldulate ways of insertion, easy; O(n) time, O(1) space; n in[1, 500]
        long sum=1;
        for( int i=1; i<=n; i++)	sum=sum*(2*i-1)*i%1000000007;// sum of 2*(n-1)+1, 2*(n-1), ..., 2, 1 = (2*n-1)*n
        return sum;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
*/
class Solution {
public:
    int countOrders(int n) {
        // Dynamic Programming, caldulate ways of insertion, easy; n in[1, 500]
        long sum=1;
        for( int i=1; i<=n; i++){
            sum=sum*(2*i-1)*i;// sum of 2*(n-1)+1, ..., 1 = (2*n-1)*n
            sum=sum%1000000007;
        }
        return sum;
    }
};