
/*
948. Bag of Tokens

Suggested tag: greedy, array, sort

Test Cases:
[100]
50
[100,200]
150
[100,200,300,400]
200

Runtime: 8 ms

*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        // greedy 
        int S=0;
        sort(tokens.begin(), tokens.end());
        
        for( int b=0, e=tokens.size()-1; b<=e; ){// b: next up; e: next down 
            if(b<=e&&tokens[b]<=P){
                while(b<=e&&tokens[b]<=P){
                    P-=tokens[b++];
                    S++;
                }                
            }else{
                break;
            }
            if(b>=e)    break;
            
            if(0<S){
                P+=tokens[e--];
                S--;
            }else{
                break;
            }
            // cout<<b<<","<<e<<":"<<P<<","<<S<<" ";
        }
        
        return S;
    }
};
