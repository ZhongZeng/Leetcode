
/*
Leetcode 787. Cheapest Flights Within K Stops

Companies 
Airbnb
Related Topics 
Dynamic Prograamming, Heap, Breadth-first Search 
Similar Questions 
Maximum Vacation Days

Next challenges: Maximum Vacation Days

Test Cases:
3
[[0,1,100],[1,2,100],[0,2,500]]
0
2
1
3
[[0,1,100],[1,2,100],[0,2,500]]
0
2
0

Runtime: 13 ms
Your runtime beats 82.46 % of cpp submissions.

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // adapted Dijkstra: BFS+heap 
        // There will not be any duplicated flights or self cycles. 
        // The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1. 
        // k is in the range of [0, n - 1]. 
        // The price of each flight will be in the range [1, 10000]. 
        int ds=1000001;// =100*10000+1
        vector<vector<int>> hp;// node, distance from src, flights/stops
        vector<int> vc={src, 0, -1}, vd(3,0), vt(n, -1);
        hp.push_back(vc);
        unordered_map<int,unordered_map<int,int>> um;
        unordered_map<int,unordered_map<int,int>>::iterator umi;
        unordered_map<int,int> us;
        unordered_map<int,int>::iterator usi;
        
        // record edges 
        for(int i=0; i<n; i++)  um.emplace(i,us);
        for(int i=0; i<flights.size(); i++) um.find(flights[i][0])->second.emplace(flights[i][1],flights[i][2]);
        
        // adapted Dijkstra
        while(!hp.empty()){
            vc=hp[0];
            popHp(hp);
            vt[vc[0]]=1;
            if(vc[0]==dst)  return vc[1];
            if(vc[2]<K){// within K flights 
                umi=um.find(vc[0]);
                for( usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                    if(vt[usi->first]<0){// hasn't been visited 
                        vd[0]=usi->first;
                        vd[1]=vc[1]+usi->second;
                        vd[2]=vc[2]+1;
                        pushHp( hp, vd);
                    }
                }
            }
        }
        
        return -1;
    }
    
    void pushHp(vector<vector<int>>& hp, vector<int>& vc){// min heap [1] 
        int i=hp.size();
        hp.push_back(vc);
        
        while(0<i){
            if(hp[i][1]<hp[(i-1)>>1][1]){
                vc=hp[(i-1)>>1];
                hp[(i-1)>>1]=hp[i];
                hp[i]=vc;
                i=(i-1)>>1;
            }else{
                return ;
            }
        }
        
        return ;
    }
    
    void popHp(vector<vector<int>>& hp){
        vector<int> vc;
        hp[0]=hp.back();
        hp.pop_back();
        int i=0;
        
        while(2*i+2<hp.size()){
            if(hp[2*i+1][1]<hp[i][1]&&hp[2*i+1][1]<hp[2*i+2][1]){
                vc=hp[2*i+1];
                hp[2*i+1]=hp[i];
                hp[i]=vc;
                i=2*i+1;
            }else if(hp[2*i+2][1]<hp[i][1]){
                vc=hp[2*i+2];
                hp[2*i+2]=hp[i];
                hp[i]=vc;
                i=2*i+2;
            }else{
                break;
            }
        }
        
        if(2*i+1<hp.size()&&hp[2*i+1][1]<hp[i][1]){
            vc=hp[2*i+1];
            hp[2*i+1]=hp[i];
            hp[i]=vc;
        }
        
        return ;
    }    
};
