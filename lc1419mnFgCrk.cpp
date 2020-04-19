/*
1419. Minimum Number of Frogs Croaking

Companies	C3.ai
Related Topics	String

Test Cases:
"croakcroak"
"crcoakroak"
"croakcrook"
"croakcroa"

Runtime: 96 ms	Your runtime beats 30.77 % of cpp submissions.
Memory Usage: 9.2 MB
*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        // greedy 
        int cur=0, max=0;
        vector<int> croak_queue(4,0);
        unordered_map<char,int> um({{'c',0},{'r',1},{'o',2},{'a',3},{'k',4}});
        
        for( int i=0; i<croakOfFrogs.size(); i++){
            int p=um[croakOfFrogs[i]];
            if(p==0){
                if(max<++cur)   max=cur;
                croak_queue[0]+=1;
            }else{// 0<p
                if(croak_queue[p-1]==0) return -1;
                croak_queue[p-1]-=1;
                
                if(p<4) croak_queue[p]+=1;
                else    cur--;
            }
        }
        
        for( int i=0; i<croak_queue.size(); i++){
            if(0<croak_queue[i])    return -1;
        }
        
        return max;
    }
};