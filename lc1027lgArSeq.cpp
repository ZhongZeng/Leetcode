/*
1027. Longest Arithmetic Sequence

Companies	Google, Microsoft, snapdeal
Related Topics	Dynamic Programming

Test Cases:
[3,6,9,12]
[9,4,7,2,10]
[20,1,15,3,10,5,8]
[4,3,2,1]

Runtime: 1620 ms
Memory Usage: 326.2 MB
Your runtime beats 60.26 % of cpp submissions.
*/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        // DP, O(n*n) time; Leetcode has similiar problem
        vector<unordered_map<int,int>> vu;// dis, length
        int mx=0;
        
        for( int i=0; i<A.size(); i++){
            unordered_map<int,int> um;
            for( int j=0; j<i; j++){
                int d=A[i]-A[j], l=2;
                unordered_map<int,int>::iterator umi=vu[j].find(d);// find longest art subseq w/ d @ j 
                l=(umi!=vu[j].end())?umi->second+1:2;
                
                if(mx<l)    mx=l;// 2<=l 
                
                umi=um.find(d);// update longest art subseq w/ d @ j 
                if(umi!=um.end())   umi->second=umi->second<l?l:umi->second;
                else    um.emplace(d,l);
            }
            vu.push_back(um);
        }
        
        return mx;
    }
};
