

/*
Leetcode 744. Network Delay Time

Related Topics 
Heap, Depth-first Search,Breadth-first Search, Graph

Next challenges: Construct Binary Tree from Preorder and Inorder Traversal, 
Increasing Subsequences, Redundant Connection

Test Cases:
[[2,1,1],[2,3,1],[3,4,1]]
4
2
[[1,2,1],[2,1,3]]
2
2

Runtime: 79 ms

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Dijkstra learned from Algo-Stanford 
        // There are N network nodes, labelled 1 to N.
        int t, d;// node, distance
        vector<pair<int,int>> vt;
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator umi;
        unordered_map<int, unordered_map<int, int>> umm;
        unordered_map<int, unordered_map<int, int>>::iterator ummi;
        
        for(int i=1; i<N+1; i++)    umm.emplace(i, um);
        for(int i=0; i!=times.size(); i++)
            umm.find(times[i][0])->second.emplace(times[i][1],times[i][2]);
        
        vt.push_back(make_pair(K,0));
        while(!(vt.empty()||umm.empty())){// nothing to visit || all visited
            t=vt[0].first;
            d=vt[0].second;
            popHp(vt);
            ummi=umm.find(t);
            if(ummi!=umm.end()){
                for(umi=ummi->second.begin(); umi!=ummi->second.end(); umi++){
                    pushHp(vt, umi->first, umi->second+d);
                }                
                umm.erase(ummi);                
            }
        }
        
        return umm.empty()?d:-1;
    } 

protected:    
    void popHp(vector<pair<int,int>> & vt){// min
        vt[0]=vt.back();
        vt.pop_back();
        int i=0;
        pair<int,int> pr;
        while(2*i+2<vt.size()){
            if(vt[2*i+2].second<vt[i].second&&vt[2*i+2].second<vt[2*i+1].second){
                pr=vt[2*i+2];
                vt[2*i+2]=vt[i];
                vt[i]=pr;
                i=2*i+2;
            }else if(vt[2*i+1].second<vt[i].second){
                pr=vt[2*i+1];
                vt[2*i+1]=vt[i];
                vt[i]=pr;
                i=2*i+1;                
            }else{
                return ;
            }
        }
        if(2*i+1<vt.size()&&vt[2*i+1].second<vt[i].second){
            pr=vt[2*i+1];
            vt[2*i+1]=vt[i];
            vt[i]=pr;            
        }
        return ;
    }
    
    void pushHp(vector<pair<int,int>> & vt, int t, int d){
        int i=vt.size();
        pair<int,int> pr;
        vt.push_back(make_pair(t,d));
        while(0<i){
            if(vt[i].second<vt[(i-1)/2].second){
                pr=vt[(i-1)/2];
                vt[(i-1)/2]=vt[i];
                vt[i]=pr;
                i=(i-1)/2;
            }else{
                return;
            }
        }
        return ;
    }
};