
/*
Leetcode 842. Split Array into Fibonacci Sequence

Companies  
Amazon 
Related Topics 
String, Backtracking, Greedy 
Similar Questions 
Additive Number

Test Cases:
"123456579"
"11235813"
"112358130"
"0123"
"21021"
"02121"

Next challenges: Scramble String, Repeated Substring Pattern, Find And Replace in String

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
		// Backtrack; 2147483647; leetcode has a similar problem of splitIntoFibonacci
        vector<int> rt;
        if(S.size()<3)  return rt;
        int a=0, b, len=S[0]!='0'?S.size()-2:1;// corner case S[0]=='0'
        
        for( int i=0; i<len; i++){
            if(214748364<a||(a==214748364&&7<S[i])) break;
            a=a*10+S[i]-'0';
            
            if(S[i+1]!='0'){
                rt.push_back(a);
                b=0;
                for( int j=i+1; j<S.size()-1; j++){
                    if(214748364<b||(b==214748364&&7<S[j])) break;
                    b=b*10+S[j]-'0';
                    
                    rt.push_back(b);
                    if(dfs( a, b, j, rt, S))    return rt;
                    rt.pop_back();
                }
                rt.pop_back();
            }else{
                rt.push_back(a);
                b=0;
                rt.push_back(b);
                if(dfs( a, b, i+1, rt, S))    return rt;
                rt.pop_back();
                rt.pop_back();
            }
        }
        
        return rt;
    }
    
    bool dfs( int a, int b, int j, vector<int>& rt, string& S ){
        if(j==S.size()-1)   return true;
        int c=0;
        
        for( int k=j+1; k<S.size(); k++){
            if(214748364<c||(c==214748364&&7<S[k])) break;
            c=c*10+S[k]-'0';
            if(c-b==a){
                rt.push_back(c);
                if(dfs( b, c, k, rt, S))    return true;
                rt.pop_back();
            }else if(a<c-b){
                return false;
            }
        }
        
        return false;
    }
};
