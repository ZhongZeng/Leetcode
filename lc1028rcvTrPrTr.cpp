/*
1028. Recover a Tree From Preorder Traversal

Companies	Amazon
Related Topics	Tree, Depth-first Search 

Runtime: 20 ms
Memory Usage: 11.5 MB
Your runtime beats 99.16 % of cpp submissions. 

Test Cases:
"1-2--3--4-5--6--7"
"1-2--3---4-5--6---7"
"1-401--349---90--88"

First, cover the string to values and depths. 
Then, traverse all the nodes sequentailly. If the depth increases by 1 from the previous node, then it's the left child of the previous node. If the depth decreases, find the closest previous node whose depth is exactly 1 smaller than the current depth. This node is the right child of that node. 
Interest obversation: the depth can only increase by 1 or decrease. 

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        // pre-order DFS, tree; If only one child, guaranteed to be left child; 
        // value in [1,1000], assuming no trailing 0s for value 
        TreeNode * rt;
        if(S.size()<1)  return rt;// corner case: empty tree 
        vector<int> vv, vd={0}, td;
        vector<TreeNode*> vt;
        int t=0, d=0;
        
        for( int i=0; i<S.size(); i++){// record value & depth 
            if(d==0){// corner case: first value; dont' swap if else
                if(S[i]=='-'){
                    vv.push_back(t);
                    t=0;
                    d=1;
                }else{
                    t=t*10+S[i]-'0';
                }
            }else{
                if(S[i]=='-'){
                    d++;
                }else{
                    vd.push_back(d);
                    t=S[i]-'0';
                    d=0;
                }
            }
        }
        vv.push_back(t);
        
        rt=new TreeNode(vv[0]);// root 
        vt.push_back(rt);
        td.push_back(0);
        for( int i=1; i<vv.size(); i++){// reconstruct tree; vv.size()==vd.size() 
            TreeNode * nd=new TreeNode(vv[i]);
            if(vd[i]==vd[i-1]+1){// increase can only be 1
                vt.back()->left=nd;
            }else{
                while(td.back()!=vd[i]-1){
                    vt.pop_back();
                    td.pop_back();
                }
                vt.back()->right=nd;
            }
            vt.push_back(nd);
            td.push_back(vd[i]);
        }
        
        
        return rt;
    }
};