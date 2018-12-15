/*
399. Evaluate Division

Related Topics: Graph 

Test Cases:
[["a","b"],["b","c"],["bc","cd"]]
[1.5,2.5,5.0]
[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
[ ["a","b"],["b","c"] ]
[2.0,3.0]
[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Evaluate Division.
*/

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        // DFS, O(m*k) time; assuming no conflicts 
        unordered_map<string,unordered_map<string,double>> um;
        unordered_map<string,unordered_map<string,double>>::iterator umi;
        vector<double> rt;
        
        for( int i=0; i<equations.size(); i++){// build graph
            buildGraph( equations[i].first, equations[i].second, values[i], um);
            buildGraph( equations[i].second, equations[i].first, 1.0/values[i], um);
        }
        
        for( int i=0; i<queries.size(); i++){
            unordered_set<string> vt;
            rt.push_back(dfs(queries[i].first, queries[i].second, vt, um));
        }
        
        return rt;
    }
    
    double dfs( string s1, string& s2, unordered_set<string>& vt, unordered_map<string,unordered_map<string,double>>& um){
        if(vt.find(s1)==vt.end())   vt.emplace(s1);
        else    return -1;
        
        unordered_map<string,unordered_map<string,double>>::iterator umi=um.find(s1);
        if(umi!=um.end()){
            for(unordered_map<string,double>::iterator usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                if(usi->first==s2)  return usi->second;// can't place at top of this function, b/c non-exist same element division 
                double d=dfs( usi->first, s2, vt, um);
                if(d!=-1.0)    return d*(usi->second);
            }
        }
        
        return -1.0;
    }
    
    void buildGraph(string& s1, string& s2, double val, unordered_map<string,unordered_map<string,double>>& um){
        unordered_map<string,unordered_map<string,double>>::iterator umi=um.find(s1);
        if(umi!=um.end()){
            umi->second.emplace(s2,val);
        }else{
            unordered_map<string,double> us;
            us.emplace(s2,val);
            us.emplace(s1,1.0);// same element division 
            um.emplace(s1,us);
        }
        return ;
    }
};