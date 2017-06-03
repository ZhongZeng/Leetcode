
/*
Leetcode 357. Count Numbers with Unique Digits

You are here! 
Your runtime beats 12.37 % of cpp submissions.	3 ms 
Your runtime beats 36.95 % of cpp submissions.	0 ms

Tag:  Dynamic Programming, Backtracking, Math
Next challenges: (H) Burst Balloons(M) Is Subsequence(E) Arranging Coins


*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // answers are the same for all n>=10
        if(10<n){ // 10< n
            return countNumbersWithUniqueDigits(10);
        }else if(1<n){ // n<11 && 1<n
            return countNumbersWithUniqueDigits(n-1)+permutation(9, n)+(n-1)*permutation(9, n-1);
        }else{ // 
            return 10;
        }
        
    }
    
protected:
    int permutation(int m, int n){ // permutate n out of m
        int p=1;
        for(int i=m; i!=m-n; i--){
            p=p*i;
        }
        return p;
    }

};
