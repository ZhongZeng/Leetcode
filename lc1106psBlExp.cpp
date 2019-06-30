/*
1106. Parsing A Boolean Expression

Tag: String, Stack (suggested)

Test Cases:
"!(&(!(t),&(f),|(f)))"
"!(f)"
"|(f,t)"
"&(t,f)"
"|(&(t,f,|(t,f,f)),!(t))"

Runtime: 8 ms
Memory Usage: 9.2 MB
*/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        // stack, O(n) time&space; Medium
        vector<char> st;
        
        for( int i=0; i<expression.size(); i++){
            if(expression[i]=='&'||expression[i]=='|'
               ||expression[i]=='!'||expression[i]=='('){
                st.push_back(expression[i]);
            }else if(expression[i]==')'){
                bool t=false, f=false;
                for( ; st.back()!='('; st.pop_back()){
                    if(st.back()=='t')  t=true;
                    else if(st.back()=='f')  f=true;
                }
                st.pop_back();// pop '('

                if(st.back()=='&')  st.back()=f?'f':'t';
                else if(st.back()=='|') st.back()=t?'t':'f';
                else    st.back()=t?'f':'t'; // '!()' contains only 't' or 'f'
                
                //for(auto e:st)  cout<<e;    cout<<endl;
            }else if(expression[i]=='t'||expression[i]=='f'){
                st.push_back(expression[i]);
            }// else ','
        }
        
        return st.back()=='t';
    }
};