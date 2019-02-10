
/*
990. Satisfiability of Equality Equations

Related Topics: Graph; suggested: Union Find 

Test Cases:
["e!=c","b!=b","b!=a","e==d"]
["a==b","b!=a"]
["b==a","a==b"]
["a==b","b!=c","c==a"]

Runtime: 12 ms
Memory Usage: 7.5 MB

*/

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // Union find; equations[i].length == 4; equations[i]: [0]&[3]:lowercase letters, [1]:'='|'!'
        unordered_map<char,char> um;// element, parent 
        //vector<unordered_map<char,char>::iterator> vu;// could be used for path compression 
        
        for( int i=0; i<equations.size(); i++){// build union 
            if(equations[i][1]=='='){
                char a=equations[i][0], b=equations[i][3];
                unordered_map<char,char>::iterator uma=um.find(a), umb=um.find(b);
                if(uma!=um.end()){
                    if(umb!=um.end()){
                        while(uma->first!=uma->second)  uma=um.find(uma->second);
                        while(umb->first!=umb->second)  umb=um.find(umb->second);
                        uma->second=umb->first;
                    }else{
                        um.emplace(b,a);
                    }
                }else{
                    if(umb!=um.end()){
                        um.emplace(a,b);
                    }else{
                        um.emplace(a,a);
                        um.emplace(b,a);
                    }
                }
            }
        }
        
        for( int i=0; i<equations.size(); i++){// check not equal; store non-equal relation is expensive 
            if(equations[i][1]=='!'){
                if(equations[i][0]==equations[i][3])    return false;// corner case "a!=a"
                unordered_map<char,char>::iterator uma=um.find(equations[i][0]), umb=um.find(equations[i][3]);
                if(uma!=um.end()&&umb!=um.end()){// if either not exist, it's fine 
                    while(uma->first!=uma->second)  uma=um.find(uma->second);
                    while(umb->first!=umb->second)  umb=um.find(umb->second);
                    if(uma->first==umb->first)  return false;
                }
            }
        }
        
        return true;
    }
};