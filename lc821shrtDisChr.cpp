

/*
Leetcode 821. Shortest Distance to a Character

Weekly Contest 81  

Test Case:
"loveleetcode"
"e"

Runtime: 15 ms

*/


class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        // BFS, O(n)
        // All letters in S and C are lowercase.
        // C is a single character, and guaranteed to be in string S.
        int d=0;
        vector<int> rt(S.size(), -1), vt, ut;
        
        for(int i=0; i<S.size(); i++){
            if(S[i]==C){
                rt[i]=d;
                vt.push_back(i);
            }
        }
        
        while(!vt.empty()){
            ut.clear();
            d++;
            for(int i=0; i<vt.size(); i++){
                if(0<vt[i]&&rt[vt[i]-1]<0){
                    rt[vt[i]-1]=d;
                    ut.push_back(vt[i]-1);
                }  
                if(vt[i]+1<rt.size()&&rt[vt[i]+1]<0){
                    rt[vt[i]+1]=d;
                    ut.push_back(vt[i]+1);
                }    
            }
            
            vt=ut;            
        }
        
        return rt;
    }
};
