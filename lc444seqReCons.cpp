

/*
Leetcode 444. Sequence Reconstruction

Companies 
Google
Related Topics 
Graph, Topological Sort 
Similar Questions 
Course Schedule II

Next challenges: Evaluate Division, Is Graph Bipartite?, Similar String Groups

Test Cases:
[1]
[[1],[2,3],[3,2]]
[1]
[[1,-9999],[-9999,-9998],[-9998,-9999]]
[5,3,2,4,1]
[[5,3,2,4],[4,1],[1],[3],[2,4],[1000000000]]
[1]
[[],[]]
[1,2,3]
[[1,2],[1,3]]
[1,2,3]
[[1,2]]
[1,2,3]
[[1,2],[2,3],[4,1]]
[4,1,5,2,6,3]
[[5,2,6,3],[4,1,5,2]]
[1,2,3]
[[1,2],[1,3],[2,3]]

Runtime: 179 ms
Your runtime beats 24.48 % of cpp submissions.

*/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        // topological sort, O(n) time&space
        // construct topological order & check if same as org         
        // seqs is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 10000
        int mx=0;
        unordered_map<int,unordered_set<int>> be;// backward edges 
        unordered_map<int,unordered_set<int>>::iterator umi;
        unordered_set<int>::iterator usi;
        unordered_map<int,int> mf;// # of forward going edges
        unordered_map<int,int>::iterator mfi;
        
        for(int i=0; i<seqs.size(); i++){// recorde backward edges 
            for(int j=seqs[i].size()-1; 0<j; j--){
                umi=be.find(seqs[i][j]);
                if(umi!=be.end()){
                    usi=umi->second.find(seqs[i][j-1]);
                    if(usi==umi->second.end())  umi->second.emplace(seqs[i][j-1]);
                }else{
                    unordered_set<int> us;
                    us.emplace(seqs[i][j-1]);
                    be.emplace(seqs[i][j], us);
                }
            }
        }

        for(int i=0; i<seqs.size(); i++){// recorde # of forward edges 
            for(int j=seqs[i].size()-1; 0<j; j--){
                mfi=mf.find(seqs[i][j-1]);
                if(mfi!=mf.end())   mfi->second+=1;
                else    mf.emplace(seqs[i][j-1],1);
                mx=mx<seqs[i][j]?seqs[i][j]:mx;
            }
            mx=mx<seqs[i][0]?seqs[i][0]:mx;
        }
        
        // topological sort - find start position 
        vector<int> vn(mx,0), vs, ts;
        for(mfi=mf.begin(); mfi!=mf.end(); mfi++)   vn[mfi->first]=1;//1-has outgoing edges 
        for(int i=0; i<vn.size(); i++)  if(vn[i]!=1)    vs.push_back(vn[i]);
        if(vs.size()!=1)    return false;
        
        while(!vs.empty()){
            ts.push_back(vs[0]);
            vs.pop_back();
            vn[ts.back()]=2;// visited 
            
            umi=be.find(ts.back());
            if(umi!=be.end()){
                for(usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                    mfi=mf.find(*usi);// mfi!=mf.end() guranteed, since *usi has outgoing edges
                    mfi->second-=1;
                    if(mfi->second==0&&vn[*usi]!=2) vs.push_back(*usi);
                }                
            }
            
            if(vs.size()!=1)    return false;
        }
        
        // compare ts w/ org 
        if(ts.size()!=org.size())   return false;
        for(int i=0, j=ts.size()-1; i<org.size(); i++, j--)
            if(org[i]!=ts[j])   return false;
        
        return true;
    }
};
