
/*
Leetcode 498. Diagonal Traverse

Next challenges: Non-overlapping Intervals, Validate IP Address, Course Schedule III

Test Cases:
[]
[[1,2,3],[4,5,6],[7,8,9]]

Runtime: 79 ms
Your runtime beats 73.54 % of cpp submissions.

*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> vc;
        if(matrix.size()<1) return vc;
        if(matrix[0].size()<1)  return vc;
        bool asd=true;
        int r=0,c=0;
        while(true){
            if(asd){
                while(r!=0&&c!=matrix[0].size()-1){
                    vc.push_back(matrix[r][c]);
                    r--;
                    c++;
                }
                vc.push_back(matrix[r][c]);
                if(c!=matrix[0].size()-1){
                    c++;
                }else{
                    if(r!=matrix.size()-1)  r++;
                    else    return vc;
                }
                asd=!asd;
            }else{
                while(r!=matrix.size()-1&&c!=0){
                    vc.push_back(matrix[r][c]);
                    r++;
                    c--;                                        
                }
                vc.push_back(matrix[r][c]);
                if(r!=matrix.size()-1){
                    r++;
                }else{
                    if(c!=matrix[0].size()-1)   c++;
                    else    return vc;
                }
                asd=!asd;
            }
        }
    }
};
