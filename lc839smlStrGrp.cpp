
/*
Leetcode 839. Similar String Groups

Companies 
Google 
Related Topics 
Depth-first Search, Union Find, Graph 

Test Case:
["tars","rats","arts","star"]

Runtime: 301 ms

*/

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
		// A.length <= 2000; A[i].length <= 1000; A.length * A[i].length <= 20000
		// A[i] consist of lowercase letters only and are anagrams of each other. 
		// O(n*m*m) time for comparason + Union Find 
        int rt=0, df, i, j, k, s, t;
		vector<int> vc, vs, vt;
		unordered_set<int> gp;
		unordered_set<int>::iterator gpi;
		for( i=0; i<A.size(); i++)	vc.push_back(i);
		
		for( i=0; i<A.size(); i++){
			for( j=i+1; j<A.size(); j++){
				df=0;
				for( k=0; k<A[i].size(); k++){
					if(A[i][k]!=A[j][k])	df++;
					if(2<df)	break;
				}
				if(df<3){// Union Find 
					s=i;
					vs.clear();
					while(vc[s]!=s){
						vs.push_back(s);
						s=vc[s];
					}
					vs.push_back(s);
					for(k=0; k<vs.size(); k++)	vc[vs[k]]=vs.back();// path compression
					
					t=j;
					vt.clear();
					while(vc[t]!=t){
						vt.push_back(t);
						t=vc[t];
					}
					vt.push_back(t);
					for(k=0; k<vt.size(); k++)	vc[vt[k]]=vs.back();// path compression
				}
				//cout<<i<<","<<j<<": ";
				//for(auto e:vc)  cout<<e<<" ";   cout<<endl;
			}
		}
		
		for( i=0; i<vc.size(); i++){
            s=i;
            vs.clear();
            while(vc[s]!=s){
                vs.push_back(s);
                s=vc[s];
            }
            vs.push_back(s);
            for(k=0; k<vs.size(); k++)	vc[vs[k]]=vs.back();// path compression            
			if(gp.find(vc[i])==gp.end())	gp.emplace(vc[i]);
		}
		
		return gp.size(); 
    }
};
