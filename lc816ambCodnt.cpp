
/*
Leetcode 816. Ambiguous Coordinates

Companies   
Google 
Related Topics 
String 

Test Cases:
"(123)"
"(100)"
"(1002)"

Next challenges: Word Abbreviation, Smallest Range, Basic Calculator III

Runtime: 12 ms
Your runtime beats 34.38 % of cpp submissions.

*/

// backtracking, 4 <= S.length <= 12 
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> rt;
		string rs="(";
		
		addCod( rt, S, rs, 1, false, false, true );
		
		return rt;
    }
	
	void addCod( vector<string>& rt, string& S, string& rs, int i, bool cm, bool dc, bool fd ){// DFS
		// dc: decimal added; cm: comma added; fd: first digit 
        //cout<<rs<<" ";
        if(i==S.size()-1){
            if(cm==true&&validEnd(rs,dc)){
                rt.push_back(rs);
                rt.back().push_back(')');
            }
            return ;            
        }
        
        rs.push_back(S[i]);

        if(cm==false&&validEnd(rs,dc)&&i<S.size()-2){// add ',' 
            rs.append(", ");
            addCod( rt, S, rs, i+1, true, false, true );
            rs.pop_back();
            rs.pop_back();
        }
        if(dc==false&&i<S.size()-2){// add '.' 
            rs.push_back('.');
            addCod( rt, S, rs, i+1, cm, true, false );
            rs.pop_back();
        }
        if(S[i]!='0'||fd==false||i==S.size()-2)    
            addCod( rt, S, rs, i+1, cm, dc, false );// no add ','or'.'; ensure no prevailing 0 

        rs.pop_back();
		
		return ;
	}
	
	bool validEnd( string& rs, bool& dc ){// valid number && trailing 0 problem 
		return dc==false||(dc==true&&rs.back()!='0');
	}
};
