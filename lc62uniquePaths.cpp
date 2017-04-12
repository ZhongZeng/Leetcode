

/*
Leetcode 62. Unique Paths
You are here! 
Your runtime beats 54.05% of cpp submissions. 0 ms
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        /* the solution is combination of m or n out of (m+n)
        m and n can be swaped*/
        double res=1;// int is not large enough
        int temp;
        if(n<m){
            temp=m;
            m=n;
            n=temp;
        }// m<=n
        
        for(int i=m, j=1; i!=m+n-1; i++, j++){// i [m, m+n+2]; j [1, n-1]
            res=res*i/j; //this can make sure res is always an integer
            // cout<<i<<" "<<j<<" "<<res<<endl;
            // if using int, the multiplication and division can't be seperated, or res would be too large
        }
        
        return res;
    }
};


int main(){

	return 0;
}
