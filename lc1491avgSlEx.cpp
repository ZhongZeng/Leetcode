/*
1491. Average Salary Excluding the Minimum and Maximum Salary

Easy
Companies	Netsuite
Related Topics	Araay, Sort

Test Cases:
[4000,3000,1000,2000]
[8000,9000,2000,3000,6000,1000]

Runtime: 4 ms, faster than 59.75% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
Memory Usage: 7.1 MB, less than 66.67% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
Next challenges: Maximum Sum of 3 Non-Overlapping Subarrays,
Compare Strings by Frequency of the Smallest Character,
Smallest String With Swaps
*/

class Solution {
public:
    double average(vector<int>& salary) {
        // O(n) time; salary.size() in [3,100], salary[i] in [10**3,10**6]
        int min=salary[0], max=salary[0], sum=0;
        for( int i=0; i<salary.size(); i++){
            if(salary[i]<min)   min=salary[i];
            if(max<salary[i])   max=salary[i];
            sum+=salary[i];
        }
        
        return (sum-min-max)*1.0/(salary.size()-2);
    }
};