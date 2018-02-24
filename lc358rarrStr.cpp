
/*
Leetcode 358. Rearrange String k Distance Apart

Companies 
Google 
Related Topics 
Hash Table, Heap, Greedy 
Similar Questions 
Task Scheduler, Reorganize String

Test Cases:
"aabbcc"
3
"aaabc"
3
"abacabcd"
2
""
0
""
1
"bbabcaccaaabababbaaaaccbbcbacbacacccbbcaabcbcacaaccbabbbbbcacccaccbabaccbacabca"
1
"a"
2

Runtime: 13 ms
Your runtime beats 89.20 % of cpp submissions.

*/

class Solution {
public:
    string rearrangeString(string s, int k) {
        // All input strings are given in lowercase letters. 
        if(k<2) return s;
        string rt, ch="abcdefghijklmnopqrstuvwxyz";
        vector<int> lt(26,0);
        pair<int,char> pr;
        vector<pair<int,char>> hp;
        queue<pair<int,char>> qu;
        // hash table, O(n) time
        for(string::iterator it=s.begin(); it!=s.end(); it++)   lt[*it-'a']+=1;
        for(int i=0; i<lt.size(); i++)  if(lt[i]!=0)    pushHp(hp, make_pair(lt[i],ch[i]));
        
        //heap; greedy:push_back possible largrest# char; queue; O(k*lg(26)) time
        for(int i=1; i<k; i++){
            pr=hp[0];
            pr.first-=1;
            qu.push(pr);
            rt.push_back(pr.second);
            popHp(hp);
        }
        
        while(!hp.empty()){
            pr=hp[0];
            popHp(hp);
            pr.first-=1;
            rt.push_back(pr.second);
            
            if(0<qu.front().first)  pushHp(hp, qu.front());
            qu.pop();
            qu.push(pr);
        }
        
        while( !qu.empty()){
            if(0<qu.front().first) return "";
            qu.pop();
        }
        
        return rt;
    }
    
protected:
    void pushHp(vector<pair<int,char>>& hp, pair<int,char> pr){// largest first heap 
        int i=hp.size();
        hp.push_back(pr);
        while(0<i){
            if(largerThan(hp[i],hp[(i-1)>>1])){
                pr=hp[(i-1)>>1];
                hp[(i-1)>>1]=hp[i];
                hp[i]=pr;
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
