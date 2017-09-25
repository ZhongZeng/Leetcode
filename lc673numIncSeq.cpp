

/*
Leetcode 673. Number of Longest Increasing Subsequence

Related Topics 
Dynamic Programming 
Similar Questions 
Longest Increasing Subsequence, Longest Continuous Increasing Subsequence 

Test Cases:
[1,1,1,2,2,2,3,3,3]
[1,3,5,4,7]

Runtime: 38 ms
You are here! 
Your runtime beats 40.57 % of cpp submissions.

Runtime: 33 ms
You are here! 
Your runtime beats 54.39 % of cpp submissions.

*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {        
        int nm=0, mlen=0, nc, clen ;
        vector<int> vl, vn; 
        for( int i=0; i!=nums.size(); i++){
            clen = 0;
            nc = 1;
            for( int j=0; j!=vl.size(); j++){
                if( nums[j] < nums[i] ){
                    if( clen < vl[j]+1 ){
                        clen = vl[j]+1;
                        nc = vn[j];
                    }else if( clen==vl[j]+1 ){
                        nc += vn[j];
                    }
                }
            }
            vl.push_back( clen ); 
            vn.push_back( nc ); 
            // cout<<clen<<' '<<nc<<endl;
            if( mlen < clen ){ 
                mlen = clen; 
                nm = nc; 
            }else if( mlen==clen ){ 
                nm += nc; 
            }
        }
        // cout<<endl;
        return nm;
    }
};

