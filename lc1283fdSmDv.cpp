/*
1283. Find the Smallest Divisor Given a Threshold

Companies	Expedia
Related Topics	Binary Search

Test Cases:
[1,2,5,9]
6
[2,3,5,7,11]
11
[19]
5
[1,2,3]
6

Runtime: 48 ms	Your runtime beats 50.00 % of cpp submissions.
Memory Usage: 11.5 MB
*/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // binary search, O(n*log(1000001) time); nums[i] in [1,1000000]
        int b=0, e=1000001;// sumDiv(e)<=threshold<sumDiv(b), (b,e], imaginary b 
        while(b<e-1){
            int m=b+(e-b)/2, sum=sumDiv(nums, m);
            if(threshold<sum)   b=m;
            else    e=m;
        }
        return e;
    }
    
protected:
    int sumDiv(vector<int> & nums, int d){
        int sum=(0<d)?0:1;
        d=(0<d)?d:1;
        for( int i=0; i<nums.size(); i++)   sum+=nums[i]/d+(0<nums[i]%d);
        return sum;
    }
};