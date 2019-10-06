/*
1208. Get Equal Substrings Within Budget

Companies	Traveloka
Related Topics	Array, Sliding Window 

Test Cases:
"abcd"
"bcdf"
3
"abcd"
"acde"
0

Runtime: 12 ms	Your runtime beats 80.46 % of cpp submissions.
Memory Usage: 9.9 MB
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // two-pointer; O(n) time 
        int b=0, e=0, cs=0, mx=0;//[b,e)
        while( e<s.size() ){
            if(maxCost<cs){
                cs-=abs(s[b]-t[b]);
                b++;
            }else{
                mx=mx<(e-b)?e-b:mx;
                cs+=abs(s[e]-t[e]);
                e++;
            }
        }
        if(cs<=maxCost) mx=mx<(e-b)?e-b:mx;
        return mx;
    }
};