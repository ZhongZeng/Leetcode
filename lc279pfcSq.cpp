

/*

Leetcode 279. Perfect Squares

Related Topics 
Math, Dynamic Programming, Breadth-first Search
Similar Questions 
Count Primes, Ugly Number II

Next challenges: Word Break II, Frog Jump, Minimum Window Subsequence

Test Cases:
5
8
12
89

Runtime: 55 ms
Your runtime beats 77.38 % of cpp submissions.

*/

class Solution {
public:
    int numSquares(int n) {
        // BFS
        vector<int> vc;
        vector<pair<int,int>> vs, vt;
        int c=1, t;
        for(int i=1; i<=n/i; i++){
            vc.push_back(i*i);
            if(vc.back()==n)    return 1;
            vs.push_back(make_pair(vc.back(),i-1));
        }
        
        while(true){
            c++;
            vt.clear();
            for(int i=0; i<vs.size(); i++){
                for(int j=vs[i].second; -1<j; j--){
                    t=vs[i].first+vc[j];
                    if(t==n)    return c;
                    else if(t<n)  vt.push_back(make_pair(t,j));
                }
            }
            
            c++;
            vs.clear();
            for(int i=0; i<vt.size(); i++){
                for(int j=vt[i].second; -1<j; j--){
                    t=vt[i].first+vc[j];
                    if(t==n)    return c;
                    else if(t<n)  vs.push_back(make_pair(t,j));
                }
            }            
        }
        
        return -1;
    }
};
