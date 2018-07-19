
/*
Leetcode 428. Serialize and Deserialize N-ary Tree

Related Topics 
Tree 

Similar Questions 
Serialize and Deserialize Binary Tree, Serialize and Deserialize BST, Encode N-ary Tree to Binary Tree

Runtime: 68 ms
Your runtime beats 65.52 % of cpp submissions.

*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {// BFS
        string data;
        if(!root)   return data;
        vector<Node*> vn, vm;
        vn.push_back(root);
        while(!vn.empty()){
            for( int i=0; i<vn.size(); i++ ){
                data.append(to_string(vn[i]->val));
                data.push_back('#');
                data.append(to_string(vn[i]->children.size()));
                data.push_back('#');
                for( int j=0; j<vn[i]->children.size(); j++)    vm.push_back(vn[i]->children[j]);
            }
            vn=vm;
            vm.clear();
        }
        return data;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {// BFS 
        //cout<<data<<endl;
        if(data.size()<1)   return NULL;
        int vl=0, ss=0, st=0, i=-1;
        
        while(data[++i]!='#')   vl=vl*10+data[i]-'0';
        Node * root=new Node(vl);
        vector<Node*> vn={root}, un;// nodes
        
        while(data[++i]!='#')   ss=ss*10+data[i]-'0';
        vector<int> vs={ss}, us;// size of children of nodes 
        
        while( i+1<data.size() ){
            for( int j=0; j<ss; j++){
                for( vl=0, i++; data[i]!='#'; i++)  vl=vl*10+data[i]-'0';
                Node * tr=new Node(vl);
                un.push_back(tr);
                
                for( vl=0, i++; data[i]!='#'; i++)  vl=vl*10+data[i]-'0';
                us.push_back(vl);
                st+=vl;
            }
            
            for( int j=0, k=0; j<vn.size(); j++){// point parents to children
                for( int l=0; l<vs[j]; l++, k++)    vn[j]->children.push_back(un[k]);
            }
            
            ss=st;
            st=0;
            vn=un;
            vs=us;
            un.clear();
            us.clear();
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
