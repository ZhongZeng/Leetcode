
/*
Leetcode 625. Minimum Factorization

Companies   
Tencent
Related Topics 
Math, Recursion 

Test Cases:
48
35
221
18000000

Next challenges: Remove 9, Chalkboard XOR Game, Mirror Reflection

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    int smallestFactorization(int a) {
        // 2,3,5,7=>4,6,8,9; minimum-digit, combine 2&3 as much as possible 
        if(a<10)    return a;
        int rt=0;
        vector<int> vd={2,3,4,5,6,7,8,9}, vf(8,0), vc={0,1,3,5};
        
        // Find Factors
        for( int i=0, l, t; i<vc.size(); i++){
            for( l=vc[i], t=vd[l]; a%t==0; vf[l]++) a=a/t;
        }
        if(a!=1)    return 0;
        
        // Combine Factors
        vf[6]=vf[0]/3;// 2*2*2=8
        vf[0]=vf[0]%3;
        
        switch(vf[0]){
            case 0:
                vf[7]=vf[1]/2;// 3*3=9
                vf[1]=vf[1]%2;
                break;
            case 1:
                if(vf[1]%2==1){
                    vf[4]=1;// 2*3=6
                    vf[0]=0;
                }
                vf[7]=vf[1]/2;// 3*3=9
                vf[1]=0;
                break;
            case 2:
                if(vf[1]%2==0){
                    vf[0]=0;// one 2*2=4
                    vf[2]=1;
                }else{
                    vf[0]=1;// one 2*3=6; one 2 remaining 
                    vf[4]=1;
                }
                vf[7]=vf[1]/2;// 3*3=9
                vf[1]=0;
                break;
        }
        
        // Calculate Return Value; rt<2147483648 required
        for( int i=0; i<vf.size(); i++){
            for( int j=0; j<vf[i]; j++){
                if(214748364<rt||(rt==214748364&&7<vd[i]))  return 0;
                else    rt=rt*10+vd[i];
            }
        }
        
        return rt;
    }
};
