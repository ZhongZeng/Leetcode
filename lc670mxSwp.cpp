
/*

Leetcode 670. Maximum Swap

Related Topics 
Array Math 
Similar Questions 
Create Maximum Number 

Next challenges: Create Maximum Number

Test Cases:
1993
98368
2736
9876
543232121
543232721

Runtime: 6 ms
You are here! 
Your runtime beats 0.54 % of cpp submissions.

Runtime: 3 ms
You are here! 
Your runtime beats 12.54 % of cpp submissions. 

*/


class Solution {
public:
    int maximumSwap(int num) {
        vector<int> vc;
        int i, c=0, mx, tmp, rv=0, num0=num;
        while( num!=0 ){
            vc.push_back( num%10 );
            num = num / 10;
            ++c;
        }
        
        i=c;
        while( --i!=0){
            if( vc[i]<vc[i-1] ){                
                break;
            }
        }
        
        
        if(i!=0){
            mx = i-1;
            while( --i!=-1 ){
                mx = vc[i]<vc[mx] ? mx : i;
                // mx = vc[mx]<vc[i] ? i : mx; // this is wrong, tricky
            }            
            
            // cout<<vc[mx]<<endl;
            
            for(i=c-1; ; i--)  if( vc[i]<vc[mx] ) break;
            
            tmp=vc[i];
            vc[i]=vc[mx];
            vc[mx]=tmp;
            
            for(i=c-1; i!=-1; i-- ){
                rv=rv*10+vc[i];
            }
            
            return rv;
        }else{
            return num0;
        }           
    }
};

