
/*
Leetcode 933. Number of Recent Calls

Test Case:
["RecentCounter","ping","ping","ping","ping"]
[[],[1],[100],[3001],[3002]]

Runtime: 228 ms

*/

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        vc.push_back(t);
        int b=-1, e=vc.size()-1, mid, s=t-3000;// vc[b]<s<=vc[b+1] 
        
        while(b+1<e){
            mid=b+(e-b+1)/2;
            if(vc[mid]<s)   b=mid;
            else    e=mid;
        }
        
        return vc.size()-b-1;
    }
    
protected:
    vector<int> vc;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */