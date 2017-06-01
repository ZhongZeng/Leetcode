
/*
Leetcode 413. Arithmetic Slices

You are here! 
Your runtime beats 5.45 % of cpp submissions.	6 ms
Your runtime beats 16.89 % of cpp submissions.	3 ms

Tags: Dynamic Programming, Math
Similar Problems: (H) Arithmetic Slices II - Subsequence
Next challenges: (H) Arithmetic Slices II - Subsequence

Test Case:
[1,2,3,4,6,8,10]
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        vector<int> v;
        int d=A[1]-A[0];
        int len=2;
        for(int i=2; i!=A.size(); i++){
            if(A[i]-A[i-1]==d){
                // cout<<A[i]<<" "<<len<<endl;
                len++;
            }else{
                // cout<<A[i]<<" "<<len<<endl;
                if(len!=2){
                    v.push_back(len);
                    len=2;
                }
                d=A[i]-A[i-1];
            }
        }
        if(len!=2) v.push_back(len);
        
        int sum=0;
        for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
            sum+=(*it-2)*(*it-1)/2;
        }
        
        return sum;
    }
};
