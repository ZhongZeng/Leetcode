/*
1624. Largest Substring Between Two Equal Characters

Related Topics:	String

Runtime: 4 ms
Memory Usage: 6.6 MB	Your memory usage beats 10.75 % of cpp submissions.
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max=-1;
        vector<int> indices(26, -1);
        for( int i=0; i<s.size(); i++){
            int index=indices[s[i]-'a'];
            if(index==-1)   indices[s[i]-'a']=i;
            else    max=max<i-index-1?i-index-1:max;
        }
        return max;
    }
};