
/*
Leetcode 834. Sum of Distances in Tree

Companies 
Google 
Related Topics 
Tree, Depth-first Search 

Next challenges: Unique Binary Search Trees II, Zuma Game, The Maze II

Test Cases:
6
[[0,1],[0,2],[2,3],[2,4],[2,5]]
1
[]

Runtime: 160 ms

*/

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        // O(n*n) is trivial: DFS from [0,N) 
		// It's a DAG/tree, so two nodes are connected by their lowerest common ancester. 
		// Adding distance b/t each node is not applicable, since it takes O(n*n) time. Think about adjacent nodes. 
        // O(V+E) time, 3 passes 
        int dis0=0;
        vector<int> rt(N,0), vc(N,0), vt(N, 0);
		unordered_map<int, unordered_set<int>> ed;
		
		for(int i=0; i<edges.size(); i++){// record edges 
			addEdge( ed, edges[i][0], edges[i][1] );
			addEdge( ed, edges[i][1], edges[i][0] );
		}
        
        dfs0( 0, 0, dis0, vt, ed);// calculate distance from 0, thought as root 
        
        dfsPst( 0, 0, N, vc, vt, ed);// recored # children
        
        dfsPre( 0, dis0+N, N, rt, vt, vc, ed);// calculate distance b/w parent&child; dis0+N adjusted for 0
		
		return rt;
    }
    
    void dfsPre( int i, int dis, int& N, vector<int>& rt, 
                vector<int>& vt, vector<int>& vc, unordered_map<int,unordered_set<int>>& ed){
        // pre-order DFS 
        if(2<vt[i]) return ;// 3-parent node 
        vt[i]=3;
        
        dis=dis-vc[i]+(N-2-vc[i]);
        rt[i]=dis;
        
        unordered_map<int,unordered_set<int>>::iterator edi=ed.find(i);
        if(edi!=ed.end()){
            for(unordered_set<int>::iterator usi=edi->second.begin(); usi!=edi->second.end(); usi++)
               dfsPre( *usi, dis, N, rt, vt, vc, ed);
        }
            
        return ;
    }
    
    int dfsPst( int i, int d, int& N, vector<int>& vc, vector<int>& vt, unordered_map<int,unordered_set<int>>& ed){
        // post order DFS 
        if(1<vt[i]) return 0;// 2-parent node 
        vt[i]=2;
        
        int c=0;
        unordered_map<int,unordered_set<int>>::iterator edi=ed.find(i);
        if(edi!=ed.end()){
            for(unordered_set<int>::iterator usi=edi->second.begin(); usi!=edi->second.end(); usi++)
                c+=dfsPst( *usi, d+1, N, vc, vt, ed);            
        }
        
        vc[i]=c;
        
        return c+1;
    }

    void dfs0(int i, int d, int& dis0, vector<int>& vt, unordered_map<int,unordered_set<int>>& ed){
        if(vt[i]!=0)    return ;// 1-parent node 
        vt[i]=1;
        
        dis0+=d;
        unordered_map<int,unordered_set<int>>::iterator edi=ed.find(i);
        if(edi!=ed.end()){
            for(unordered_set<int>::iterator usi=edi->second.begin(); usi!=edi->second.end(); usi++)
                dfs0( *usi, d+1, dis0, vt, ed);
        }
        
        return ;
    }	
	
	void addEdge(unordered_map<int, unordered_set<int>>& ed, int& a, int& b){
		unordered_map<int,unordered_set<int>>::iterator edi=ed.find(a);
		if(edi!=ed.end()){
			edi->second.emplace(b);
		}else{
			unordered_set<int> us;
			us.emplace(b);
			ed.emplace(a, us);
		}
		
		return ;
	}
};