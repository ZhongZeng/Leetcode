/*
1136. Parallel Courses

Companeis	Uber, Google, Microsoft
Related Topics	Dynamic Programming, Depth-first Search

Runtime: 148 ms, faster than 31.53% of C++ online submissions for Parallel Courses.
Memory Usage: 28.5 MB, less than 50.00% of C++ online submissions for Parallel Courses.
Runtime: 144 ms, faster than 35.59% of C++ online submissions for Parallel Courses.
Memory Usage: 28.7 MB, less than 50.00% of C++ online submissions for Parallel Courses.
Next challenges: Dungeon Game, Least Operators to Express Number, Reducing Dishes
*/

class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        // BFS, Topological Sort; relations guranteed to be unique 
        int s=0;
        vector<int> pres(N,0), learned(N,0);// # of prerequisites, learned or not
        unordered_map<int,vector<int>> edges;// prerequisite, next courses
        unordered_set<int> to_learn;
        
        for(int i=0; i<relations.size(); i++){
            pres[relations[i][1]-1]+=1;
            unordered_map<int,vector<int>>::iterator it=edges.find(relations[i][0]-1);
            if(it!=edges.end()) it->second.push_back(relations[i][1]-1);
            else    edges.emplace( relations[i][0]-1, vector<int> {relations[i][1]-1});
        }
        
        for(int i=0; i<pres.size(); i++)
            if(pres[i]==0)  to_learn.emplace(i);
        
        for( ; !to_learn.empty(); s++){// BFS
            unordered_set<int> next_to_learn;
            for( unordered_set<int>::iterator it=to_learn.begin(); it!=to_learn.end(); it++){
                learned[*it]=1;
                unordered_map<int,vector<int>>::iterator jt=edges.find(*it);
                if(jt!=edges.end()){
                    for( int j=0; j<jt->second.size(); j++){
                        int t=jt->second[j];
                        pres[t]-=1;
                        if(pres[t]==0)  next_to_learn.emplace(t);// learned[t]==0 guranteed
                    }
                }
            }
            to_learn=next_to_learn;
        }
        
        for( int i=0; i<learned.size(); i++)
            if(learned[i]==0)   return -1;
        
        return s;
    }
};