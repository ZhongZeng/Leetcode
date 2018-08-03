
/*
Leetcode 362. Design Hit Counter

Companies  
Dropbox, Google, Amazon, Bloomberg, Microsoft, Yelp 
Related Topics 
Design 
Similar Questions 
Logger Rate Limiter

Test Cases:
["HitCounter","hit","hit","hit","getHits","hit","getHits","hit","getHits"]
[[],[1],[2],[3],[4],[300],[300],[301],[301]]
["HitCounter","getHits","getHits","getHits","hit","hit","getHits"]
[[],[100],[200],[300],[300],[401],[402]]
["HitCounter","hit","hit","hit","getHits","getHits","getHits","getHits","getHits","hit","getHits"]
[[],[2],[3],[4],[300],[301],[302],[303],[304],[501],[600]]

Next challenges: Design HashMap, Design Linked List, Design Circular Queue

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {// timestamp is monotonically increasing
        vc.push_back(timestamp);
        return ;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        if(vc.size()<1) return 0;
        
        int l=binarySearch( timestamp, 0, vc.size()), m;
        if(timestamp-300<vc[0]) m=-1;
        else    m=binarySearch( timestamp-300, 0, vc.size());
        
        return l-m;
    }
    
protected:
    vector<int> vc;
    
    int binarySearch( int t, int b, int e){// O(log(n)) time 
        int mid;
        while(b+1<e){
            mid=b+(e-b)/2;
            if(t<vc[mid])   e=mid;
            else    b=mid;
        }
        return b;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
