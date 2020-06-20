/*
1340. Jump Game V

Hard
Companeis	
Releated Topics	Dynamic Programming

Test Cases:
[6,4,14,6,8,13,9,7,10,6,12]
2
[3,3,3,3,3]
3
[7,6,5,4,3,2,1]
1
[7,1,7,1,7,1]
2
[66]
1

Runtime: 48 ms, faster than 91.63% of C++ online submissions for Jump Game V.
Memory Usage: 14.9 MB, less than 73.77% of C++ online submissions for Jump Game V.
Next challenges: Dungeon Game, Handshakes That Don't Cross, Longest Common Subsequence
*/

/*
Every element i can only be visited from j in [i-d, i) (i, i+d], where arr[i]<arr[j]. 
This is a Directed Acyclic Graph with n nodes and n*2*d edges. 
Thus, O(n*d) time . 
*/
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        // Dynamic Programming, DFS+Memorization
        int mx=0;
        vector<int> jp(arr.size(), -1);
        for( int i=0; i<arr.size(); i++){
            dfs( i, d, arr, jp);
            mx=mx<jp[i]?jp[i]:mx;
        }
        return mx;
    }
    
protected:
    int dfs( int p, int & d, vector<int> & arr, vector<int> & jp){
        if(jp[p]!=-1)   return jp[p];
        int mx=1;
        for( int i=1; i<=d&&-1<p-i; i++){
            if(arr[p-i]<arr[p]){
                int t=dfs( p-i, d, arr, jp)+1;
                mx=mx<t?t:mx;
            }else{
                break;
            }
        }
        for( int i=1; i<=d&&p+i<arr.size(); i++){
            if(arr[p+i]<arr[p]){
                int t=dfs( p+i, d, arr, jp)+1;
                mx=mx<t?t:mx;
            }else{
                break;
            }
        }
        jp[p]=mx;
        return mx;
    }
};