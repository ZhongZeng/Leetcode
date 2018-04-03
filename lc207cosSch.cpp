
/*
Leetcode 207. Course Schedule

Companies 
Uber, Apple, Zenefits, Yelp 
Related Topics 
Depth-first Search, Breadth-first Search, Graph, Topological Sort 
Similar Questions 
Course Schedule II, Graph Valid Tree, Minimum Height Trees, Course Schedule III

Test Cases:
2
[[1,0]]
2
[[1,0],[0,1]]

Runtime: 18 ms
Your runtime beats 51.33 % of cpp submissions.

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // DFS, edge classification, (topological sort) ; directed graph; O(V+E) 
        bool pos=true;
        int ts=0;// time stamp 
        pair<int,int> pr=make_pair(-1,-1);
        vector<pair<int,int>> vt(numCourses, pr);
        vector<int> vd;
        unordered_map<int, unordered_set<int>> um;
        unordered_map<int, unordered_set<int>>::iterator umi;
        
        // record edges
        for(int i=0; i<prerequisites.size(); i++){
            umi=um.find(prerequisites[i].first);
            if(umi!=um.end()){// assuming no duplicates in prerequisites
                umi->second.emplace(prerequisites[i].second);
            }else{
                unordered_set<int> us;
                us.emplace(prerequisites[i].second);
                um.emplace(prerequisites[i].first, us);
            }
        }
        
        // DFS - detect backward edge 
        for( umi=um.begin(); umi!=um.end(); umi++){// better than n in constant time
            if(!pos)    return pos;
            if(vt[umi->first].first<0)  dfs( umi->first, um, vt, ts, pos);
        }
        
        return pos;
    }
    
    void dfs(int cd, unordered_map<int, unordered_set<int>>& um, vector<pair<int,int>>& vt, int& ts, bool& pos){
        // cd hasn't been visited 
        if(!pos)    return ;
        vt[cd].first=++ts;
        
        unordered_map<int, unordered_set<int>>::iterator umi=um.find(cd);
        if(umi!=um.end()){
            for( unordered_set<int>::iterator usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                if(vt[*usi].first<0){// *usi hasn't been visited, tree edge
                    dfs( *usi, um, vt, ts, pos);
                }else{// *usi has been visited; forward/cross/backward edge
                    if(vt[*usi].second<0){// we only care about backward edge 
                        pos=false;
                        return ;
                    }  
                }
            }            
        }
        
        vt[cd].second=++ts;
        return ;
    }
};
