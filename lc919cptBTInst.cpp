
/*
Leetcode 919. Complete Binary Tree Inserter

Tag: Tree, Design 

Test Cases:
["CBTInserter","insert","get_root"]
[[[1]],[2],[]]
["CBTInserter","insert","insert","get_root"]
[[[1,2,3,4,5,6]],[7],[8],[]]

Runtime: 16 ms

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
class CBTInserter {
public:
    // use a vector to implement, heap is perfectly-balance binary tree
    CBTInserter(TreeNode* root) {
        // BFS, O(n)
        vector<TreeNode*> vd, ve;
        vd.push_back(root);
        while(!vd.empty()){
            ve.clear();
            for(int i=0; i<vd.size(); i++){
                vc.push_back(vd[i]);
                if(vd[i]->left) ve.push_back(vd[i]->left);
                if(vd[i]->right)ve.push_back(vd[i]->right);
            }
            vd=ve;
        }
    }
    
    int insert(int v) {// O(1)
        TreeNode * nd=new TreeNode(v);
        if(vc.size()%2==1)  vc[(vc.size()-1)/2]->left=nd;
        else    vc[(vc.size()-1)/2]->right=nd;
        vc.push_back(nd);
        return vc[vc.size()/2-1]->val;
    }
    
    TreeNode* get_root() {// O(1)
        return vc[0];
    }
    
protected:
    vector<TreeNode*> vc;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */