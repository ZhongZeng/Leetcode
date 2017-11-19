

/*
Leetcode 507. Perfect Number

Related Topics 
Math 
Similar Questions 
Self Dividing Numbers 

Next challenges: Self Dividing Numbers

Test Cases:
1
28
20
99999996


Runtime: 3 ms
You are here! 
Your runtime beats 41.19 % of cpp submissions.

Look at the 2 line Solution C++, which uses math. 

*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<1)   return false;
        int t=num-1, s=sqRt(num), r;
        //cout<<num<<" "<<s<<endl;
        for( int i=2; i<s; i++){
            if(num%i==0)    t-=i+num/i;
        }
        if(num%s==0){
            if(s*s!=num)    t-=s+num/s;
            else    t-=s;
        }    
        
        return t!=0? false:true;
    }

protected:    
    int sqRt(int num){
        int b=1, e=num/2+2, mid;//[b,e)
        while( b!=e-1 ){
            mid=b+(e-b)/2;
            if(num/mid<mid){
                e=mid;
            }else{
                b=mid;
            }            
        }                
        return b; //b*b<=num
    }
    
};
