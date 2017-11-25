

/*
Leetcode 394. Decode String

Related Topics 
Stack, Depth-first Search 
Similar Questions 
Encode String with Shortest Length, Number of Atoms 

Next challenges: Encode String with Shortest Length, Number of Atoms

Test Cases:
"3[a]2[bc]"

Runtime: 0 ms
You are here! 
Your runtime beats 43.81 % of cpp submissions.

*/

#include<stack>
#include<iostream>
using namespace std;


class Solution {
public:
    string decodeString(string s) {
        // # is followed by '[', # is positive
        string rs="";
        stack<int> sn, sl;//# repetive, location
        int num, n=0, sz;        
        for(int i=0; i!=s.size(); i++ ){
            if( s[i]=='[' ){
                sn.push(n-1);
                sl.push(rs.size());                
                n=0;
            }else if( s[i]==']' ){
                sz=rs.size();                
                for(int j=0; j!=sn.top(); j++){                    
                    for(int k=sl.top(); k!=sz; k++){
                        rs.push_back(rs[k]);                        
                    }
                }        
                //cout<<sn.top()<<" "<<sl.top()<<" "<<sz<<" "<<rs<<endl;
                sn.pop();
                sl.pop();                
            }else if( isLower(s[i]) ){
                rs.push_back(s[i]);
            }else if( isNum(s[i]) ){            
                n=(s[i]-'0')+10*n;
            }                          
        }
        return rs;
    }      
protected:
    bool isNum(char & c){
        return -1<c-'0' && -1<'9'-c;
    }
    
    bool isLower(char & c){
        return -1<c-'a' && -1<'z'-c;
    }
};


int main(){
	Solution s;
	string a="3[a]2[bc2[a]]";
	cout<<s.decodeString(a)<<endl;
		
	return 0;
}


