/*
1042. Flower Planting With No Adjacent

Related Topics	Graph 

Runtime: 204 ms
Your runtime beats 38.03 % of cpp submissions.
Memory Usage: 48 MB

Test Cases:
3
[[1,2],[2,3],[3,1]]
4
[[1,2],[3,4]]
4
[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]

*/

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        // O(n) time, greedy; all nodes connect to <=3 other nodes; for any given node, choose the color diff/ from adjacent nodes 
        vector<int> vc(N,0);
        unordered_map<int,list<int>> um;
        
        for( int i=0; i<paths.size(); i++){
            addPath( paths[i][0]-1, paths[i][1]-1, um);
            addPath( paths[i][1]-1, paths[i][0]-1, um);
        }
        
        if(0<vc.size()) vc[0]=1;
        for( int i=1; i<vc.size(); i++){
            unordered_map<int,list<int>>::iterator umi=um.find(i);
            if(umi!=um.end()){// choose a color (from 4 colors) different from 3 adjacent nodes 
                vector<int> cl={0,1,2,3,4};
                for( auto li=umi->second.begin(); li!=umi->second.end(); li++)  cl[vc[(*li)]]=0;// record color
                for( int j=1; j<cl.size(); j++){
                    if(cl[j]!=0){
                        vc[i]=j;//==cl[j]
                        break;
                    }
                }
            }else{
                vc[i]=1;
            }
        }
        
        return vc;
    }
    
protected:
    void addPath( int a, int b, unordered_map<int,list<int>>& um){
        unordered_map<int,list<int>>::iterator umi=um.find(a);
        if(umi!=um.end()){
            umi->second.push_back(b);
        }else{
            list<int> ls={b};
            um.emplace(a,ls);
        }
        return ;
    }
};