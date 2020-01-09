/*
1306. Jump Game III

Companies	Microsoft
Related Topics	Breadth-first Search, Graph

Test Cases:
[4,2,3,0,3,1,2]
5
[4,2,3,0,3,1,2]
0
[3,0,2,1,2]
2
[0,3,0,6,3,3,4]
6

Runtime: 48 ms	Your runtime beats 93.35 % of cpp submissions.
Memory Usage: 12.4 MB
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // BFS; O(n) time&space; 'ANY' doesn't mean ALL in this problem
        unordered_set<int> us, zr;
        vector<int> vc={start};
        us.emplace(start);
        
        for( int i=start; !vc.empty(); ){
            vector<int> vd;
            for( int j=0; j<vc.size(); j++){
                int t=vc[j]+arr[vc[j]];
                if(-1<t&&t<arr.size()&&us.find(t)==us.end()){
                    us.emplace(t);
                    vd.push_back(t);
                }
                t=vc[j]-arr[vc[j]];
                if(-1<t&&t<arr.size()&&us.find(t)==us.end()){
                    us.emplace(t);
                    vd.push_back(t);
                }
            }
            vc=vd;
        }
        
        for( int i=0; i<arr.size(); i++){
            if(arr[i]==0&&us.find(i)!=us.end()) return true;
        }
        
        return false;
    }
};