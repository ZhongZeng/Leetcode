
/*
Leetcode 739. Daily Temperatures

Related Topics 
Hash Table, Stack 
Similar Questions 
Next Greater Element I 

Next challenges: Palindrome Permutation, 
Logger Rate Limiter, Smallest Range

Test Case:
[73,74,75,71,69,72,76,73]

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // stack
        // O(n) time
        vector<int> vc(temperatures.size(),0);
        if(temperatures.size()<1)   return vc;
        stack<pair<int,int>> st;
        st.push(make_pair(temperatures[0],0));
        for(int i=1; i!=temperatures.size(); i++){
            while(!st.empty()){
                if(st.top().first<temperatures[i]){
                    vc[st.top().second]=i-st.top().second;
                    st.pop();
                }else{
                    break;
                }
            }
            st.push(make_pair(temperatures[i],i));
        }
        
        return vc;
    }
};

