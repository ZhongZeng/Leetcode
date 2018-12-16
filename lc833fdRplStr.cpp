/*833. Find And Replace in String

Related Topics: String 

Test Cases:
"abcd"
[0,2]
["ab","ec"]
["eee","ffff"]
"abcd"
[0, 2]
["a", "cd"]
["eee", "ffff"]

Runtime: 4 ms, faster than 99.81% of C++ online submissions for Find And Replace in String.
*/

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        // O(m+n) time; no overlap guranteed; only lower case in input 
        string rt;
        unordered_map<int,int> um;
        int i, j;
        for( i=0; i<indexes.size(); i++)    um.emplace(indexes[i],i);
        
        for( i=0; i<S.size(); ){
            unordered_map<int,int>::iterator umi=um.find(i);
            if(umi!=um.end()){
                for( j=0; j<sources[umi->second].size(); j++){
                    if(S[i+j]!=sources[umi->second][j]) break;
                }
                if(j==sources[umi->second].size()){
                    i+=sources[umi->second].size();
                    rt.append(targets[umi->second]);
                    continue;
                }
            }
            rt.push_back(S[i++]);
        }
        
        return rt;
    }
};