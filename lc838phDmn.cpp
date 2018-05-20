

/*
Leetcode 838. Push Dominoes


Test Cases:
".L.R...LR..L.."
"RR.L"

Runtime: 34 ms

*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        // a falling domino expends no additional force to a falling or already fallen domino.
        // 0 <= N <= 10^5
        // String dominoes contains only 'L', 'R' and '.'
        string rt;
        vector<int> vc;// distance to nearest 'R' to the left 
        int i, c=1;
        
        for( i=0; i<dominoes.size(); i++){
            if(dominoes[i]=='L'){
                c=1;
                rt.push_back('L');
            }else if(dominoes[i]=='R'){
                c=0;
                rt.push_back('R');
            }else{
                rt.push_back('.');
                if(c<1) c--;
            }
            vc.push_back(c);
        }
        //for(auto e:vc)  cout<<e<<" ";   cout<<endl;
        
        for( i=rt.size()-1, c=1; -1<i; i--){// c:'L'; vc[i]:'R'
            if(rt[i]=='L'){
                c=0;
            }else if(rt[i]=='R'){
                c=1;
            }else{
                if(c<1) c--;
                
                if(vc[i]<0&&(c<vc[i]||c==1)){
                    rt[i]='R';
                }else if(c<0&&(vc[i]<c||vc[i]==1)){
                    rt[i]='L';
                }
            }
        }
        
        return rt;
    }
};
