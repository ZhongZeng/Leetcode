/*
1416. Restore The Array

Companies	Postman
Related Topics	Dynamic Programming

Test Cases:
"407780786171321121429620765476840275495357129574174233567552131453038760763182952432348422252546559691171161181440370120987634895458140447952079749439961325982629462531738374032416182281868731817661954890417245087359968833257550123324827240537957646002494771036413572415"
823924906
"600342244431311113256628376226052681059918526204"
703
"1000"
10000
"1000"
10
"1317"
2000
"2020"
30
"1234567890"
90

Runtime: 572 ms, faster than 21.21% of C++ online submissions for Restore The Array.
Memory Usage: 69.1 MB, less than 100.00% of C++ online submissions for Restore The Array.
Next challenges: Maximum Vacation Days, Strange Printer, 
Airplane Seat Assignment Probability
*/

class Solution {
public:
    int numberOfArrays(string s, int k) {
        // Backtracking, DFS, Hash Table, Suffix; O(s*log(k) time; Medium
        unordered_map<int,int> arrs;// [b,s.size()), ways of docoding
        return dfs( s, 0, k, arrs);
    }
    
protected:
    int dfs( string & s, int b, int & k, unordered_map<int,int> & arrs){// post-order dfs
        if(b==s.size()) return 1;// can also add arrs[s.size()]=1; in numberOfArrays()
        if(s[b]=='0')   return 0;// not leading 0s
        if(arrs.find(b)!=arrs.end())    return arrs.find(b)->second;
        
        int sum=0;
        for( long i=b, num=s[i]-'0'; i<s.size(); i++, num=num*10+s[i]-'0'){
            if(num<=k)  sum=(sum+dfs( s, i+1, k, arrs))%1000000007;
            else    break;
        }
        
        arrs[b]=sum;
        return sum;
    }
};