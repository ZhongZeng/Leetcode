


/*
Leetcode 295. Find Median from Data Stream

Related Topics 
Heap, Design
Similar Questions 

Next challenges: Sliding Window Median

Test Cases；
["MedianFinder","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","findMedian","addNum","findMedian"]
[[],[8],[9],[13],[13],[14],[20],[25],[29],[33],[37],[50],[],[78],[]]
["MedianFinder","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","findMedian"]
[[],[8],[9],[13],[13],[14],[20],[25],[29],[33],[37],[50],[78],[]]
["MedianFinder","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","addNum","findMedian"]
[[],[8],[9],[13],[13],[14],[20],[25],[29],[33],[37],[50],[78],[]]
["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian"]
[[],[78],[],[14],[],[50],[],[20],[],[13],[],[9],[],[25],[],[8],[],[13],[],[37],[],[29],[],[33],[],[55],[],[52],[],[6],[],[17],[],[65],[],[23],[],[74],[],[43],[],[5],[],[29],[],[29],[],[72],[],[7],[],[13],[],[56],[],[21],[],[31],[],[66],[],[69],[],[69],[],[74],[],[12],[],[77],[],[23],[],[10],[],[6],[],[27],[],[63],[],[77],[],[21],[],[40],[],[10],[],[19],[],[59],[],[35],[],[40],[],[44],[],[4],[],[15],[],[29],[],[63],[],[27],[],[46],[],[56],[],[0],[],[60],[],[72],[],[35],[],[54],[],[50],[],[14],[],[29],[],[62],[],[24],[],[18],[],[79],[],[16],[],[19],[],[8],[],[77],[],[10],[],[21],[],[66],[],[42],[],[76],[],[14],[],[58],[],[20],[],[0],[]]

Runtime: 169 ms
Your runtime beats 27.56 % of cpp submissions.

*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    // addNum O(lg(n)) time; findMedian O(1) time
    // use 2 heaps, learned from Algo-Stanford; a very classic problem
    vector<int> lo, hi;
    
    MedianFinder() {
        vector<int> lo, hi;//max, min
    }
    
    void addNum(int num) {
        if(lo.size()<hi.size()){
            if(hi[0]<num){
                pushLo(lo, hi[0]);
                rplcHi(hi, num);
            }else{
                pushLo(lo, num);
            }
        }else{
            if(hi.empty()){
                hi.push_back(num);
                return ;
            }  
            if(num<lo[0]){
                pushHi(hi, lo[0]);
                rplcLo(lo, num); 
            }else{
                pushHi(hi, num);
            }
        }
        return ;
    }
    
    double findMedian() {
        //for(auto ele:lo)    cout<<ele<<" "; cout<<endl;
        //for(auto ele:hi)    cout<<ele<<" "; cout<<endl;
            
        return lo.size()<hi.size()?hi[0]:lo[0]+(hi[0]-lo[0])/2.0;
    }
    
protected:
    void rplcLo(vector<int> & hp, int ele){ // max 
        hp[0]=ele;
        int i=0, t;
        while(2*i+2<hp.size()){
            if(hp[i]<hp[2*i+1]&&hp[2*i+2]<hp[2*i+1]){
                t=hp[2*i+1];
                hp[2*i+1]=hp[i];
                hp[i]=t;
                i=2*i+1;
            }else if(hp[i]<hp[2*i+2]){
                t=hp[2*i+2];
                hp[2*i+2]=hp[i];
                hp[i]=t;
                i=2*i+2;                
            }else{
                return ;
            }
        }
        if(2*i+1<hp.size()&&hp[i]<hp[2*i+1]){
            t=hp[2*i+1];
            hp[2*i+1]=hp[i];
            hp[i]=t;            
        }
        return ;
    }
    
    void rplcHi(vector<int> & hp, int ele){ // min
        hp[0]=ele;
        int i=0, t;
        while(2*i+2<hp.size()){
            if(hp[2*i+1]<hp[i]&&hp[2*i+1]<hp[2*i+2]){
                t=hp[2*i+1];
                hp[2*i+1]=hp[i];
                hp[i]=t;
                i=2*i+1;
            }else if(hp[2*i+2]<hp[i]){
                t=hp[2*i+2];
                hp[2*i+2]=hp[i];
                hp[i]=t;
                i=2*i+2;                
            }else{
                return ;
            }
        }
        if(2*i+1<hp.size()&&hp[2*i+1]<hp[i]){
            t=hp[2*i+1];
            hp[2*i+1]=hp[i];
            hp[i]=t;            
        }
        return ;
    }
    
    void pushLo(vector<int> & hp, int ele){ // max 
        int i=hp.size(), t;
        hp.push_back(ele);
        while(0<i){
            if(hp[(i-1)/2]<hp[i]){
                t=hp[(i-1)/2];
                hp[(i-1)/2]=hp[i];
                hp[i]=t;
                i=(i-1)/2;
            }else{
                return ;
            }
        }
        return ;
    }
    
    void pushHi(vector<int> & hp, int ele){ // min
        int i=hp.size(), t;
        hp.push_back(ele);
        while(0<i){
            if(hp[i]<hp[(i-1)/2]){
                t=hp[(i-1)/2];
                hp[(i-1)/2]=hp[i];
                hp[i]=t;
                i=(i-1)/2;
            }else{
                return ;
            }
        }
        return ;        
    }
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */