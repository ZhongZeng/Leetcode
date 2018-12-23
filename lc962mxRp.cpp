
/*
962. Maximum Width Ramp

Related Topics: Array 

Test Cases:
[6,0,8,2,1,5]
[9,8,1,0,1,9,4,0,4,1]

Runtime: 60 ms

*/

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        // O(n*log(n)) time, O(n) space, stack+binary search; O(n^2) time is trival
        vector<pair<int,int>> vd={make_pair(A[0],0)};// decreasing unique-value array: value,location 
        int mx=0, d;
        for( int i=1; i<A.size(); i++){
            if(A[i]<vd.back().first){
                vd.push_back(make_pair(A[i],i));
            }else{
                d=i-binarySearch(vd, A[i]);
                if(mx<d)    mx=d;
            }
        }
        return mx;
    }
    
    int binarySearch(vector<pair<int,int>>& vd, int target){
        int b=-1, e=vd.size()-1, mid;// vd[e]<=target<vd[b]
        while(b+1<e){
            mid=b+(e-b)/2;
            if(target<vd[mid].first)  b=mid;
            else    e=mid;
        }
        return vd[e].second;
    }
};