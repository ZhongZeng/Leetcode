

/*

Leetcode 496. Next Greater Element I

Tag: Stack
Similar Problems: (M) Next Greater Element II (M) Next Greater Element III
Next challenges: (M) Next Greater Element II(M) Next Greater Element III

You are here! 
Your runtime beats 54.76 % of cpp submissions.	12 ms
Your runtime beats 63.47 % of cpp submissions.	9 ms

Test Cases:
[4,1]
[1,3,4,3,6,5]
result: [6,3]

*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        // inspired by the words unordered_map and stack from others' solution
        // O(n) time, O(n) space
        stack<int> s;
        unordered_map<int, int> unmap; // element, its first greater element to the right
        vector<int> v;
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            while(!s.empty() && s.top()<*it){
                // cout<<s.top()<<" "<<*it<<endl;
                unmap.emplace(s.top(), *it);
                s.pop();
            }
            s.push(*it);
        }
        // cout<<"test1"<<endl;
        
        while(!s.empty()){
                // cout<<s.top()<<" "<<-1<<endl;
                unmap.emplace(s.top(), -1);
                s.pop();
        }
        // cout<<"test2"<<endl;
        
        for(vector<int>::iterator it=findNums.begin(); it!=findNums.end(); it++){
            v.push_back(unmap.find(*it)->second);
        }
        // cout<<"last test"<<endl;
        
        return v;
    }
};
