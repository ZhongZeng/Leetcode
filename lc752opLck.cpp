
/*
Leetcode 752. Open the Lock

*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // BFS; has table
        
        int n, ts, tt, tgt, dig;
        tgt=(target[0]-'0')*1000+(target[1]-'0')*100+(target[2]-'0')*10+target[3]-'0';
        //cout<<tgt<<endl;
        unordered_set<int> dd, vt;
        queue<pair<int,int>> qu;
        for(int i=0; i!=deadends.size(); i++){
            dd.emplace((deadends[i][0]-'0')*1000+(deadends[i][1]-'0')*100+(deadends[i][2]-'0')*10+deadends[i][3]-'0');
        }
        if(dd.find(0)!=dd.end())    return -1;
        
        qu.emplace(make_pair(0,0));
        while(!qu.empty()){
            if(qu.front().first==tgt)   return qu.front().second;
            ts=qu.front().first;
            n=qu.front().second;
            qu.pop();
            
            for(int i=0, p=1, q=10; i!=4; i++, p*=10, q*=10){
                dig=ts%q/p;
                if(dig==9)  tt=ts-9*p;
                else    tt=ts+p;
                if(notIn(tt, dd, vt)){
                    vt.emplace(tt);
                    qu.emplace(make_pair(tt,n+1));
                }
                

                if(dig==0)  tt=ts+9*p;
                else    tt=ts-p;
                if(notIn(tt, dd, vt)){
                    vt.emplace(tt);
                    qu.emplace(make_pair(tt,n+1));
                }             
            }
        }
        
        return -1;
    }
    
protected:
    bool notIn(int tt, unordered_set<int> & dd, unordered_set<int> & vt){
        return dd.find(tt)==dd.end()&&vt.find(tt)==vt.end();
    }
        
};
