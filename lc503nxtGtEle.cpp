
/*
Leetcode 503. Next Greater Element II

Related Topics 
Stack 
Similar Questions 
Next Greater Element I, Next Greater Element III 

Next challenges: Next Greater Element I, Next Greater Element III

Test Case:
[1,2,1]

Runtime: 106 ms
Your runtime beats 75.33 % of cpp submissions.

*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> vc(nums.size(),-1);
        stack<pair<int,int>> st;
        for(int i=0;i!=nums.size(); i++){
            while(!st.empty()){
                if(st.top().first<nums[i]){
                    vc[st.top().second]=nums[i];
                    st.pop();
                }else{
                    break;
                }
            }
            st.push(make_pair(nums[i],i));
        }
        
        for(int i=0;i!=nums.size(); i++){
            while(!st.empty()){
                if(st.top().first<nums[i]){
                    vc[st.top().second]=nums[i];
                    st.pop();
                }else{
                    break;
                }
            }
            st.push(make_pair(nums[i],i));
        }
        
        return vc;
    }
};
