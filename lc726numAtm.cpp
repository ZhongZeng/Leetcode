
/*
Leetcode 726. Number of Atoms

Related Topics 
Hash Table, Stack, Recursion 
Similar Questions 
Decode String Encode String with Shortest Length 

Next challenges: Encode String with Shortest Length

Test Cases:
"H2O"
"K4(ON(SO3)2)2"
"Mg(OH)2"

Runtime: 3 ms
You are here! 
Your runtime beats 11.84 % of cpp submissions.

*/


class Solution {
public:
    string countOfAtoms(string formula) {
        stack<int> sl;//locations
        vector<string> ss;//atoms
        vector<int> si;//#iterations
        string s,rs="";// atom, return string
        int r=0;//#iteration
        
        unordered_map<string, int> um;
        unordered_map<string, int>::iterator umi;
        vector<string> vs;
        
		// count atoms 
        for(int i=0; i!=formula.size(); ){            
            if( isUpper(formula[i]) ){
                s.clear();
                s.push_back(formula[i]);
                while(isLower(formula[++i]) && i<formula.size())    s.push_back(formula[i]);
                ss.push_back(s);
                if( isNum(formula[i]) && i<formula.size() ){
                    r=formula[i]-'0';
                    while(isNum(formula[++i]) && i<formula.size())   r=r*10+formula[i]-'0';
                    si.push_back(r);
                }else{
                    si.push_back(1);
                }
            }else if( formula[i]=='(' ){
                sl.push(ss.size());               
                i++;
            }else if( formula[i]==')' ){ //')' is followed by #
                r=0;
                while(isNum(formula[++i]) && i<formula.size())   r=r*10+formula[i]-'0';
                for(int j=sl.top(); j!=ss.size(); j++)  si[j]=si[j]*r;
                sl.pop();
            }              
        }
        
        // consolidate atoms
        for(int i=0; i!=ss.size(); i++){
            umi=um.find(ss[i]);
            if( umi!=um.end() ) umi->second+=si[i];
            else    um.emplace(ss[i], si[i]);
        }
        
        // sort atoms
        for(unordered_map<string, int>::iterator it=um.begin(); it!=um.end(); it++) vs.push_back(it->first);
        sort(vs.begin(), vs.end());
        
        // output atoms
        for(int i=0; i!=vs.size(); i++){
            rs.append(vs[i]);
            umi=um.find(vs[i]);
            if(umi->second!=1)  rs.append(to_string(umi->second));
        }
        
        return rs;
    }

protected:
    bool isUpper(char & c){
        return -1<c-'A' && -1<'Z'-c;        
    }
    
    bool isLower(char & c){
        return -1<c-'a' && -1<'z'-c;
    }
    
    bool isNum(char & c){
        return -1<c-'0' && -1<'9'-c;
    }
    
};

