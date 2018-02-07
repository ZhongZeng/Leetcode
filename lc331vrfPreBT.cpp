

/*
Leetcode 331. Verify Preorder Serialization of a Binary Tree

Related Topics 
Stack

Next challenges: Largest Rectangle in Histogram, 
Binary Search Tree Iterator, Exclusive Time of Functions

Test Cases:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
"1,#"
"9,#,#,1"
""

Runtime: 5 ms
Your runtime beats 66.18 % of cpp submissions.

*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // no need to worry about values; BT not BST
        // You may assume that the input format is always valid. 
        if(preorder.back()!='#')    return false;// this line is nessary to prevent runtime error
        vector<int> vc;
        int i=-1;
        while( ++i<preorder.size() ){
            if(preorder[i]!='#'){
                while(preorder[i]!=',') i++;//i<preorder.size()&&
                vc.push_back(2);// left and right children 
            }else{//=='#'
                while(!vc.empty()){
                    if(vc.back()==2){
                        vc.back()-=1;
                        break;
                    }else{//==1
                        vc.pop_back();
                    }
                }
                if(vc.empty()){
                    if(i!=preorder.size()-1)    return false;
                    else    return true;
                }
                i++;// preorder[i]==','
            }
        }
        
        return false;
    }
};
