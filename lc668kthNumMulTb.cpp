
/*
Leetcode 668. Kth Smallest Number in Multiplication Table

Companies 
Google 
Related Topics 
Binary Search 
Similar Questions 
Kth Smallest Element in a Sorted Matrix, Find K-th Smallest Pair Distance, 
K-th Smallest Prime Fraction

Next challenges: Find K-th Smallest Pair Distance, K-th Smallest Prime Fraction

Test Cases:
1
3
3
3
3
5
3
3
3
2
3
6



*/

// Runtime: 246 ms
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
		// binary search, O(log(n*m)*m*log(n)) time; k in [1, m * n] 
        int b=0, e=m*n+1, mid=b+(e-b)/2, rb=rnk(b,m,n), re=rnk(e,m,n), rm=rnk(mid,m,n), mn=m*n, t;
		k--;// [0,m*n-1] 
        if(n<m){
            t=n;
            n=m;
            m=t;
        }
		
		while( rb+1<re&&b+1<e&&rm!=k ){// find mid w/ smaller closer k-1 elements: (b,e)
			if(rm<k){
                b=mid;
                rb=rm;
            }else{
                e=mid;
                re=rm;
            }

			mid=b+(e-b)/2;
            rm=rnk(mid,m,n);
		}
        //cout<<mid<<" "<<rm<<endl;
        
        // find the element exsiting in Multiplication Table, which is smallest element>mid in eaach row 
        for( int i=1; i<=m; i++){
            t=minLarger( mid, i, n);
            if(t!=n+1&&i*t<mn)  mn=i*t;
        }
		
		return mn;
    }
    
    int minLarger( int t, int i, int& n){// return the position of smallest element larger than mid in ith row 
        int b=0, e=n+1, mid;// b*i<t && t<e*i 
        
        while( b+1<e ){// stop when b+1==e 
            mid=b+(e-b)/2;
            if(mid*i<t)	b=mid;
            else	e=mid;
        }
        
        return e;
    }
	
	int rnk( int t, int& m, int& n){// return # elements smaller t, O(m*log(n)); could be optimized to O(m+n), saw in Discuss 
		int r=0, b, mid, e;
		
		for( int i=1; i<=m; i++){
			b=0;
			e=n+1;// b*i<t && t<=e*i
			
			while( b+1<e ){// stop when b+1==e 
				mid=b+(e-b)/2;
				if(mid*i<t)	b=mid;
				else	e=mid;
			}
			
			r+=b;
		}
		
		return r; 
	}
};
	

/*
// Runtime: 249 ms
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
		// binary search, O(log(n*m)*m*log(n)) time; k in [1, m * n] 
        int b=0, e=m*n+1, mid=b+(e-b)/2, rb=rnk(b,m,n), re=rnk(e,m,n), rm=rnk(mid,m,n), mn=m*n, t;
		k--;// [0,m*n-1] 
        if(n<m){
            t=n;
            n=m;
            m=t;
        }
		
		while( b+1<e&&rm!=k ){// find mid w/ smaller closer k-1 elements: (b,e)
			if(rm<k){
                b=mid;
                rb=rm;
            }else{
                e=mid;
                re=rm;
            }

			mid=b+(e-b)/2;
            rm=rnk(mid,m,n);
		}
        //cout<<mid<<" "<<rm<<endl;
        
        // find the element exsiting in Multiplication Table, which is smallest element>mid in eaach row 
        for( int i=1; i<=m; i++){
            t=minLarger( mid, i, n);
            if(t!=n+1&&i*t<mn)  mn=i*t;
        }
		
		return mn;
    }
    
    int minLarger( int t, int i, int& n){// return the position of smallest element larger than mid in ith row 
        int b=0, e=n+1, mid;// b*i<t && t<e*i 
        
        while( b+1<e ){// stop when b+1==e 
            mid=b+(e-b)/2;
            if(mid*i<t)	b=mid;
            else	e=mid;
        }
        
        return e;
    }
	
	int rnk( int t, int& m, int& n){// return # elements smaller t 
		int r=0, b, mid, e;
		
		for( int i=1; i<=m; i++){
			b=0;
			e=n+1;// b*i<t && t<=e*i
			
			while( b+1<e ){// stop when b+1==e 
				mid=b+(e-b)/2;
				if(mid*i<t)	b=mid;
				else	e=mid;
			}
			
			r+=b;
		}
		
		return r; 
	}
};

*/