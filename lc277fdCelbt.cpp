

/* 
Leetcode 277. Find the Celebrity

Companies 
Facebook, Linkedin
Related Topics 
Array 

Next challenges: Median of Two Sorted Arrays, Subsets II, 
Construct Binary Tree from Inorder and Postorder Traversal

Runtime: 77 ms
Your runtime beats 11.13 % of cpp submissions.

*/


// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        // O(n) time; greedy: only 1 celebrite in [0,i]; n:[0,n - 1]
        int cl=0;
        
        for(int i=1; i<n; i++){
            if((!knows(i, cl))&&knows(cl,i))    cl=i;
        }
        
        for(int i=0; i<n; i++){
            if(i!=cl){
                if( knows(cl,i)||(!knows(i,cl)) )
                    return -1;
            }
        }
        
        return cl;
    }
};