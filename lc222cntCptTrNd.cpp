/*
Leetcode 222. Count Complete Tree Nodes

Related Topics 
Binary Search, Tree 
Similar Questions 
Closest Binary Search Tree Value

Next challenges: Boundary of Binary Tree, Maximum Average Subarray II, Two Sum IV - Input is a BST

Test Cases:
[1,2,3,4,5,6,7]
[1,2,3,4,5,6]
[1,2,3,4,5]
[1,2,3,4]
[1]
[]

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Runtime: 36 ms, faster than 84.12% of C++ online submissions for Count Complete Tree Nodes.
class Solution {
public:
    int countNodes(TreeNode* root) {// O(h*h) time, but faster w.r.t. constant 
        if(!root)   return 0;
		TreeNode * tr, * tt;
        int rt=0, h=0, nl=0, i;// nl: # of nodes to its left in same level, excluding self 
		for( tr=root; tr; tr=tr->left)	h++;
        rt+=(1<<(h-1))-1;// # of nodes not in bottom level 
		
		for( tr=root; 1<h; h--){// tr is not a full tree guranteed, unless tree is full itself
            for( tt=tr->left, i=1; tt; tt=tt->right)	i++;
            
            if(h==i){// if left subtree is full, go to right subtree 
                tr=tr->right;
                nl=(nl<<1)+1;
            }else{// go to left subtree 
                tr=tr->left;
                nl=(nl<<1);
            }   
		}
		
		return rt+nl+(tr!=NULL);// adjust for last node in last row 
    }
}; 

class Solution {
public:
    int countNodes(TreeNode* root) {
		// O(h*h) time, but faster w.r.t. constant 
		TreeNode * tr, * tt;
        int h=0, rt=0, d=0, n2=0, i;
		for( tr=root; tr; tr=tr->left)	h++;
		
		for( tr=root; 0<h; h--, d++){
			rt+=(1<<d)+n2;// (1<<d): nodes in above level, n2: nodes in same level to its left 
			
			for( tt=tr->left, i=1; tt; tt=tt->right)	i++;
			
			if(h==i){// left subtree is full, go to right subtree; last row doen't matter 
				tr=tr->right;
				n2=(n2<<1)+1;
			}else{// go to left subtree 
				tr=tr->left;
				n2=(n2<<1);
			}
		}
		
		return rt+1;// last row, complete nodes to its left, no nodes to its right 
    }
};


// Runtime: 436 ms, faster than 4.41% of C++ online submissions for Count Complete Tree Nodes.
class Solution {
public:
    int countNodes(TreeNode* root) {
        // binary search, O(h*h) time 
        if(!root)   return 0;
        TreeNode * tr;
        int h=0, b, mid, e;
        for( tr=root; tr; tr=tr->left)  h++;
        b=1<<(h-1);
        e=1<<h;
        
        while(b+1<e){// # of nodes in [b,e)
            mid=b+(e-b)/2;
            if(isInTree(root, mid)==true) b=mid;
            else    e=mid;
        }
        
        return b;
    }
    
protected:    
    bool isInTree(TreeNode* root, int m){
        vector<int> vc;
        for( ; 1<m; m=m>>1) vc.push_back(m!=m>>1<<1?1:0);
        for( int i=vc.size()-1; -1<i; i--)  root=vc[i]==0?root->left:root->right;// root!=NULL guranteed til last iteration
        return root;
    }
};

// Runtime: 199 ms	Your runtime beats 7.87 % of cpp submissions.
class Solution {
public:
    int countNodes(TreeNode* root) {
        // O(d*d) time, O(d) space, d=log(# nodes) 
        if(!root)   return 0;
        TreeNode * tr=root;
        vector<bool> vb;
        int b, e=1, mid, d=0, t, i;
        
        while(tr){
            tr=tr->left;
            d++;
            e=e<<1;
        }
        b=e>>1;
        
        while(b+1<e){// [b,e) 
            // true-left; false-right 
            // cout<<b<<","<<e<<" "<<endl;
            mid=b+(e-b)/2;
            t=mid;
            vb.clear();
			for( i=0; i<d-1; i++, t=t>>1)   vb[i]=t-(t>>1<<1)!=1?true:false;
            // for( i=1; i<d; i++, t=t>>1) vb.push_back(t%2!=1?true:false);
			// Runtime: 245 ms. Your runtime beats 4.23 % of cpp submissions.
            
            tr=root;
            for( i=d-2; -1<i; i--){
                if(vb[i])   tr=tr->left;
                else    tr=tr->right;
            }
            
            if(tr)  b=mid;
            else    e=mid;
        }
        
        return b;
    }
};
