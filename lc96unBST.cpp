
/*
Leetcode 96. Unique Binary Search Trees

Companies 
Snapchat
Related Topics 
Dynamic Programming, Tree 
Similar Questions 
Unique Binary Search Trees II

Test Cases:
1
3
4

Next challenges: Unique Binary Search Trees II

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    int numTrees(int n) {
        // DP, O(n**2) time 
        if(n<1) return 0;
        int sum=0;
        vector<int> vc={1}, vd;
        
        for( int i=1; i<n; i++){// vc[i]=i-# of nodes from root to right most node 
            vd={1};
            for( int j=1; j<vc.size(); j++) vd.push_back(vc[j]+vd.back());
            vd.push_back(vd.back());
            vc=vd;
            //for(auto e:vd)  cout<<e<<" ";   cout<<endl;
        }
        
        for( int i=0; i<vc.size(); i++) sum+=vc[i];
        
        return sum;
    }
};
