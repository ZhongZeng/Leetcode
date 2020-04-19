/*
1196. How Many Apples Can You Put into the Basket

Companies	Virtu Financial
Tags	Greedy

Runtime: 4 ms, faster than 95.65% of C++ online submissions for How Many Apples Can You Put into the Basket.
Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for How Many Apples Can You Put into the Basket.
Next challenges: Minimize Rounding Error to Meet Target
Number of Burgers with No Waste of Ingredients, Construct Target Array With Multiple Sums
*/

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        // greedy, sort
        int count=0;
        sort(arr.begin(), arr.end());
        for( int i=0, sum=0; i<arr.size(); count++, i++){
            if(sum+arr[i]<=5000)    sum+=arr[i];
            else    return count;
        }
        return count;
    }
};