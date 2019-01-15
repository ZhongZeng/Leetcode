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
[["a","b"],["a","c"],["a","d"],["a","e"],["a","f"],["a","g"],["a","h"],["a","i"],["a","j"],["a","k"],["a","l"],["a","aa"],["a","aaa"],["a","aaaa"],["a","aaaaa"],["a","bb"],["a","bbb"],["a","ff"]]
[1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,1.0,1.0,1.0,1.0,1.0,3.0,5.0]
[["d","f"],["e","g"],["e","k"],["h","a"],["aaa","k"],["aaa","i"],["aa","e"],["aaa","aa"],["aaa","ff"],["bbb","bb"],["bb","h"],["bb","i"],["bb","k"],["aaa","k"],["k","l"],["x","k"],["l","ll"]]

Next challenges: Reconstruct Itinerary, Minimize Malware Spread II, Largest Component Size by Common Factor

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Evaluate Division.

*/

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        // Unioin Find, should be faster than DFS if # queries is large 
		double d1, d2;
		vector<double> rt;
		vector<unordered_map<string,pair<string,double>>::iterator> vt1, vt2;
		unordered_map<string,pair<string,double>> um;// key = pr.second(double) pr.first 
		
		for( int i=0; i<equations.size(); i++){// build initial graph 
			um.emplace(equations[i].first, make_pair(equations[i].first, 1.0));
			um.emplace(equations[i].second, make_pair(equations[i].second, 1.0));
		}
		
		for( int i=0; i<equations.size(); i++)	union2( equations[i], values[i], um);// build graph, assuming no conflict 
		
		for( int i=0; i<queries.size();i++){// find 
			d1=findRoot(vt1, queries[i].first, um);// vt1[0] = d1 vt1.back() 
			d2=findRoot(vt2, queries[i].second, um);
			rt.push_back((vt1.size()<1||vt1.size()<1||vt1.back()!=vt2.back())?-1.0:d1/d2);            
            
			pathCompression(vt1);// path compression 
			pathCompression(vt2);
		}
		
		return rt;
    }
	
protected: 
    void pathCompression(vector<unordered_map<string,pair<string,double>>::iterator>& vt1){
        if(vt1.size()<1)    return ;
		for( int i=vt1.size()-2; -1<i; i--){
            if(vt1[i]->second.first!=vt1.back()->second.first){// vt1[i]->second.first==vt1[i+1]->second.first; !!important, b/c vt1[i] could've been updated in vt2
                vt1[i]->second.first=vt1.back()->second.first;
                vt1[i]->second.second=vt1[i]->second.second*vt1[i+1]->second.second;
            }
		}
		return ;
	}
	
	double findRoot(vector<unordered_map<string,pair<string,double>>::iterator>& vt1, 
			string s1, unordered_map<string,pair<string,double>>& um){
		unordered_map<string,pair<string,double>>::iterator umi=um.find(s1);
        vt1.clear();
		if(umi==um.end())	return -1.0;// corner case, non-existing element 
		
		vt1.push_back(umi);
		double d1=umi->second.second;
		while(umi->first!=umi->second.first){
			umi=um.find(umi->second.first);
			vt1.push_back(umi);
			d1*=umi->second.second;
		}
		
		return d1;
	}
    
	void union2( pair<string, string>& pr, double val, unordered_map<string,pair<string,double>>& um ){
		vector<unordered_map<string,pair<string,double>>::iterator> vt1, vt2;
		double d1=findRoot(vt1, pr.first, um), d2=findRoot(vt2, pr.second, um);
		
		vt1.back()->second.first=vt2.back()->second.first;// union 
		vt1.back()->second.second=val*d2/d1;
		
		pathCompression(vt1);
		pathCompression(vt2);
		
		return ;
	}
};

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