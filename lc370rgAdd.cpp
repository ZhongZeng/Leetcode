
/*
Leetcode 370. Range Addition

Companies 
Google
Related Topics 
Array 
Similar Questions 
Range Addition II

Next challenges: Find K-th Smallest Pair Distance, 
My Calendar II, Number of Subarrays with Bounded Maximum

Test Case:
5
[[1,3,2],[2,4,3],[0,2,-2]]

Runtime: 102 ms
Your runtime beats 50.00 % of cpp submissions.

*/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // O(n) time, O(1) space
        int i, c, d;
        vector<int> vc(length, 0);
        if(length<1)    return vc;
        for( i=0; i<updates.size(); i++){
            vc[updates[i][0]]+=updates[i][2];
            if(updates[i][1]<length-1)  vc[updates[i][1]+1]-=updates[i][2];
        }
        
        for( i=1, c=vc[0]; i<vc.size(); i++){
            d=vc[i];
            vc[i]+=c;
            c+=d;
        }
        
        return vc;
    }
};
