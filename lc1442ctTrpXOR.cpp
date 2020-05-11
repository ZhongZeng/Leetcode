/*
1442. Count Triplets That Can Form Two Arrays of Equal XOR

Related Topcics	Array, Math, Bit Manipulation

Test Cases:
[2,3,1,6,7]
[1,1,1,1,1]
[2,3]
[1,3,5,7,9]
[7,11,12,9,5,2,7,17,22]

https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/discuss/625784/C%2B%2B-O(n)-Time-and-Space-20-line
*/

/*
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
Next challenges:
Minimum Factorization, Minimize Rounding Error to Meet Target, Robot Bounded In Circle
*/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // Prefix, Bit Manipulation; O(n) time&space; if X^Y=Z, X=Z^Y; if X==Y, X^Y==0
		int sum=0;
		unordered_map<int,pair<int,int>> prefix;// XOR of [0,k], count & sum of k - count
		prefix.emplace( 0, make_pair(1,1));// imaginary at -1 doesn't exist
		
		for( int i=0, x=0; i<arr.size(); i++){
			x=x^arr[i];
			unordered_map<int,pair<int,int>>::iterator it=prefix.find(x);
			if(it!=prefix.end()){
				sum+=i*it->second.first-it->second.second;
				it->second.first+=1;
				it->second.second+=i+1;
			}else{
				prefix.emplace( x, make_pair(1, i+1));
			}
		}
		
		return sum;
    }
};

/*
Runtime: 16 ms, faster than 100.00% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
Next challenges:
Minimum Factorization, Minimize Rounding Error to Meet Target, Robot Bounded In Circle
*/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // Prefix, Bit Manipulation; O(n*n) time, O(n) space; if X^Y=Z, X=Z^Y; if X==Y, X^Y==0
		int sum=0;
		unordered_map<int,vector<int>> prefix;// XOR of [0,k], {k}
		prefix.emplace(0,vector<int> {-1});
		
		for( int i=0, x=0; i<arr.size(); i++){
			x=x^arr[i];
			unordered_map<int,vector<int>>::iterator it=prefix.find(x);
			if(it!=prefix.end()){
				for( int j=0; j<it->second.size(); j++)
					sum+=i-it->second[j]-1;
				it->second.push_back(i);
			}else{
				prefix.emplace( x, vector<int> {i});
			}
		}
		
		return sum;
    }
};

/*
Runtime: 120 ms
Memory Usage: 7.5 MB
*/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // Array, Bit Manipulation; O(n**3) time; if X^Y=Z, X==Z^Y; arr.size in [1,300]
        if(arr.size()<1)    return 0;
        int count=0;
        
        for( int k=0, bk=0; k<arr.size(); k++){// bk: [0,k] XOR
            bk=bk^arr[k];
            for( int i=0, bi=0; i<k; i++){// bi: [0,i) XOR
                for( int j=i+1, ij=arr[i]; j<=k; j++){// ij:[i,j) XOR
                    if(ij==(bk^bi^ij))    count++;
                    ij=ij^arr[j];
                }
                bi=bi^arr[i];
            }
        }
        
        return count;
    }
};