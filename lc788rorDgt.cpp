
/*
Leetcode 788. Rotated Digits

Test Cases:
9
10
45
99
100
891
1000
10000

Runtime: 3 ms

*/


class Solution {
public:
    int rotatedDigits(int N) {
        // N  will be in range [1, 10000].
        // contains 2,5,6,9; only contains 2,5,6,9 & 0,1,8     
        // brute force O(N*lg(N)) 
        int sum=0, num=N, d, ten=1;
        bool b=false;
        vector<int> vc, df={0,4,40,316,2320}, lg={1,7,49,343,2401};
        // 0;<10:4;<100:4*7+3*4;<1000:4*7*7+3*40;<10000:4*7*7*7+3*316
        // 0;<10:7;<100:7*7;    <1000:7*7*7;     <10000:7*7*7*7
        for( int i=0; 0<num; num/=10, ten*=10, i++) vc.push_back(num%10);
        
        for( int i=vc.size()-1; -1<i; i--){
            d=vc[i];
            if(b){
                sum+=(rvt(d)+sam(d))*lg[i];
            }else{
                sum+=rvt(d)*lg[i]+sam(d)*df[i];
                if(d==2||d==5||d==6||d==9)  b=true;
            }
            if(d==3||d==4||d==7)    return sum;
        }
        if((d==2||d==5||d==6||d==9)||(b&&(d==0||d==1||d==8)))   sum++;
        
        return sum;
    }

protected:    
    int rvt(int d){//2,5,6,9
        if(d<3)    return 0;//012
        else if(d<6)    return 1;//345
        else if(d<7)    return 2;//6
        else    return 3;//789
    }
    
    int sam(int d){//0,1,8
        if(d<1) return 0;
        else if(d<2)    return 1;
        else if(d<9)    return 2;
        else    return 3;
    }
};
