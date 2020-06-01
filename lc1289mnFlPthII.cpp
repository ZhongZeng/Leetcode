/*
1289. Minimum Falling Path Sum II

Hard (suggested: Medium)
Companies	Google
Related Topics	Dynamic Programming

Test Case:
[[1,2,3],[4,5,6],[7,8,9]]

Runtime: 60 ms, faster than 82.48% of C++ online submissions for Minimum Falling Path Sum II.
Memory Usage: 13.4 MB, less than 100.00% of C++ online submissions for Minimum Falling Path Sum II.
Next challenges: Soup Servings, Least Operators to Express Number,
Minimum Difficulty of a Job Schedule
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        // Dynamic Programming; Medium
        if(arr.size()<1||arr[0].size()<2)   return 0;
        int mn;
        vector<int> vc(arr[0].size(),0);
        
        for( int i=0; i<arr.size(); i++){
            pair<int,int> p1, p2;// value, position; only 1st and 2nd smallest matter
            if(vc[0]<vc[1]){
                p1=make_pair(vc[0],0);
                p2=make_pair(vc[1],1);
            }else{
                p1=make_pair(vc[1],1);
                p2=make_pair(vc[0],0);
            }
            for( int j=2; j<vc.size(); j++){// use 2 instead of 0 or 1
                if(vc[j]<p1.first){
                    p2=p1;
                    p1=make_pair(vc[j], j);
                }else if(vc[j]<p2.first){
                    p2=make_pair(vc[j], j);
                }
            }
            
            for( int j=0; j<vc.size(); j++) vc[j]=(j!=p1.second?p1.first:p2.first)+arr[i][j];
        }
        
        mn=vc[0];
        for( int i=0; i<vc.size(); i++) mn=mn<vc[i]?mn:vc[i];
        return mn;
    }
};