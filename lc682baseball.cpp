

/*
Leetcode 682. Baseball Game

Related Topics 
Stack 

Next challenges: Largest Rectangle in Histogram, Min Stack, Decode String

Test Cases: 
["5","-2","4","C","D","9","+","+"]
["5","-2","4","D","C","+"]
["5","2","C","D","+"]

Runtime: 3 ms
You are here! 
Your runtime beats 68.72 % of cpp submissions.

*/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum=0, num, dig;
        vector<int> vp; // score in ops, added value
        for(int i=0; i!=ops.size(); i++ ){
            if( ops[i]=="C" ){
                sum -= *vp.rbegin();
                vp.pop_back();
            }else if( ops[i]=="D" ){
                sum += *vp.rbegin()*2;
                vp.push_back( *vp.rbegin()*2 );
            }else if( ops[i]=="+" ){
                num = vp[vp.size()-1]+vp[vp.size()-2];
                sum += num;
                vp.push_back( num );
            }else{
                num = 0;                
                if( ops[i][0]!='-' ){
                    dig = 1;
                    for(int j=ops[i].size()-1; j!=-1; j--){
                        num += (ops[i][j]-'0')*dig;
                        dig *= 10;
                    }
                }else{
                    dig = -1;
                    for(int j=ops[i].size()-1; j!=0; j--){
                        num += (ops[i][j]-'0')*dig;
                        dig *= 10;
                    }                    
                }
                sum += num;
                vp.push_back( num );
            }          
            // cout<<sum<<endl;
        }
        // cout<<endl;
        return sum; 
    }
};

