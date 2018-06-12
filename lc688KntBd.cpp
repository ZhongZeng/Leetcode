
/*
Leetcode 688. Knight Probability in Chessboard

Companies 
Goldman Sachs 
Related Topics 
Dynamic Programming 
Similar Questions 
Out of Boundary Paths

Next challenges: Dungeon Game, Largest Divisible Subset, Palindromic Substrings

Test Cases:
1
0
0
0

3
2
1
2

8
30
6
4

Runtime: 5 ms
Your runtime beats 97.99 % of cpp submissions.

*/

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<double> vc(N,0);
		vector<vector<double>> vv(N,vc),vw(N,vc);
		double sum=0.0;
		vv[r][c]=1;
		
		for( int i=0; i<K; i++){
			for( int j=0; j<N; j++)	for( int k=0; k<N; k++)	vw[j][k]=0;
			
			for( int j=0; j<N; j++){
				for( int k=0; k<N; k++){
					if( 0<vv[j][k] ){
						if(0<j&&1<k)    vw[j-1][k-2]+=vv[j][k]/8.0;
						else	sum+=vv[j][k]/8.0;
						if(0<j&&k+2<N)	vw[j-1][k+2]+=vv[j][k]/8.0;
						else	sum+=vv[j][k]/8.0;
						if(j+1<N&&1<k)	vw[j+1][k-2]+=vv[j][k]/8.0;
						else	sum+=vv[j][k]/8.0;
						if(j+1<N&&k+2<N)	vw[j+1][k+2]+=vv[j][k]/8.0;
						else	sum+=vv[j][k]/8.0;
						if(1<j&&0<k)    vw[j-2][k-1]+=vv[j][k]/8.0;
						else	sum+=vv[j][k]/8.0;
						if(1<j&&k+1<N)	vw[j-2][k+1]+=vv[j][k]/8.0;
						else	sum+=vv[j][k]/8.0;
						if(j+2<N&&0<k)  vw[j+2][k-1]+=vv[j][k]/8.0;
						else	sum+=vv[j][k]/8.0;
						if(j+2<N&&k+1<N)	vw[j+2][k+1]+=vv[j][k]/8.0;
						else	sum+=vv[j][k]/8.0;
					}
                    //cout<<sum<<" ";
				}
			}
            vv=vw;
		}
		
		return 1.0-sum;
    }
};


/*
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        // TLE, O(8^k) time
        // cout<<posMov(3,1,2)<<endl;
        return K!=0 ? knightInBd( N, K, r, c) : 1; 
    }
    
    double knightInBd(int N, int K, int r, int c){
        // N-by-N chess board, K moves, (r, c)
        double cpsb=0;
        if( K!=1 ){
            if( -1<r-1 && -1<c-2)   cpsb += knightInBd(N, K-1, r-1, c-2) / 8;
            if( -1<r-2 && -1<c-1)   cpsb += knightInBd(N, K-1, r-2, c-1) / 8;
            if( -1<r-2 && c+1<N)    cpsb += knightInBd(N, K-1, r-2, c+1) / 8;
            if( -1<r-1 && c+2<N)    cpsb += knightInBd(N, K-1, r-1, c+2) / 8;
            if( r+1<N && c+2<N) cpsb += knightInBd(N, K-1, r+1, c+2) / 8;
            if( r+2<N && c+1<N) cpsb += knightInBd(N, K-1, r+2, c+1) / 8;
            if( r+1<N && -1<c-2)    cpsb += knightInBd(N, K-1, r+1, c-2) / 8;
            if( r+2<N && -1<c-1)    cpsb += knightInBd(N, K-1, r+2, c-1) / 8;            
        }else{
            cpsb = posMov( N, r, c) / 8.0;
        }        
        // cout<<r<<' '<<c<<' '<<cpsb<<endl;
        return cpsb;
    }
    
    double posMov(int N, int r, int c){
        int r1=0, r2=0, c1=0, c2=0;        
        if(-1<r-1){
            ++r1;
            if(-1<r-2)  ++r2;
        }
        
        if(r+1<N){
            ++r1;
            if(r+2<N)   ++r2;
        }
        
        
        if(-1<c-1){
            ++c1;
            if(-1<c-2)  ++c2;
        }
        
        if(c+1<N){
            ++c1;
            if(c+2<N)   ++c2;
        }
        
        return c1*r2 + c2*r1;
    }
    
};
*/
