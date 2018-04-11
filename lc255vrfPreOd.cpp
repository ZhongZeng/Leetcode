
/*
Leetcode 255. Verify Preorder Sequence in Binary Search Tree

Companies 
Zenefits 
Related Topics 
Stack, Tree 
Similar Questions 
Binary Tree Preorder Traversal

Next challenges: Ternary Expression Parser, Tag Validator, Path Sum IV

Test Cases:
[]
[8,5,1,6,13,10]
[8,5,1,6,13,7]

Runtime: 43 ms
Your runtime beats 66.84 % of cpp submissions.

*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        // You may assume each number in the sequence is unique. 
        if(preorder.size()<2)   return true;
        int mn=LONG_MIN;// 	-2147483647
        vector<int> vc;
        vc.push_back(preorder[0]);
        
        for(int i=1; i<preorder.size(); i++){
            if(vc.back()<preorder[i]){
                while(!vc.empty()&&vc.back()<preorder[i]){
                    mn=vc.back();
                    vc.pop_back();
                }
            }else{
                if(preorder[i]<mn)  return false;
            }
            vc.push_back(preorder[i]);
        }
        
        return true;
    }
};
