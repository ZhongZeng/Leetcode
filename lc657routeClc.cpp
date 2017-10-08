
/*
Leetcode 657. Judge Route Circle

Related Topics 
String 
Similar Questions 
Friend Circles 

Next challenges: Friend Circles

Test Cases:
"UD"
"ULRDUD"

Runtime: 19 ms
You are here! 
Your runtime beats 42.05 % of cpp submissions.

*/


class Solution {
public:
    bool judgeCircle(string moves) {
        int l,r,u,d;
        l=r=u=d=0;
        for( string::iterator it=moves.begin(); it!=moves.end(); it++){
            switch (*it){
                case 'L':   ++l;
                            break;
                case 'R':   ++r;
                            break;
                case 'U':   ++u;
                            break;
                case 'D':   ++d;
                            break;
            }
        }
        // cout<<l<<' '<<r<<' '<<u<<' '<<d<<endl;
        return l!=r || u!=d ? false : true ;
    }
};

