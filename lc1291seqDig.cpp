/*
1291. Sequential Digits

Companies	F5Network
Related Topics	Backtracking

Test Cases:
100
300
1000
13000

Runtime: 4 ms
Memory Usage: 8.3 MBs
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // O(9*9) time; low, high in [10,10**9] 
        vector<int> rt, vc={1,2,3,4,5,6,7,8,9};
        while(!vc.empty()){
            vector<int> vd;
            for( int i=0; i<vc.size(); i++){
                if(low<=vc[i]&&vc[i]<=high) rt.push_back(vc[i]);
                if(vc[i]%10<9)  vd.push_back(vc[i]*10+vc[i]%10+1);
            }
            vc=vd;
        }
        return rt;
    }
};