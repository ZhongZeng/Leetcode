
/*
Leetcode 718. Maximum Length of Repeated Subarray

Companies 
Citadel 
Related Topics 
Array, Hash Table, Binary Search, Dynamic Programming 
Similar Questions 
Minimum Size Subarray Sum

Next challenges: Largest Divisible Subset, Knight Probability in Chessboard, Basic Calculator IV

Test Cases:
[1,2,3,2,1]
[3,2,1,4,7]

Runtime: 155 ms
Your runtime beats 47.99 % of cpp submissions.

*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // O(n*m) time, aligh each A[i] w/ B[0] then use 2-pointer; similar but easier than lcs
        int mx=0;
        vector<int> va(A.size()+1, 0), ua; //A[0:i]
        
        for( int j=0; j<B.size(); j++){
            ua={0};
            for( int i=0; i<A.size(); i++){
                if(A[i]==B[j]){
                    ua.push_back(va[i]+1);
                    if(mx<ua.back())    mx=ua.back();
                }else{
                    ua.push_back(0);
                }
            }
            //for(auto e:ua)  cout<<e<<" ";   cout<<endl;
            va=ua;
        }
        
        return mx;
    }
};
