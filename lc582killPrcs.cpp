

/*
Leetcode 582. Kill Process

Companies 
Bloomberg 
Related Topics 
Tree, Queue 

Next challenges: Verify Preorder Sequence in Binary Search Tree, 
Delete Node in a BST, Subtree of Another Tree 

Test Cases:
[1,3,10,5]
[3,0,5,3]
5

Runtime: 227 ms
Your runtime beats 19.16 % of cpp submissions.

*/

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // hash table
        vector<int> rt, vc={kill}, vd;
        unordered_set<int> us;
        unordered_set<int>::iterator usi;
        unordered_map<int,unordered_set<int>> um;
        unordered_map<int,unordered_set<int>>::iterator umi;
        for(int i=0; i<pid.size(); i++){
            umi=um.find(ppid[i]);
            if(umi!=um.end()){
                usi=umi->second.find(pid[i]);
                if(usi==umi->second.end())  umi->second.emplace(pid[i]);
            }else{
                us.clear();
                us.emplace(pid[i]);
                um.emplace(ppid[i],us);
            }
        }
        
        while(!vc.empty()){// BFS
            vd.clear();
            for(int i=0; i<vc.size(); i++){
                rt.push_back(vc[i]);
                umi=um.find(vc[i]);
                if(umi!=um.end()){
                    for(usi=umi->second.begin(); usi!=umi->second.end(); usi++) vd.push_back(*usi);
                }
            }
            
            if(vd.empty())  return rt;
            vc.clear();
            for(int i=0; i<vd.size(); i++){
                rt.push_back(vd[i]);
                umi=um.find(vd[i]);
                if(umi!=um.end()){
                    for(usi=umi->second.begin(); usi!=umi->second.end(); usi++) vc.push_back(*usi);
                }
            }            
        }
        
        return rt;
    }
};
