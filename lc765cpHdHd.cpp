

/*
Leetcode 765. Couples Holding Hands

Weekly Contest 67

Test Cases:
[0,2,1,3]
[3, 2, 0, 1]

Runtime: 3 ms

*/

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        // greedy, sort
		// O(n*n) time 
        int i, j, t, sum=0;
        for(i=1; i<row.size(); i+=2){
            if(!isCp(row[i-1],row[i])){
                for(j=i+1; j<row.size(); j++){
                    if(isCp(row[i-1],row[j])){
                        break;
                    }
                }
                t=row[i];
                row[i]=row[j];
                row[j]=t;
                //cout<<i<<","<<j<<" ";
                sum++;
            }
        }
        return sum;
    }
    
    bool isCp(int a, int b){
        if(b<a) return isCp(b, a);
        return (b-a==1)&&(a%2==0);
    }
    
};
