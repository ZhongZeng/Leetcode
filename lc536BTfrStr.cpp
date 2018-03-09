
/*
Leetcode 536. Construct Binary Tree from String

Companies 
Amazon
Related Topics 
String, Tree, (suggested: DFS)
Similar Questions 
Construct String from Binary Tree

Next challenges: Longest Uncommon Subsequence II, 
Palindromic Substrings, Equal Tree Partition 

Test Cases:
""
"2(1)"
"4(2(1))(6(5))"
"2(4(7(1)(12))(8))"

Runtime: 36 ms
Your runtime beats 47.89 % of cpp submissions. 

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
    TreeNode* str2tree(string s) {
        // DFS, pre-order traversal 
        // An empty tree is represented by "" instead of "()". One child must be left not right child. 
        if(s.size()<1)  return NULL;
        int num=0, t, i=s[0]!='-'?0:1, sg=s[0]!='-'?1:-1;
        bool nn=false;
        for( ; i<s.size()&&s[i]!='('; i++)  num=num*10+s[i]-'0';
        TreeNode * root=new TreeNode(num*sg), * tr;
        vector<TreeNode*> vt={root};
        vector<int> vc={2};
        
        for( num=0, sg=true; i<s.size(); i++){
            //cout<<i<<": ";
            if(s[i]=='('){// # starts with '('
                if(nn){
                    TreeNode * tr=new TreeNode(num*sg);
                    vt.push_back(tr);
                    vc.push_back(2);
                }
                num=0;
                sg=1;
                nn=false;
            }else if(s[i]==')'){// 2')' after each non-leaf #/node 
                if(nn){
                    TreeNode * tr=new TreeNode(num*sg);
                    if(vc.back()==2)    vt.back()->left=tr;
                    else if(vc.back()==1)   vt.back()->right=tr;
                    vc.back()-=1;
                    nn=false;                    
                }else{
                    tr=vt.back();
                    vt.pop_back();
                    vc.pop_back();
                    if(vc.back()==2)    vt.back()->left=tr;
                    else if(vc.back()==1)   vt.back()->right=tr;
                    vc.back()-=1;
                    nn=false;                      
                }
            }else if(s[i]=='-'){
                sg=-1;
            }else{
                num=10*num+s[i]-'0';
                nn=true;
            }
        }
        
        return root;
    }
};
