/*
1402. Reducing Dishes

Company	OT
Related Topics	Dynamic Programming (suggested: Greedy)
Hard (suggested: Medium or Easy)

Runtime: 4 ms, faster than 93.93% of C++ online submissions for Reducing Dishes.
Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Reducing Dishes.
Next challenges: 4 Keys Keyboard, Valid Palindrome III,
Build Array Where You Can Find The Maximum Exactly K Comparisons
*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // Array, Greedy; O(n*log(n)) time, O(1) space
        int mx, sat=0, sum=0;
        sort( satisfaction.begin(), satisfaction.end());
        
        for( int i=0; i<satisfaction.size(); i++){
            sat+=(i+1)*satisfaction[i];
            sum+=satisfaction[i];
        }
        mx=sat;
        
        for( int i=0; i<satisfaction.size()&&satisfaction[i]<0; i++){// removing negative dishes one-by-one, while keeping all positive dishes
            sat-=sum;// remove satisfaction[i] and move subsquent dishes left by 1
            sum-=satisfaction[i];
            if(mx<sat)  mx=sat;
        }
        
        return mx;
    }
};