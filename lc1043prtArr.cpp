/*
1043. Partition Array for Maximum Sum

Next challenges: Reconstruct Itinerary, All Paths from Source Lead to Destination, K-Similar Strings

Test Case:
[1,15,7,9,2,5,10]
3

Runtime: 12 ms	Your runtime beats 96.02 % of cpp submissions.
Memory Usage: 9.5 MB
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        // DP; O(N*K) time, O(K) space
        if(A.size()<1)  return 0;
        int rt, mx, i, j, t;
        list<int> qu;// used as a queue
        list<int>::reverse_iterator li;
        
        for( i=0, mx=A[0]; i<K; i++){// group up to K for 1st K elements
            mx=mx<A[i]?A[i]:mx;
            qu.push_back(mx*(i+1));
        }
        
        for( i=K; i<A.size(); i++){// qu.size()==K
            for( j=0, li=qu.rbegin(), mx=A[i], rt=(*li)+A[i]; j<K; j++, li++){
                mx=mx<A[i-j]?A[i-j]:mx;
                t=(*li)+mx*(j+1);
                if(rt<t)    rt=t;
            }
            qu.push_back(rt);
            qu.pop_front();
        }
        
        return qu.back();
    }
};
