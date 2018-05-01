

/*

Leetcode 446. Arithmetic Slices II - Subsequence

Companies 
Baidu 
Related Topics 
Dynamic Programming 
Similar Questions 
Arithmetic Slices

Test Cases:
[2,4,6,8,10]
[2,2,3,4]
[0,2000000000,-294967296]
[]

*/

// Runtime: 647 ms
// Your runtime beats 30.23 % of cpp submissions.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
		// O(n**2) time; corner cases: equal values, INT_MIN 
        int sum=0;
		long d; 
		
		unordered_map<long, int> um;// distance, # of elements
		unordered_map<long, int>::iterator umi, umj;
		list<unordered_map<long, int>> vd(A.size(), um) ;// use list instead of vector to speed up modification
		list<unordered_map<long, int>>::iterator vi=vd.begin(), vj; 
		
		for(int i=0; i<A.size(); i++, vi++){// subarrays ending @ i 
			vj=vd.begin(); 
			for(int j=0; j<i; j++, vj++){// subarrays w/ distance==d 
				d=(long)A[i]-A[j];//(long)(A[i]-A[j]) is WRONG, since int is already truncated before cast
				umj=vj->find(d);
				if(umj!=vj->end()){
					sum+=umj->second;
					
					umi=vi->find(d);
					if(umi!=vi->end())	umi->second+=umj->second+1;
					else	vi->emplace(d, umj->second+1);
				}else{
					umi=vi->find(d);
					if(umi!=vi->end())	umi->second+=1;
					else	vi->emplace(d, 1); 
				}
			}
		}
		
		return sum;
    }
};

/*
// Runtime: 695 ms	Your runtime beats 22.33 % of cpp submissions.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
		// O(n**2) time; corner cases: equal values, INT_MIN 
        int sum=0;
		long d; 
		
		unordered_map<long, int> um;// distance, # of elements
		unordered_map<long, int>::iterator umi, umj;
		vector<unordered_map<long, int>> vd(A.size(), um) ; 
		
		for(int i=1; i<A.size(); i++){// subarrays ending @ i 
			for(int j=0; j<i; j++){// subarrays w/ distance==d 
				d=(long)A[i]-A[j];//(long)(A[i]-A[j]) is WRONG, since int is already truncated before cast
                //cout<<d<<" "; 
				umj=vd[j].find(d);
				if(umj!=vd[j].end()){
					sum+=umj->second;
					
					umi=vd[i].find(d);
					if(umi!=vd[i].end())	umi->second+=umj->second+1;
					else	vd[i].emplace(d, umj->second+1);
				}else{
					umi=vd[i].find(d);
					if(umi!=vd[i].end())	umi->second+=1;
					else	vd[i].emplace(d, 1); 
				}
			}
		}
		
		return sum;
    }
};
*/