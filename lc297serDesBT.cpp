
/*
Leetcode 297. Serialize and Deserialize Binary Tree

Companies 
Google, Facebook, Microsoft, Amazon, Bloomberg, Uber, LinkedIn
Related Topics 
Tree, Design 
Similar Questions 
Encode and Decode Strings, Serialize and Deserialize BST, Find Duplicate Subtrees

Next challenges: Encode and Decode Strings, 
Serialize and Deserialize BST, Find Duplicate Subtrees

Test Cases:
[1,2,3,null,null,4,5]
[-1,0,1]

Runtime: 28 ms
Your runtime beats 78.98 % of cpp submissions.

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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // BFS
        string rt;
        if(!root)   return rt;
        vector<TreeNode*> vc, vd;
        vc.push_back(root);
        while(!vc.empty()){
            serial(vc, vd, rt);
            if(vd.empty())  break;
            serial(vd, vc, rt);
        }
        rt.pop_back();
        return rt;
    }

    void serial(vector<TreeNode*>& vc, vector<TreeNode*>& vd, string& rt){
        vd.clear();
        for(int i=0; i<vc.size(); i++){
            if(vc[i]!=NULL){
                rt.append(to_string(vc[i]->val));
                rt.push_back(',');
                vd.push_back(vc[i]->left);
                vd.push_back(vc[i]->right);
            }else{
                rt.append("n,");
            }
        }
        return ;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()<1)   return NULL;
        int nd=0, i=0;
        TreeNode * rt=findNum(data, i), *tr;
        vector<TreeNode*> vc, vd;
        vc.push_back(rt);
        
        for( i++; i<data.size(); i++, nd++){
            if(nd==vc.size()*2){
                vc=vd;
                vd.clear();
                nd=0;
            }
            
            if(data[i]!='n'){
                tr=findNum(data, i);
                if(nd%2!=1) vc[nd>>1]->left=tr;
                else    vc[nd>>1]->right=tr;
                vd.push_back(tr);                
            }else{
                i++;                
            } 
        }
        
        return rt;
    }
    
    TreeNode * findNum(string& data, int& i){
        int num=0;
        if(data[i]!='-'){
            while(i<data.size()&&data[i]!=',')  num=num*10+data[i++]-'0';
        }else{
            i++;
            while(i<data.size()&&data[i]!=',')  num=num*10-data[i++]+'0';
        }
        TreeNode * tr=new TreeNode(num);
        return tr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));