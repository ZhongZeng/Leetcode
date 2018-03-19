
/*

Leetcode 323. Number of Connected Components in an Undirected Graph

Companies 
Google, Twitter 
Related Topics 
Depth-first Search, Breadth-first Search, Union Find, Graph 
Similar Questions 
Number of Islands, Graph Valid Tree, Friend Circles

Test Cases:
5
[[0,1]]
5
[[0,1],[1,2],[3,4]]
6
[[0,1],[0,2],[2,5],[3,4],[3,5]]
10
[[5,6],[0,2],[1,7],[5,9],[1,8],[3,4],[0,6],[0,7],[0,3],[8,9]]

Runtime: 13 ms
Your runtime beats 81.03 % of cpp submissions.

*/

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        // Union Find
        int s, t, sum=0;
        vector<int> vc, vd(n, 0), vt;
        for(int i=0; i<n; i++)  vc.push_back(i);
        
        // Quick Union
        for(int i=0; i<edges.size(); i++){
            t=edges[i].first;
            vt={t};
            while(vc[t]!=t){
                t=vc[t];
                vt.push_back(t);
            }
            s=vt.back();
            for(int j=0; j<vt.size(); j++)  vc[vt[j]]=s;// path compresson
            
            t=edges[i].second;
            vt={t};
            while(vc[t]!=t){
                t=vc[t];
                vt.push_back(t);
            }
            for(int j=0; j<vt.size(); j++)  vc[vt[j]]=s;// path compresson
        }
        
        for(int i=0; i<n; i++){
            t=i;
            vt={t};
            while(vc[t]!=t){
                t=vc[t];
                vt.push_back(t);
            }
            s=vt.back();
            for(int j=0; j<vt.size(); j++)  vc[vt[j]]=s;// path compresson            
        }
        //for(auto e:vc)  cout<<e<<" ";   cout<<endl;
        
        for(int i=0; i<n; i++)  vd[vc[i]]=1;
        for(int i=0; i<n; i++)  sum+=vd[i];
        
        return sum;
    }
};
