
/*
Leetcode 22. Generate Parentheses

You are here! 
Your runtime beats 14.63 % of cpp submissions.	3 ms

Tags: Backtracking String
Similar Problems: (M) Letter Combinations of a Phone Number (E) Valid Parentheses
Next challenges: (M) Permutations II(H) Shortest Palindrome(M) Longest Uncommon Subsequence II

*/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vs={""},vs2; // vector of strings
        vector<int> vi={0},vi2; // vector of # of '(' 
        for(int i=0; i!=2*n; i++){
            // cout<<"i: "<<i<<endl;
            vector<string>::iterator vsi=vs.begin();
            vector<int>::iterator vii=vi.begin();
            while( vsi != vs.end() ){
                if( *vii < n){
                    vs2.push_back(*vsi+"(");
                    vi2.push_back(*vii+1);
                    // cout<<(*vsi+"( ")<<(*vii+1)<<" "<<i+1<<endl;
                }
                if( i/2 < *vii){
                    vs2.push_back(*vsi+")");
                    vi2.push_back(*vii);
                    // cout<<(*vsi+") ")<<*vii<<" "<<i+1<<endl;
                }
                vsi++;  vii++;
            }
            vs=vs2; vs2.clear();
            vi=vi2; vi2.clear();
            // cout<<endl;
        }
        
        return vs;
    }
};
