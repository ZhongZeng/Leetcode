

/*
946. Validate Stack Sequences

Suggested Tag: array, stack, greedy 

Test Cases:
[1,2,3,4,5]
[4,5,3,2,1]
[1,2,3,4,5]
[4,3,5,1,2]

Runtime: 4 ms

*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // pushed is a permutation of popped; pushed and popped have distinct values.
        if(pushed.size()<1) return true;
        int i, j;
        vector<int> vc;
        
        for( i=0, j=0; j<popped.size(); ){
            if(!vc.empty()&&vc.back()==popped[j]){
                vc.pop_back();
                j++;
            }else{
                if(i<pushed.size()) vc.push_back(pushed[i++]);
                else    return false;
            }
        }
        
        return vc.empty()&&i==pushed.size()&&j==popped.size();
    }
};
