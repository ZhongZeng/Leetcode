
/*
Leetcode 301. Remove Invalid Parentheses

Related Topics:
Depth-first Search, Breadth-first Search 

Similar Questions:
Valid Parentheses 

Test Cases:
"()())()"
"(a)())()"
")(f"

Runtime: 4 ms
Your runtime beats 74.32 % of cpp submissions.

*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
		// DFS+backtrack; read the hint: since not knowing which to remove, try all options 
		vector<string> vs, rt;
        unordered_set<string> us;
		string t;// protential valid string 
        int mn=findMinRemoval(s);
        
		dfs( vs, s, t, mn, 0, 0);
        
        for( int i=0; i<vs.size(); i++){// remove duplicate 
            if(us.find(vs[i])==us.end()){
                rt.push_back(vs[i]);
                us.emplace(vs[i]);
            }
        }
		
		return rt;
    }
	
protected: 
    int findMinRemoval(string & s){
        int p=0, mn=0;// parentheses, min parentheses to remove 
		
		for( int i=0; i<s.size(); i++){
			if(s[i]=='(')	p++;
			else if(s[i]==')')	p--;
			if(p<0){// p==-1
				mn++;
				p=0;
			}
		}
		mn+=p;        
        
        return mn;
    }
    
	void dfs( vector<string>& vs, string& s, string& t, int mn, int p, int l){// return vector, original string, temp string, # remove left, # parentheses, location in original string 
        //cout<<t<<":"<<l<<","<<p<<","<<mn<<"; ";
        if(mn<0||p<0)   return ;
		if(l==s.size()){
			if(p==0&&mn==0)	vs.push_back(t);
			return ;
		}
        
		if(s[l]=='('){
			t.push_back(s[l]);
			dfs( vs, s, t, mn, p+1, l+1);
			t.pop_back();
            dfs( vs, s, t, mn-1, p, l+1);// remove this '(' 
		}else if(s[l]==')'){
			t.push_back(s[l]);
			dfs( vs, s, t, mn, p-1, l+1);
			t.pop_back();
			dfs( vs, s, t, mn-1, p, l+1);// remove this ')' 
		}else{
            t.push_back(s[l]);
            dfs( vs, s, t, mn, p, l+1);
            t.pop_back();
        }
		
		return ;
	}
};
