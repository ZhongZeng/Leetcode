

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
[2147483638,2147483639,2147483640,2147483641,2147483642,2147483643,2147483644,2147483645,2147483646,2147483647,-2147483648,-2147483647,-2147483646,-2147483645,-2147483644,-2147483643,-2147483642,-2147483641,-2147483640,-2147483639]

Runtime: 320 ms, faster than 66.97% of C++ online submissions for Arithmetic Slices II - Subsequence.

*/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        // DP, O(n*n) time 
        int n, sum=0;
        long d;
        unordered_map<long,int> vm;
        vector<unordered_map<long,int>> vu(1,vm);// ending @ vu[i]: distance, # of sequence
        unordered_map<long,int>::iterator umi;
        
        for( int i=1; i<A.size(); i++){
            unordered_map<long,int> um;
            for( int j=0; j<i; j++){
                d=(long)A[i]-A[j];
                if(INT_MAX<d||d<INT_MIN)    continue;
                
                umi=vu[j].find(d);
                if(umi!=vu[j].end()){
                    sum+=umi->second;
                    n=umi->second+1;
                }else{
                    n=1;
                }
                
                umi=um.find(d);
                if(umi!=vu[i].end())    umi->second+=n;
                else    um.emplace(d,n);
            }
            vu.push_back(um);
        }
        
        return sum;
    }
};


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