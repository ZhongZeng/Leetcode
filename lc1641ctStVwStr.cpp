/*
1641. Count Sorted Vowel Strings

Medium

Companies:	Amazon 
Related Topics:	Math, Dynamic Programming, Backtracking

Runtime: 0 ms	
Memory Usage: 6.2 MB	
*/

class Solution {
public:
    int countVowelStrings(int n) {
        // Dynamic Programming; O(n) time
        int sum=0;
        vector<int> counts( 5, 1);
        for( int i=2; i<=n; i++){
            for( int j=counts.size()-2; -1<j; j--)
                counts[j]+=counts[j+1];
        }
        for( int i=0; i<counts.size(); i++)
            sum+=counts[i];
        return sum;
    }
};