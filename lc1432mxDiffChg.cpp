/*
1432. Max Difference You Can Get From Changing an Integer

Medium
Companies	mercari
Related Topics	String

Test Cases:
111
555
10000
9288

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Max Difference You Can Get From Changing an Integer.
Memory Usage: 6 MB, less than 59.56% of C++ online submissions for Max Difference You Can Get From Changing an Integer.
Next challenges: Text Justification, Greatest Common Divisor of Strings, Remove Palindromic Subsequences
*/

class Solution {
public:
    int maxDiff(int num) {
        // Greedy; O(n) time&space
        int i, add=-1, reduce=-1, reduce_to=-1, diff=0;
        vector<int> vc;
        for( int n=num; 0<n; n/=10) vc.push_back(n%10);
        
        for( int i=vc.size()-1; -1<i; i--){
            if(vc[i]!=9){
                add=vc[i];
                break;
            }
        }
        
        if(vc.back()!=1){
            reduce=vc.back();
            reduce_to=1;
        }else{
            for( int i=vc.size()-2; -1<i; i--){
                if(vc[i]!=0&&vc[i]!=1){
                    reduce=vc[i];
                    reduce_to=0;
                    break;
                }
            }
        }
        
        for( int i=0, ten=1; i<vc.size(); i++, ten*=10){
            if(vc[i]==add)  diff+=ten*(9-vc[i]);
            if(vc[i]==reduce)   diff+=ten*(vc[i]-reduce_to);
        }
        
        return diff;
    }
};