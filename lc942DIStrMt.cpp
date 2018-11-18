
/*
Leetcode 942. DI String Match

Test Cases:
"IDID"
"III"
"DDI"

Runtime: 48 ms

*/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        // greedy, O(n) time&space  
        vector<int> rt;
        int mx=S.size(), mn=0;
        if(S.size()<1)  return rt;
        
        for( int i=S.size()-1, t=0; -1<i; i--){// record consecutive 'I'&'D'
            if(S[i]=='D'){
                if(0<t) t=-1;
                else    t--;
            }else{// S[i]=='I'
                if(t<0) t=1;
                else    t++;
            }
            rt.push_back(t);
        }
        rt.push_back(rt.back()<0?rt.back()-1:rt.back()+1);
        //for(auto e:rt)  cout<<e<<" ";   cout<<endl;
        
        for( int i=rt.size()-1, t; -1<i; ){// greedy 
            if(0<rt[i]){
                mx=mx-rt[i];
                for( t=rt[i]; -1<i&&0<rt[i]; i--)    rt[i]=mx+t+1-rt[i];
            }else{// rt[i]<0
                mn=mn-rt[i];
                for( t=rt[i]; -1<i&&rt[i]<0; i--)    rt[i]=mn+t-1-rt[i];
            }
        }
        
        for( int i=0, j=rt.size()-1, t; i<j; i++, j-- ){// reverse rt 
            t=rt[i];
            rt[i]=rt[j];
            rt[j]=t;
        }
        
        return rt;
    }
};
