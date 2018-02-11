
/*
Leetcode 780. Reaching Points

Test Cases:
1
1
1
1
9
5
12
8
1
1
3
5
35
13
455955547
420098884
1
1
1000000000
1

189 / 189 test cases passed.
Runtime: 6 ms

*/

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // start from (tx,ty), otherwise O(n**2) for DP
        // cout<<tx<<","<<ty<<" ";
        if(sx==tx&&sy==ty){
            return true;
        }else if(sx<=tx&&sy<=ty){
            if(tx<ty){// only ty is reduceable
                if(sy<tx){
                    return reachingPoints(sx,sy,tx,ty%tx);
                }else{
                    if((ty-sy)%tx!=0)   return false;
                    else    return (tx-sx)%sy==0;// achieveable sy==ty
                }
            }else if(ty<tx){// only tx is reduceable
                if(sx<ty){
                    return reachingPoints(sx,sy,tx%ty,ty);
                }else{
                    if((tx-sx)%ty!=0)   return false;
                    else    return (ty-sy)%sx==0;// achieveable sy==ty
                }
            }else{
                return (sx==tx||sx==0)&&(sy==tx||sy==0);
            }
        }else{
            return false;
        }
    }
};

/*
// Wrong Answer 
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx==sx&&ty==sy){
            return true;
        }else if(tx<sx||ty<sy){
            return false;
        }else{
            if(tx<ty){
                return reachingPoints(sx, sy, tx, (ty-sy)%tx==0?sy:+sy);
            }else if(ty<tx){
                return reachingPoints(sx, sy, tx-ty, ty);
            }else{
                return reachingPoints(sx, sy, 0, ty)||(sx, sy, tx, 0);
            }
        }
    }
};

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // transform equivalent to (x,0) or (0,y) reflected on line x+y=sx+sy
        // rather Math
        //cout<<sx<<","<<sy<<endl;
        unordered_map<int,unordered_set<int>> um;
        return reachingPoints(sx,sy,tx,ty,um);
    }

    bool reachingPoints(int sx, int sy, int tx, int ty, unordered_map<int,unordered_set<int>>& um) {
        if(sx<=tx&&sy<=ty){
            emp(sx, sy, um);
            unordered_map<int,unordered_set<int>>::iterator umi=um.find(tx);
            if(umi!=um.end()&&umi->second.find(ty)!=umi->second.end()){
                return true;
            }else{
                return reachingPoints(sx+sy,sy,tx,ty,um)||reachingPoints(sx,sx+sy,tx,ty,um);
            }
        }else{
            return false;
        }
    }
    
    void emp(int& sx, int& sy, unordered_map<int,unordered_set<int>>& um){
        unordered_map<int,unordered_set<int>>::iterator umi=um.find(sx);
        unordered_set<int>::iterator ui;
        
        if(umi!=um.end()){
            ui=umi->second.find(sy);
            if(ui==umi->second.end())   umi->second.emplace(sy);
        }else{
            unordered_set<int> u;
            u.emplace(sy);
            um.emplace(sx,u);
        }
        return ;
    }
};
*/