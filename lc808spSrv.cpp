/*
808. Soup Servings

Medium
Companies	Google
Related Topics	Dynamic Programming

Test Cases:
50
800
660295675

Runtime: 4 ms, faster than 65.43% of C++ online submissions for Soup Servings.
Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Soup Servings.
Next challenges: Create Maximum Number, Smallest Sufficient Team, Maximum Profit in Job Scheduling

TO READ: https://leetcode.com/problems/soup-servings/discuss/195582/A-Mathematical-Analysis-of-the-Soup-Servings-Problem
*/

class Solution {
public:
    double soupServings(int N) {
        // Dynamic Programming, Memorization; O(4*N*N/25/25) time, O(N*N/25/25) space; 25-increment
        if (N >= 5000)  return 1.0;// CHEATING
        int n=N/25+(N%25==0?0:1);
        vector<vector<pair<double,double>>> pb(n+1, 
            vector<pair<double,double>> (n+1, make_pair(-1,-1)));// a, b
        pair<double,double> pr=dp( n, n, pb);
        return pr.first+(1-pr.first-pr.second)/2.0;
    }
    
protected:
    pair<double,double> dp( int a, int b, 
        vector<vector<pair<double,double>>> & pb){// remaining a and b
        if(a<=0)    return make_pair(b<=0?0:1, 0);
        else if(b<=0)   return make_pair(0, 1);
        if(pb[a][b].first!=-1)  return pb[a][b];// TLE if missing this line
        
        pair<double,double> pr1=dp(a-4, b, pb), pr2=dp(a-3, b-1, pb), 
            pr3=dp(a-2, b-2, pb), pr4=dp(a-1, b-3, pb);
        double a_empty_first=(pr1.first+pr2.first+pr3.first+pr4.first)/4.0, 
            b_empty_first=(pr1.second+pr2.second+pr3.second+pr4.second)/4.0;
        
        pb[a][b]=make_pair(a_empty_first, b_empty_first);
        
        return make_pair(a_empty_first, b_empty_first);
    }
};