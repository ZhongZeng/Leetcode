
/*
59. Spiral Matrix II

Tags Array
Similar Problems (M) Spiral Matrix

Runtime: 6 ms
You are here! 
Your runtime beats 3.86 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r=0, c=0, ele=0;
        vector<int> vec0(n,1);
        vector<vector<int>> vec(n,vec0);
        while(0<n){
            for(int j=1; j<n; j++){vec[r][c++]=++ele;}//cout<<ele<<" ";cout<<endl;
            for(int j=1; j<n; j++){vec[r++][c]=++ele;}//cout<<ele<<" ";cout<<endl;
            for(int j=1; j<n; j++){vec[r][c--]=++ele;}//cout<<ele<<" ";cout<<endl;
            for(int j=1; j<n; j++){vec[r--][c]=++ele;}//cout<<ele<<" ";cout<<endl;
            r++;c++;
            n=n-2;
            //cout<<endl;
        }
        if(n==-1){
            vec[--r][--c]=++ele;
        }
        return vec;
    }
};

