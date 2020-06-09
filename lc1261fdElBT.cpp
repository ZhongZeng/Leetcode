/*
1261. Find Elements in a Contaminated Binary Tree

Medium
Companies	Google
Related Topics	Hash Table, Tree

Test Cases:
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]

Runtime: 68 ms, faster than 53.30% of C++ online submissions for Find Elements in a Contaminated Binary Tree.
Memory Usage: 33.4 MB, less than 16.92% of C++ online submissions for Find Elements in a Contaminated Binary Tree.
Runtime: 100 ms, faster than 32.49% of C++ online submissions for Find Elements in a Contaminated Binary Tree.
Memory Usage: 33.2 MB, less than 25.25% of C++ online submissions for Find Elements in a Contaminated Binary Tree.
Next challenges: Rabbits in Forest, Minimum Area Rectangle, Largest Values From Labels
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        // Easy; O(n+m) time; DFS, Tree
        dfs( root, 0);
    }
    
    bool find(int target) {
        return us.find(target)!=us.end();
    }
    
protected:
    unordered_set<int> us;
    void dfs(TreeNode * tr, int v){
        if(!tr) return ;
        us.emplace(v);
        dfs( tr->left, 2*v+1);
        dfs( tr->right, 2*v+2);
        return ;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */