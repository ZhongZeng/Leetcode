
/*

955. Delete Columns to Make Sorted II

Test Cases:
["ca","bb","ac"]
["xc","yb","za"]
["zyx","wvu","tsr"]
["doeeqiy","yabhbqe","twckqte"]

Related Topics: Greedy 

Runtime: 8 ms

*/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // greedy, O(m*n) time 
        if(A.size()<1||A[0].size()<1)   return 0;
        int rt=0, i, j, k;
        vector<int> od(A.size(),0);
        
        for( i=0; i<A[0].size(); i++){
            bool dlt=false;
            vector<int> ot(A.size(),0);
            for( j=1; j<A.size(); j++){
                if(od[j]==0){
                    if(A[j-1][i]<A[j][i]){// A[j-1] smaller than A[j]
                        ot[j]=1;
                    }else if(A[j-1][i]>A[j][i]){// A[j-1] larger than A[j]
                        rt++;
                        dlt=true;
                        break;
                    }
                }
            }
            if(dlt==false){
                for( k=0; k<ot.size(); k++) if(ot[k]==1)    od[k]=1;
            }
        }
        
        return rt;
    }
};
