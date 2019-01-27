/*
Leetcode 983. Minimum Cost For Tickets

Related Topic: Dynamic Programming 

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // DP, O(n*log(30)) time; days is in strictly increasing order; costs.length==3 
        vector<int> mc={0};// minimum cost 
        
        for( int i=0, t; i<days.size(); i++){// O(n) iteration
            mc.push_back(mc.back()+costs[0]);// 1-day pass 
            
            t=findLast( days, 7, i);// 7-day pass 
            if(mc[t]+costs[1]<mc.back())    mc.back()=mc[t]+costs[1];
            
            t=findLast( days, 30, i);// 30-day pass 
            if(mc[t]+costs[2]<mc.back())    mc.back()=mc[t]+costs[2];
        }
        
        return mc.back();
    }
    
protected:
    int findLast(vector<int>& days, int dis, int i){// find smallest value > days[i]-dis; O(log(32)) time 
        int b=i-dis<-1?-1:i-dis, m, e=i, target=days[i]-dis+1;// target in (b,e] 
        while(b+1<e){
            m=b+(e-b)/2;
            if(days[m]<target)   b=m;
            else    e=m;
        }
        return e;
    }
};
