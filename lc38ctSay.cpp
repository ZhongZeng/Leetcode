
/*
Leetcode 38. Count and Say

Related Topics 
String
Similar Questions 
Encode and Decode Strings, String Compression

Next challenges: Encode and Decode Strings, String Compression

Test Cases:
1
2
5
6
8
9

Runtime: 3 ms
Your runtime beats 23.64 % of cpp submissions.

*/

class Solution {
public:
    string countAndSay(int n) {
        if(n<1) return "";
        string s="1", st;
        int ct;
        char c;
        for(int i=1; i!=n; i++){
            ct=1;
            c=s[0];
            for(int j=1; j!=s.size(); j++){
                if(s[j]!=c){
                    st.append(to_string(ct));
                    st.push_back(c);
                    ct=1;
                    c=s[j];
                }else{
                    ct++;
                }
            }
            st.append(to_string(ct));
            st.push_back('1');
                
            s=st;
            st.clear();
        }
        return s;
    }
};
