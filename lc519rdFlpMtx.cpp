
/*
Leetcode 519. Random Flip Matrix

Companies   
Google 
Related Topics 
Random 

Test Case:
["Solution", "flip", "flip", "flip", "flip"]
[[2, 2], [], [], [], []]

Next challenges: Random Pick with Blacklist

Runtime: 24 ms
Your runtime beats 17.31 % of cpp submissions.

*/

class Solution {
public:
    // # flip & reset <= 1000
    // 1 <= n_rows, n_cols <= 10000 
    Solution(int n_rows, int n_cols) {
        r=n_rows;
        c=n_cols;
        len=r*c;
    }
    
    vector<int> flip() {
        // O(m*n) time, think of a long array 
        vector<int> rt;
        int t=rand()%(len-ls.size());
        list<int>::iterator li;
        
        for( li=ls.begin(); li!=ls.end(); li++){
            if(t<*li)   break;
            else    t++;
        }
        ls.insert( li, t);
        
        rt.push_back(t/c);
        rt.push_back(t%c);
        
        return rt;
    }
    
    void reset() {
        ls.clear();
        
        return ;
    }
    
protected:    
    int r, c, len;
    list<int> ls;// BST would be faster 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
