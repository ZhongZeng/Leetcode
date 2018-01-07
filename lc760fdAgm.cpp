
/*

Leetcode 760. Find Anagram Mappings

Test Case:
[12,28,46,32,50]
[50,12,32,46,28]

Runtime: 9 ms

*/


class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> vc;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi;
        for(int i=0; i<B.size(); i++){
            um.emplace(B[i],i);
        }
        
        for(int i=0; i<A.size(); i++){
            vc.push_back(um.find(A[i])->second);
        }
        
        return vc;
    }
};
