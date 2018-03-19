
/*
Leetcode 261. Graph Valid Tree

Companies 
Google, Facebook, Zenefits
Related Topics 
Depth-first Search, Breadth-first Search, Union Find, Graph 

Similar Questions 
Course Schedule, Number of Connected Components in an Undirected Graph
	
Next challenges: Course Schedule

Test Cases:
5
[[0,1],[0,2],[2,3],[2,4]]
5
[[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
1
[]
2
[]

Runtime: 21 ms
Your runtime beats 17.62 % of cpp submissions.

*/


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        // a valid tree has no circle, and all nodes are connected
        if(n<1) return true;
        int s, t;
        vector<int> vc, vt;
        for( int i=0; i<n; i++) vc.push_back(i);
        
        // Union Find
        for( int i=0; i<edges.size(); i++ ){
            s=edges[i].first;
            vt={s};
            while(vc[s]!=s){
                s=vc[s];
                vt.push_back(s);
            }
            t=vt.back();
            for( int j=0; j<vt.size(); j++) vc[vt[j]]=t;// path compresson
            
            s=edges[i].second;
            vt={s};
            while(vc[s]!=s){
                s=vc[s];
                vt.push_back(s);
            }
            if(t==vt.back())    return false; // if already connected 
            for( int j=0; j<vt.size(); j++) vc[vt[j]]=t;// path compresson
        }
        
        // Quick Find; O(n)
        for( int i=0; i<n; i++){
            s=i;
            vt={s};
            while(vc[s]!=s){
                s=vc[s];
                vt.push_back(s);
            }
            t=vt.back();
            for( int j=0; j<vt.size(); j++) vc[vt[j]]=t;// path compresson            
        }
        
        s=vc[0];
        for( int i=1; i<n; i++) if(vc[i]!=s)    return false;
        
        return true;
    }
};

