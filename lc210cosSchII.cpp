

/*
Leetcode 210. Course Schedule II

Companies 
Facebook, Zenefits
Related Topics 
Depth-first Search, Breadth-first Search, Graph, Topological Sort 
Similar Questions 
Course Schedule, Alien Dictionary, Minimum Height Trees, 
Sequence Reconstruction, Course Schedule III

Next challenges: Alien Dictionary, Minimum Height Trees, 
Sequence Reconstruction, Course Schedule III

Test Cases:
2
[[1,0]]
4
[[1,0],[2,0],[3,1],[3,2]]
3
[[1,0],[1,2],[0,1]]

Runtime: 31 ms
Your runtime beats 19.19 % of cpp submissions.

*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // a very typical topological sort, DFS; O(V+E) time 
        vector<int> rt, ep, vt(numCourses, -1);
        unordered_map<int, unordered_set<int>> pr, nx;
        unordered_map<int, unordered_set<int>>::iterator it;
        
        // record edge; inverse prerequisite in pr and nx, then no need to reverse rt vector
        for(int i=0; i<prerequisites.size(); i++){
            it=pr.find(prerequisites[i].first);
            if(it!=pr.end()){
                it->second.emplace(prerequisites[i].second);
            }else{
                unordered_set<int> us;
                us.emplace(prerequisites[i].second);
                pr.emplace(prerequisites[i].first, us);
            }
            
            it=nx.find(prerequisites[i].second);
            if(it!=nx.end()){
                it->second.emplace(prerequisites[i].first);
            }else{
                unordered_set<int> us;
                us.emplace(prerequisites[i].first);
                nx.emplace(prerequisites[i].second, us);
            }
        }
        
        // DFS, toplogical sort: start from vertax having no out going edge 
        for(int i=0; i<numCourses; i++) dfs(i, nx, pr, vt, rt);
        
        return rt.size()!=numCourses?ep:rt;
    }
    
    void dfs(int i, unordered_map<int, unordered_set<int>>& pr, unordered_map<int, unordered_set<int>>& nx, 
             vector<int>& vt, vector<int>& rt){
        if(vt[i]<0){ // hasn't been visited 
            unordered_map<int, unordered_set<int>>::iterator it=nx.find(i);
            if(it==nx.end()){
                rt.push_back(i);// dfs if not outgoing edge
                vt[i]=1;
                it=pr.find(i);
                if(it!=pr.end()){
                    for( unordered_set<int>::iterator usi=it->second.begin(); usi!=it->second.end(); usi++){
                        removeEdge( nx, *usi, i);// remove edge directed to last vertax
                        dfs( *usi, pr, nx, vt, rt);
                    }                    
                }
            }
        }
        
        return ;
    }
    
    void removeEdge( unordered_map<int, unordered_set<int>>& nx, int i, int c){// remove edge [j,i] i->j
        unordered_map<int, unordered_set<int>>::iterator jt=nx.find(i);
        if(jt!=nx.end()){
            unordered_set<int>::iterator usi=jt->second.find(c);
            if(usi!=jt->second.end()){// these 2 if statements should be redundent
                if(jt->second.size()<2) nx.erase(jt);
                else    jt->second.erase(usi);
            }
        }
        return ;
    }
    
};
