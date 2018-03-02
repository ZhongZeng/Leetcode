
/*
Leetcode 32. Longest Valid Parentheses

Related Topics 
String, Dynamic Programming 
Similar Questions 
Valid Parentheses

Next challenges: Unique Binary Search Trees, 
Design Log Storage System, Basic Calculator III 

Test Cases:
""
"((()()()))"
"(()((()(("
"())))"

Runtime: 10 ms
Your runtime beats 29.50 % of cpp submissions.

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        // DP, stack 
        int mx=0, t=0;
        vector<int> st;//-...+-
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                if(0<t){
                    st.push_back(t);
                    t=0;
                    st.push_back(-1);
                }else{
                    if(st.size()<1) st.push_back(-1);
                    else    st.back()-=1;
                }
            }else{
                if(st.size()<1){
                    t=0;
                }else{
                    if(st.back()==-1){
                        st.pop_back();
                        if(st.empty()){
                            t+=2;
                        }else{
                            t+=st.back()+2;
                            st.pop_back();
                        }
                    }else{
                        st.back()+=1;
                        t+=2;
                    }
                    mx=mx<t?t:mx;
                }
            }
            //for(auto e:st)  cout<<e<<" ";   cout<<endl;
        }
        
        return mx;
    }
};
