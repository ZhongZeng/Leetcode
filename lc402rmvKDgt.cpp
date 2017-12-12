

/*
Leetcode 402. Remove K Digits

Related Topics 
Stack, Greedy 
Similar Questions 
Create Maximum Number, Monotone Increasing Digits 

Next challenges: Create Maximum Number

Test Cases:
"1432219"
3
"10200"
1
"10"
2
"112"
1

Runtime: 3 ms
Your runtime beats 62.95 % of cpp submissions.

*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        // stack
        if(k==num.size())   return "0";
        int ct=0;
        stack<pair<char,int>> st;
        for(int i=0; i!=num.size(); i++){
            while(!st.empty()&&num[i]<st.top().first){
                num[st.top().second]='a';
                st.pop();
                if(++ct==k) return returnStr(num, k, ct);
            }
            st.push(make_pair(num[i],i));
        }
        
        return returnStr(num, k, ct);
    }

protected:    
    string returnStr(string & num, int k, int ct){
        // trim 'a' in string 
        int i=-1, j=-1, m=0;
        while(m!=ct){
            if(num[++j]!='a')   num[++i]=num[j];
            else    m++;
        }
        
        // copy the rest of string
        while(++j!=num.size()-k+ct)  num[++i]=num[j];
        num.erase(i+1,num.size()-i-1);
        
        // trim leading '0's
        i=-1;
        m=0;
        while(++i!=num.size()){
            if(num[i]!='0') break;
            else m++;
        }
        for(i=m; i!=num.size(); i++)    num[i-m]=num[i];
        num.erase(num.size()-m,m);
        
        return num.empty()?"0":num;
    }
    
};
