/*
375. Guess Number Higher or Lower II

Medium
Companies	Google
Minmax	Dynamic Programming, Minimax

Next challenges: Flip Game II, Can I Win

Test Cases:
1
2
3
10
100


*/

/*

Runtime: 80 ms, faster than 17.56% of C++ online submissions for Guess Number Higher or Lower II.
Memory Usage: 6.8 MB, less than 37.17% of C++ online submissions for Guess Number Higher or Lower II.
Runtime: 60 ms, faster than 42.21% of C++ online submissions for Guess Number Higher or Lower II.
Memory Usage: 6.9 MB, less than 23.26% of C++ online submissions for Guess Number Higher or Lower II.
*/
class Solution {
public:
    int getMoneyAmount(int n) {
        // Minmax, Dynamic Programming, Memorization; gurantee a win
        vector<vector<int>> um(n+1, vector<int> (n+2,-1));// um[b][e]=cost
        return maxpay(1, n+1, um);
    }
    
protected:
    int maxpay( int b, int e, vector<vector<int>> & um){// [b,e)
        if(e-1<=b)  return 0;// b==e-1||e
        if(um[b][e]!=-1)	return um[b][e];
        int mn=-1;
        for( int i=b; i<e; i++){
            // max part; no need to consider target == i
            int p1=maxpay(b,i,um)+i, p2=maxpay(i+1,e,um)+i, p=p1<p2?p2:p1;// i+1 not i for p2
            if(mn==-1||p<mn)    mn=p;// min part
        }
        um[b][e]=mn;
        return mn;
    }
};

/*
Runtime: 1208 ms, faster than 5.12% of C++ online submissions for Guess Number Higher or Lower II.
Memory Usage: 9.4 MB, less than 5.06% of C++ online submissions for Guess Number Higher or Lower II.
Runtime: 1200 ms, faster than 5.12% of C++ online submissions for Guess Number Higher or Lower II.
Memory Usage: 9.2 MB, less than 5.06% of C++ online submissions for Guess Number Higher or Lower II.

Hash Table is slow in mutation 
*/
class Solution {
public:
    int getMoneyAmount(int n) {
        // Minmax, Dynamic Programming, Memorization; gurantee a win
        unordered_map<int,unordered_map<int,int>> um;// b, e, cost
        return maxpay(1, n+1, um);
    }
    
protected:
    int maxpay( int b, int e, unordered_map<int,unordered_map<int,int>> & um){// [b,e)
        if(e-1<=b)  return 0;// b==e-1||e
        if(um[b][e]!=NULL)  return um[b][e];
        int mn=-1;
        for( int i=b; i<e; i++){
            // max part; no need to consider target == i
            int p1=maxpay(b,i,um)+i, p2=maxpay(i+1,e,um)+i, p=p1<p2?p2:p1;// i+1 not i for p2
            if(mn==-1||p<mn)    mn=p;// min part
        }
        um[b][e]=mn;
        return mn;
    }
};