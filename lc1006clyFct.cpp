
/*
1006. Clumsy Factorial

Related Topics:	Math

Test Cases:
1
2
3
4
9
10
11

Runtime: 4 ms

*/

class Solution {
public:
    int clumsy(int N) {
        // math; N in [1,10000] 
        int rt=0, i=N, t;
        
        rt=i;
        if(0<--i)   rt*=i;// *i
        else    return rt;
        if(0<--i)   rt/=i;// /i
        else    return rt;
        
        while( true ){
            if(0<--i)   rt+=i;// +i
            else    return rt;
            
            if(0<--i){// -
                t=i;
                if(0<--i)   t*=i;// *
                else    return rt-t;
                if(0<--i)   t/=i;// /
                else    return rt-t;
                rt-=t;
            }else{
                return rt;
            }
        }
        
        return rt;
    }
};
