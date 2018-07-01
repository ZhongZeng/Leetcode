
/*
Leetcode 860. Lemonade Change

Test Cases:
[5,5,5,10,20]
[5,5,10]
[10,10]
[5,5,10,10,20]

*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // DFS, bills[i] will be either 5, 10, or 20.
        vector<int> vc(2,0);
        
        for( int i=0; i<bills.size(); i++){
            if(bills[i]==5){
                vc[0]+=1;
            }else if(bills[i]==10){
                if(0<vc[0]){
                    vc[0]-=1;
                    vc[1]+=1;
                }else{
                    return false;
                }
            }else{
                if(0<vc[1]){
                    vc[1]-=1;
                    if(0<vc[0]) vc[0]-=1;
                    else    return false;
                }else if(2<vc[0]){
                    vc[0]-=3;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
};
