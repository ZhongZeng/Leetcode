/*
1390. Four Divisors

Companies	Capital One
Related Topics	Math

Test Cases:
[21,4,7]
[1,2,3,4,5,6,7,8,9,10]

Runtime: 28 ms, faster than 100.00% of C++ online submissions for Four Divisors.
Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Four Divisors.

Next challenges:
Find the Derangement of An Array, Confusing Number II, Ugly Number III
*/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for( int i=0; i<nums.size(); i++)   sum+=sumOfDivisors(nums[i]);
        return sum;
    }
    
protected:
    int sumOfDivisors( int num){
        int sq=sqrt(num), count=0, sum=0;// num in [sq*sq, (sq+1)*(sq+1)) <=> sq<=num/sq
        for( int i=1; i<=sq; i++){// corner case: 1
            if(4<count) return 0;
            int qt=num/i;
            if(qt*i==num){
                count+=2;
                sum+=qt+i;
            }
        }
        if(sq*sq==num){
            count--;
            sum-=sq;
        }
        return count==4?sum:0;
    }
};