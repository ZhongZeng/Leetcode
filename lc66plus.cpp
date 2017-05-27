


/*
Leetcode 66. Plus One
Tags: Array Math
Similar Problems: (M) Multiply Strings (E) Add Binary (M) Plus One Linked List

Runtime: 3 ms
You are here! 
Your runtime beats 19.29 % of cpp submissions.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int p=1;
        for(vector<int>::reverse_iterator it=digits.rbegin();it!=digits.rend();it++){
            *it=*it+p;
            if(9<*it){
                *it-=10;
                p=1;
            }else{
                return digits;
            }
        }
        
        if(p==1){digits.insert(digits.begin(),1);}
        
        return digits;
    }
};
