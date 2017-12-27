

/*
Leetcode 456. 132 Pattern

Related Topics 
Stack

Next challenges: Binary Tree Zigzag Level Order Traversal, 
Binary Search Tree Iterator, Closest Binary Search Tree Value II


Test Cases:
[]
[1,2,3,4]
[1, 2, 3, 4]
[-1, 3, 2, 0]
[1,4,4,4]
[1,0,1,-4,-3]
[0,1,-4,-2]
[0,1,-4,-2,-3]

Runtime: 26 ms
Your runtime beats 47.53 % of cpp submissions.

*/


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // O(n) time&space, one pass
        // if euqal is considered, it is easy 
        if(nums.size()<3)   return false;
        
        int i=nums.size(), thr=-2147483648;
        stack<int> st;
        st.push(nums.back());
        while(-1<--i){
            if(nums[i]<thr){
                return true;
            }else if(nums[i]<st.top()){
                st.push(nums[i]);
            }else if(st.top()<nums[i]){
                while(!st.empty()){
                    if(st.top()<nums[i]){
                        thr=st.top();
                        st.pop();
                    }else{
                        break;
                    }
                }
                st.push(nums[i]);
            }
        }
        
        return false;
    }
};



/*
// wrong solution

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // if euqal is considered, it is easy 
        if(nums.size()<3)   return false;
        int i=0, one;
        stack<int> st;
        st.push(nums[0]);
        while(++i<nums.size()){
            if(st.top()<nums[i]){
                one=st.top();
                st.push(nums[i]);
                break;
            }else if(nums[i]<st.top()){
                st.pop();
                st.push(nums[i]);
            }
        }
        
        
        if(st.size()<2) return false;
        
        // st.size()==2&&1,3
        
        while(++i<nums.size()){
            if(st.top()<nums[i]){
                st.pop();
                st.push(nums[i]);
            }else if(nums[i]<st.top()){
                if(one!=nums[i]){
                    return true;
                }
            }
            
        }
        
        return false;
    }
};

*/