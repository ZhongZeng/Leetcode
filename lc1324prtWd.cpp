/*
1324. Print Words Vertically

Company	Microsoft
Related Topics	String

Test Cases:
"HOW ARE YOU"
"CONTEST IS COMING"

Runtime: 0 ms
Memory Usage: 8.5 MB
*/

class Solution {
public:
    vector<string> printVertically(string s) {
        // O(n*n) time; Array 
        vector<string> vs;
        vector<int> vl={-1};// (vl[i],vl[i+1]) is i-th word
        int mx=0;
        for( int i=0; i<s.size(); i++){
            if(s[i]==' ')   vl.push_back(i);
        }
        vl.push_back(s.size());
        
        for( int i=1; i<s.size(); i++){
            string t;
            for( int j=1; j<vl.size(); j++)
                t.push_back(vl[j-1]+i<vl[j]?s[vl[j-1]+i]:' ');
            while(0<t.size()&&t.back()==' ')    t.pop_back();
            if(t.empty())   break;
            vs.push_back(t);
        }
        return vs;
    }
};