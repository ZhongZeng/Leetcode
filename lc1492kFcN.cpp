/*
1492. The kth Factor of n
Medium
Companies	Expedia
Related Topics	Math

Test Cases:
24
6
12
3
7
2
4
4
1
1
2
1
2
2
*/

/*
Runtime: 4 ms, faster than 38.88% of C++ online submissions for The kth Factor of n.
Memory Usage: 6.1 MB, less than 33.33% of C++ online submissions for The kth Factor of n.
Next challenges: Convex Polygon, Largest Triangle Area, Ugly Number III
*/
class Solution {
public:
    int kthFactor(int n, int k) {
        // O(n) time&space; k<=n in [1,1000]; concer case: 1, 2, 3
		vector<int> factors;
		
        for( int f=1, l=sqrt(n+1); f<=l; f++){
            if(n%f==0){
				factors.push_back(f);
				if(factors.size()==k)	break;
			}
        }
        
		if(factors.size()==k){
			return factors.back();
		}else if(factors.back()*factors.back()==n){// factor.size()<k guranteed
			if(k<=factors.size()*2-1)	return n/factors[factors.size()*2-1-k];
			else	return -1;
		}else{// factor.size()<k guranteed
			if(k<=factors.size()*2)	return n/factors[factors.size()*2-k];
			else	return -1;
		}
    }
};

/*
Runtime: 4 ms, faster than 38.88% of C++ online submissions for The kth Factor of n.
Memory Usage: 6.1 MB, less than 33.33% of C++ online submissions for The kth Factor of n.
Next challenges: Convex Polygon, Largest Triangle Area, Ugly Number III
*/
class Solution {
public:
    int kthFactor(int n, int k) {
        // O(n) time, O(1) space; k<=n in [1,1000]; concer case: 1, 2, 3
        int i, f;
        for( i=0, f=1; f<=(n+1)/2; f++){
            if(n%f==0&&(++i==k))    break;
        }
        
        if(i==k)    return f;
        else if(i==k-1) return n;
        else    return -1;
    }
};