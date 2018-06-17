
/*
Leetcode 855. Exam Room

Weekly Contest 89  

Test Case: 
["ExamRoom","seat","seat","seat","seat","leave","seat"]
[[10],[],[],[],[],[4],[]]

*/

class ExamRoom {
public:
    ExamRoom(int N) {
        len=N;
    }
    
    int seat() {// O(1)
        if(ls.empty()){
            ls.emplace_front(0);
            return 0;
        }
        
        
        int mx, mid;
        list<int>::iterator it, jt;
        if( ls.front()<len-1-ls.back() ){
            mx=len-1-ls.back();
            mid=len-1;
        }else{
            mx=ls.front();
            mid=0;            
        }
        
        for( it=ls.begin(), jt=++ls.begin(); jt!=ls.end(); it++, jt++){
            if(mx<(*jt-*it)/2){
                mx=(*jt-*it)/2;
                mid=(*jt+*it)/2;
            }
        }
        
        if(mid==0){
            ls.emplace_front(0);
        }else if(mid==len-1){
            ls.emplace_back(len-1);
        }else{
            for( it=ls.begin(), jt=++ls.begin(); jt!=ls.end(); it++, jt++){
                if(*it<mid&&mid<*jt){
                    ls.insert( jt, mid);
                    break;
                }
            }            
        }
        //for( auto e:ls) cout<<e<<" ";   cout<<endl;
        
        return mid;
    }
    
    void leave(int p) {// O(n) 
        for( list<int>::iterator it=ls.begin(); it!=ls.end(); it++){
            if(*it==p){
                ls.erase(it);
                return ;
            }
        }
        return ;
    }
    
protected:    
    list<int> ls;// vector leave O(1), seat O(n)
    int len;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
