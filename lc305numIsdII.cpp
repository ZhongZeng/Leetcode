

/*
Leetcode 305. Number of Islands II

Companies 
Google 
Related Topics 
Union Find 
Similar Questions 
Number of Islands

Next challenges: Redundant Connection II, Swim in Rising Water, Bricks Falling When Hit

Test Cases:
3
3
[[0,0],[0,1],[1,2],[2,1]]
3
3
[[0,1],[1,2],[2,1],[1,0],[0,2],[0,0],[1,1]]

Runtime: 164 ms
Your runtime beats 28.87 % of cpp submissions.

*/



class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        // Union Find: Quick Union w/ path compression 
        vector<int> rt(1, 1);
        unordered_map<int,pair<int, int>> us;
        unordered_map<int, unordered_map<int,pair<int, int>>> um;
        unordered_map<int, unordered_map<int,pair<int, int>>>::iterator umi;
        us.emplace(positions[0].second, positions[0]);
        um.emplace(positions[0].first, us);
        
        for(int i=1; i<positions.size(); i++){
            umi=um.find(positions[i].first);
            if(umi!=um.end()){
                umi->second.emplace(positions[i].second, positions[i]);
            }else{
                us.clear();
                us.emplace(positions[i].second, positions[i]);
                um.emplace(positions[i].first, us);
            }
            
            cnctIsd(um, positions[i], rt);
        }
        
        return rt;
    }
    
    void cnctIsd(unordered_map<int, unordered_map<int,pair<int, int>>>& um, pair<int,int>& po, vector<int>& rt){
        int cn=1;
        cn+=quickUnion( um, po, po.first-1, po.second);
        cn+=quickUnion( um, po, po.first+1, po.second);
        cn+=quickUnion( um, po, po.first, po.second-1);
        cn+=quickUnion( um, po, po.first, po.second+1);
        rt.push_back( rt.back()+cn );
        return ;
    }
    
    int quickUnion(unordered_map<int,unordered_map<int,pair<int, int>>>& um, pair<int,int>& po, int r, int c){
        unordered_map<int, unordered_map<int,pair<int, int>>>::iterator umi=um.find(r);
        if(umi!=um.end()){
            unordered_map<int,pair<int, int>>::iterator usi=umi->second.find(c);
            if(usi!=umi->second.end()){
                vector<unordered_map<int,pair<int, int>>::iterator> vc={usi}, vd;
                
                while(usi->second.first!=umi->first||usi->second.second!=usi->first){
                    umi=um.find(usi->second.first);
                    usi=umi->second.find(usi->second.second);
                    vc.push_back(usi);
                }
                for(int i=0; i<vc.size()-1; i++)    vc[i]->second=vc.back()->second;// path compression
                
                umi=um.find(po.first);
                usi=umi->second.find(po.second);
                vd.push_back(usi);
                while(usi->second.first!=umi->first||usi->second.second!=usi->first){
                    umi=um.find(usi->second.first);
                    usi=umi->second.find(usi->second.second);
                    vd.push_back(usi);
                }
                
                if(vc.back()!=vd.back()){
                    for(int i=0; i<vd.size(); i++)  vd[i]->second=vc.back()->second;// path compression
                    return -1;
                }else{
                    for(int i=0; i<vd.size(); i++)  vd[i]->second=vc.back()->second;// path compression
                    return 0;
                }
            }else{
                return 0;
            }
        }else{
            return 0;
        }
    }
    
};
