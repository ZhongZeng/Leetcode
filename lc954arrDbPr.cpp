
/*
954. Array of Doubled Pairs

Test Cases:
[3,1,3,6]
[4,-2,2,-4]
[1,2,1,-8,8,-4,4,-4,2,-2]

Related Topics: Array, Hash Table 

Runtime: 136 ms

*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        // hash table, O(n*log(n)) time         
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi, umj;
        int i;
        
        for( int i=0; i<A.size(); i++){
            umi=um.find(A[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(A[i],1);
        }
        
        sort(A.begin(), A.end());
        
        for( i=0; i<A.size()&&A[i]<0; i++){// greedy 
            umi=um.find(A[i]);
            if(umi->second!=0){
                umi->second-=1;
                
                if(A[i]%2!=0)   return false;
                else    umj=um.find(A[i]/2);                
                
                if(umj!=um.end()){
                    if(0<umj->second)   umj->second-=1;
                    else    return false;
                }else{
                    return false;
                }
            }
        }
        
        for( ; i<A.size(); i++){
            umi=um.find(A[i]);
            if(umi->second!=0){
                umi->second-=1;
                
                umj=um.find(A[i]*2);
                
                if(umj!=um.end()){
                    if(0<umj->second)   umj->second-=1;
                    else    return false;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
};