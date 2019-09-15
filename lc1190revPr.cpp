/*
1190. Reverse Substrings Between Each Pair of Parentheses

Companies   
Adobe
Related Topics 
Stack 

Test Cases:
"(abcd)"
"(u(love)i)"
"(ed(et(oc))el)"
"a(bcdefghijkl(mno)p)q"

Next challenges: Tag Validator, Basic Calculator IV, Longest Well-Performing Interval

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 8.5 MB
*/

class Solution {
public:
    string reverseParentheses(string s) {
        // O(n*n) time, stack 
        string rt, tp;
        vector<int> vp;
        
        for( int i=0; i<s.size(); i++){
            if(s[i]=='('){
                vp.push_back(rt.size());
            }else if(s[i]==')'){
                for( int j=vp.back(), k=rt.size()-1; j<k; ) swap( rt, j++, k--);
                vp.pop_back();
            }else{
                rt.push_back(s[i]);
            }
        }
        
        return rt;
    }
    
protected:
    void swap(string & rt, int j, int k){
        char c=rt[j];
        rt[j]=rt[k];
        rt[k]=c;
        return ;
    }
};