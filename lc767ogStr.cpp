
/*
Leetcode 767. Reorganize String

Related Topics 
String, Heap, Greedy, Sort 
Similar Questions 
Rearrange String k Distance ApartTask Scheduler

Next challenges: Rearrange String k Distance Apart, Task Scheduler

Test Cases:
"aab"
"aaab"
"abcdetfff"

Runtime: 3 ms
Sorry. We do not have enough accepted submissions to show runtime distribution chart.

*/ 

class Solution {
public:
    string reorganizeString(string S) {
        // S will consist of lowercase letters and have length in range [1, 500].
        // hash table; heap; greedy; O(n*lg(n)) time 
        if(S.size()<2)  return S;
        
        vector<int> vc(26,0);
        vector<pair<int,char>> hp;
        pair<int,char> pr, ps;
        string rt, ch="abcdefghijklmnopqrstuvwxyz";
        for(int i=0; i<S.size(); i++)   vc[S[i]-'a']+=1;// hash table, counting letters, O(n)
        for(int i=0; i<vc.size(); i++){// heap
            if(vc[i]!=0)    pushHp(hp, make_pair(vc[i],ch[i]));
        }
        
        ps=hp[0];
        popHp(hp);
        ps.first-=1;
        rt.push_back(ps.second);
        while(!hp.empty()){// heap; greedy, push_back the diff most char
            pr=hp[0];
            popHp(hp);
            pr.first-=1;
            if(pr.second!=rt.back())    rt.push_back(pr.second);
            else    return "";
            
            if(0<ps.first)  pushHp(hp, ps);
            ps=pr;
        }
        
        return 0<ps.first?"":rt;
    }
    
protected:
    void pushHp(vector<pair<int,char>>& hp, pair<int,char> pr){// sort in descending order of 1st int&2nd char
        int i=hp.size();
        hp.push_back(pr);
        while(0<i){
            if(largerThan(hp[i],hp[(i-1)>>1])){
                pr=hp[i];
                hp[i]=hp[(i-1)>>1];
                hp[(i-1)>>1]=pr;
                i=(i-1)>>1;
            }else{
                return ;
            }
        }
        return ;
    }
    
    void popHp(vector<pair<int,char>>& hp){
        hp[0]=hp.back();
        hp.pop_back();
        int i=0;
        pair<int,char> pr;
        while(2*i+2<hp.size()){
            if(largerThan(hp[2*i+2],hp[i])&&largerThan(hp[2*i+2],hp[2*i+1])){
                pr=hp[2*i+2];
                hp[2*i+2]=hp[i];
                hp[i]=pr;
                i=2*i+2;
            }else if(largerThan(hp[2*i+1],hp[i])){
                pr=hp[2*i+1];
                hp[2*i+1]=hp[i];
                hp[i]=pr;
                i=2*i+1;
            }else{
                return ;
            }
        }
        if(2*i+1<hp.size()&&largerThan(hp[2*i+1],hp[i])){
            pr=hp[2*i+1];
            hp[2*i+1]=hp[i];
            hp[i]=pr;            
        }
        return ;
    }
    
    bool largerThan(pair<int,char>& pr, pair<int,char>& ps){
        if(ps.first<pr.first)   return true;
        else if(pr.first<ps.first)  return false;
        else    return 0<pr.second-ps.second;
    }
};
