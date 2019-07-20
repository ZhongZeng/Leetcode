/*
1085. Sum of Digits in the Minimum Number

Companies	Amazon
Related Topics	Array
Similar Questions	Add Digits

Test Cases:
[34,23,1,24,75,33,54,8]
[99,77,33,66,55]

Runtime: 4 ms
Memory Usage: 8.5 MB

Next challenges: My Calendar I, Maximum Sum Circular Subarray, Fibonacci Number
*/

class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        // O(m+log(n)) time, O(1) time
        int min=A[0], sum=0;
        for( int i=1; i<A.size(); i++)  min=A[i]<min?A[i]:min;
        for( int t=min; 0<t; t=t/10)    sum+=t%10;
        return sum%2==0;
    }
};