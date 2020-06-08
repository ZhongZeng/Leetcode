/*
1462. Course Schedule IV

Medium
Companies	Uber
Related Topics	

Test Cases:
5
[[4,3],[4,1],[4,0],[3,2],[3,1],[3,0],[2,1],[2,0],[1,0]]
[[1,4],[4,2],[0,1],[4,0],[0,2],[1,3],[0,1]]
2
[[1,0]]
[[0,1],[1,0]]
5
[[0,1],[1,2],[2,3],[3,4]]
[[0,4],[4,0],[1,3],[3,0]]

Next challenges: K-Similar Strings, Number of Squareful Arrays,
Find the City With the Smallest Number of Neighbors at a Threshold Distance
*/

/*
Runtime: 544 ms, faster than 63.83% of C++ online submissions for Course Schedule IV.
Memory Usage: 79.9 MB, less than 16.17% of C++ online submissions for Course Schedule IV.
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // DFS, O(n*n+p+q) time; n in [2,100], queries.size() in [1,10**4]
		unordered_map<int,unordered_set<int>> next, preq;
        vector<bool> ck;
		
        for( int i=0; i<prerequisites.size(); i++)
			addPreq( prerequisites[i][0], prerequisites[i][1], next);
		
		for( int i=0; i<n; i++){
			vector<int> pre, visited(n,0);// global vistied is wrong
			dfs( i, pre, visited, next, preq);
		}
        
        for( int i=0; i<queries.size(); i++){
			unordered_map<int,unordered_set<int>>::iterator it=preq.find(queries[i][0]);
			if(it!=preq.end()&&it->second.find(queries[i][1])!=it->second.end())	ck.push_back(true);
			else	ck.push_back(false);
		}
        
        return ck;
    }
    
protected:
	void addPreq( int b, int e, unordered_map<int,unordered_set<int>> & preq){
		unordered_map<int,unordered_set<int>>::iterator it=preq.find(b);
		if(it!=preq.end())	it->second.emplace(e);
		else	preq.emplace(b, unordered_set<int> {e});
		return ;
	}

    void dfs( int i, vector<int> & pre, vector<int> & visited, 
			unordered_map<int,unordered_set<int>> & next, unordered_map<int,unordered_set<int>> & preq){
        if(visited[i]==1)	return ;
		else    visited[i]=1;
		
		for( int j=0; j<pre.size(); j++)	addPreq( pre[j], i, preq);
        pre.push_back(i);
		
		unordered_map<int,unordered_set<int>>::iterator it=next.find(i);
        if(it!=next.end()){
            for( unordered_set<int>::iterator jt=it->second.begin(); jt!=it->second.end(); jt++)
                dfs( *jt, pre, visited, next, preq);
        }
		
		pre.pop_back();
        return ;
    }
};

/*
Time Limit Exceeded
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // DFS, Memorize prerequisites of queries[i][1]; n in [2,100], queries.size() in [1,10**4]
        unordered_map<int,unordered_set<int>> next;
        vector<bool> ck;
        for( int i=0; i<prerequisites.size(); i++){
            if(next.find(prerequisites[i][0])==next.end())
                next[prerequisites[i][0]]={prerequisites[i][1]};
            else
                next[prerequisites[i][0]].emplace(prerequisites[i][1]);
        }
        
        for( int i=0; i<queries.size(); i++)    
            ck.push_back(isPrerequisite(queries[i][0], queries[i][1], n, next));
        
        return ck;
    }
    
protected:
    bool isPrerequisite( int b, int e, int n, unordered_map<int,unordered_set<int>> & next){
        vector<int> visited(n,0);
        return dfs( b, e, visited, next);
    }
    
    bool dfs( int b, int e, vector<int> & visited, unordered_map<int,unordered_set<int>> & next){
        if(b==e)    return true;
        if(visited[b]==1)   return false;
        visited[b]=1;
        
        unordered_map<int,unordered_set<int>>::iterator it=next.find(b);
        if(it==next.end())  return false;
        for( unordered_set<int>::iterator jt=it->second.begin(); jt!=it->second.end(); jt++){
            if(dfs( *jt, e, visited, next)){
				if(next.find(*jt)!=next.end())	next[*jt].emplace(e);
				else	next[*jt]={e};
				return true;
			}
        }
        return false;
    }
};

/*
Runtime: 1764 ms, faster than 5.23% of C++ online submissions for Course Schedule IV.
Memory Usage: 112.1 MB, less than 10.91% of C++ online submissions for Course Schedule IV.
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // DFS; n in [2,100], queries.size() in [1,10**4]
        unordered_map<int,unordered_set<int>> next;
        vector<bool> ck;
        for( int i=0; i<prerequisites.size(); i++){
            if(next.find(prerequisites[i][0])==next.end())
                next[prerequisites[i][0]]={prerequisites[i][1]};
            else
                next[prerequisites[i][0]].emplace(prerequisites[i][1]);
        }
        
        for( int i=0; i<queries.size(); i++)    
            ck.push_back(isPrerequisite(queries[i][0], queries[i][1], n, next));
        
        return ck;
    }
    
protected:
    bool isPrerequisite( int b, int e, int n, unordered_map<int,unordered_set<int>> & next){
        vector<int> visited(n,0);
        return dfs( b, e, visited, next);
    }
    
    bool dfs( int b, int e, vector<int> & visited, unordered_map<int,unordered_set<int>> & next){
        if(b==e)    return true;
        if(visited[b]==1)   return false;
        visited[b]=1;
        
        unordered_map<int,unordered_set<int>>::iterator it=next.find(b);
        if(it==next.end())  return false;
        for( unordered_set<int>::iterator jt=it->second.begin(); jt!=it->second.end(); jt++){
            if(dfs( *jt, e, visited, next)) return true;
        }
        return false;
    }
};