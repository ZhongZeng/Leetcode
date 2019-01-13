/*
973. K Closest Points to Origin

Related Topcis: Math, Divide and Conquer, Sort 

Test Cases:
[[1,3],[-2,2]]
1
[[3,3],[5,-1],[-2,4]]
2

Runtime: 232 ms
Your runtime beats 40.00 % of cpp submissions.
*/

struct lessThan{
    bool operator()(vector<int>& v1, vector<int>& v2){
        return v1[0]*v1[0]+v1[1]*v1[1]<v2[0]*v2[0]+v2[1]*v2[1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {// quick sort is also good 
        vector<vector<int>> rt;
        priority_queue<vector<int>,vector<vector<int>>,lessThan> pq;// max heap
        
        for( int i=0; i<points.size(); i++){
            if(pq.size()<K){
                pq.push(points[i]);
            }else{// pq.size()==k
                if(points[i][0]*points[i][0]+points[i][1]*points[i][1]
                   <pq.top()[0]*pq.top()[0]+pq.top()[1]*pq.top()[1]){
                    pq.pop();
                    pq.push(points[i]);
                }
            }
        }
        
        while(!pq.empty()){
            rt.push_back(pq.top());
            pq.pop();
        }
        
        return rt;
    }
};
