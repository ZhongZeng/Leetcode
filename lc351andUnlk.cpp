
/*
Leetcode 351. Android Unlock Patterns

Companies 
Google
Related Topics 
Dynamic Programming, Backtracking 

Next challenges: Add and Search Word - Data structure design, 
Guess Number Higher or Lower II, Split Array Largest Sum

Test Cases:
1
1
2
2
7
9

Runtime: 20 ms
Your runtime beats 63.02 % of cpp submissions.

*/

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        // 1-8 is possible; can skip only like 1-4-7 or 1-5-9 not 1-8-9 
        int sum=0;
        vector<int> vc={1,2,3,4,5,6,7,8,9}, vu(10,-1);// permutation, used-1      
        
        dfs( 0, m, n, sum, vc, vu);
        
        return sum;
    }
    
    void dfs( int j, int& m, int& n, int& sum, vector<int>& vc, vector<int>& vu){
        // permutation of first j elements in vc 
        if(m<=j&&j<=n)  sum++;
        if(j==n||j==9)  return ;
        
        for( int i=j, t; i<vc.size(); i++){
            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;
            vu[vc[j]]=1;
            
            if(j<1||isValid(vc[j-1],vc[j],vu))	dfs( j+1, m, n, sum, vc, vu);
            
            vu[vc[j]]=-1;
            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;
        }
        
        return ;
    }
    
    bool isValid( int& b, int& e, vector<int>& vu ){// O(1) time 
	
		switch(b){
			case 1:
				switch(e){
					case 3: return vu[2]==1;
					case 7: return vu[4]==1;
					case 9: return vu[5]==1;
					default: return true;
				}
			case 2:
				if(e!=8)	return true;
				else	return vu[5]==1;
			case 3:
				switch(e){
					case 1: return vu[2]==1;
					case 7: return vu[5]==1;
					case 9: return vu[6]==1;
					default: return true;
				}
			case 4:
				if(e!=6)	return true;
				else	return vu[5]==1;			
			case 5: return true;
			case 6:
				if(e!=4)	return true;
				else	return vu[5]==1;			
			case 7:
				switch(e){
					case 1: return vu[4]==1;
					case 3: return vu[5]==1;
					case 9: return vu[8]==1;
					default: return true;
				}
			case 8:
				if(e!=2)	return true;
				else	return vu[5]==1;			
			case 9:
				switch(e){
					case 1: return vu[5]==1;
					case 3: return vu[6]==1;
					case 7: return vu[8]==1;
					default: return true;
				}			
		}
		
        return false;
    }
};
