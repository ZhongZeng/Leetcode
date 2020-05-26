/*
1092. Shortest Common Supersequence

Companies	Microsoft
Related Topics	Dynamic Programming
Similar Questions	Longest Common Subsequence

Runtime: 28 ms, faster than 62.66% of C++ online submissions for Shortest Common Supersequence .
Memory Usage: 13 MB, less than 100.00% of C++ online submissions for Shortest Common Supersequence .
Next challenges: Longest Common Subsequence

https://leetcode.com/problems/shortest-common-supersequence/discuss/653246/C++-Dynamic-Programming-O(n*m)-TimeandSpace
*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // Dynamic Programming, O(n*m) Time&Space
        int i, j, k, len;
        string str;
        vector<vector<int>> sp(str1.size()+1, vector<int> (str2.size()+1,0));// sp[i][j]==shortestCommonSupersequence(str1[0,i), str2[0,j)).size()
        for( i=0; i<=str1.size(); i++)  sp[i][0]=i;
        for( j=0; j<=str2.size(); j++)  sp[0][j]=j;
        for( i=0; i<str1.size(); i++){
            for( j=0; j<str2.size(); j++){
                len=(sp[i][j+1]<sp[i+1][j]?sp[i][j+1]:sp[i+1][j])+1;
                if(str1[i]==str2[j]&&sp[i][j]+1<len)    len=sp[i][j]+1;
                sp[i+1][j+1]=len;
            }
        }
        for( i=str1.size(), j=str2.size(); 0<i||0<j; ){
            if(j==0||(0<i&&sp[i][j]==sp[i-1][j]+1)){// avoid runtime error
                str.push_back(str1[--i]);
            }else if(i==0||sp[i][j]==sp[i][j-1]+1){
                str.push_back(str2[--j]);
            }else{// sp[i][j]==sp[i-1][j-1]+1
                str.push_back(str1[i-1]);// ==str2[j-1]
                i--;
                j--;
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};