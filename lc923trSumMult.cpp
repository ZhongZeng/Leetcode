

/*
Leetcode 923. 3Sum With Multiplicity

Test Cases:
[1,1,2,3]
6
[1,1,2,2,3,3,4,4,5,5]
8
[1,1,2,2,2,2]
5

Runtime: 8 ms
Your runtime beats 89.82 % of cpp submissions.

Next challenges: Split Array Largest Sum, Count The Repetitions, 
Maximum Sum of 3 Non-Overlapping Subarrays

*/

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        // O(n*n) time; hash table; mod 1000000007
        long rt=0, tg, a, b;
        vector<int> uq;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi;
        
        for( int i=0; i<A.size(); i++){
            umi=um.find(A[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(A[i],1);
        }
        
        for( umi=um.begin(); umi!=um.end(); umi++)  uq.push_back(umi->first);
        sort( uq.begin(), uq.end());
        
        for( int i=0; i<uq.size(); i++){
            a=um.find(uq[i])->second;
            
            if(uq[i]*3==target&&2<a)    rt=(rt+a*(a-1)*(a-2)/3/2)%1000000007;// uq[i]*3
            
            if(uq[i]*3<target&&1<a){// uq[i]*2+uq[j]
                umi=um.find(target-uq[i]*2);
                if(umi!=um.end())   rt=(rt+a*(a-1)/2*umi->second)%1000000007;
            }
            
            tg=target-uq[i];
            for( int j=i+1; j<uq.size(); j++){// uq[i]+uq[j]+uq[j<]
                b=um.find(uq[j])->second;
                
                if(uq[i]+uq[j]*2==target){
                    if(1<b) rt=(rt+a*b*(b-1)/2)%1000000007;
                    break;
                }

                if(tg/2<uq[j]){
                    break;
                }else{// A[j]==tg/2 
                    umi=um.find(target-uq[i]-uq[j]);
                    if(umi!=um.end())   rt=(rt+a*b*(umi->second))%1000000007;
                    //cout<<uq[i]<<","<<uq[j]<<":"<<rt<<"; "<<a<<" "<<b<<" "<<umi->second<<endl;
                }
            }
        }
        
        return rt;
    }
};
/*
[1,1,2,3]
6
[1,1,2,2,3,3,4,4,5,5]
8
[1,1,2,2,2,2]
5
*/