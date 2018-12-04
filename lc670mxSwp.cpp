
/*
Leetcode 670. Maximum Swap

Related Topics 
Array Math 
Similar Questions 
Create Maximum Number 

Next challenges: Create Maximum Number

Test Cases:
10
9
1993
98368
2736
9876
543232121
543232721

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Swap.

*/

class Solution {
public:
    int maximumSwap(int num) {
        // O(n) time&space (can be optimized to O(1)space), array, greedy 
        int rt=0, mi=0, s1=0, s2=0;
        vector<int> vc;
        for( ; 0<num; num/=10)  vc.push_back(num%10);
        
        for( int i=1; i<vc.size(); i++){// swap largest value w/ most siginificant digit
            if(vc[i]<vc[mi]){
                s1=mi;
                s2=i;
            }else if(vc[mi]<vc[i]){
                mi=i;
            }
        }
        
        mi=vc[s1];
        vc[s1]=vc[s2];
        vc[s2]=mi;
        
        for( int i=vc.size()-1; -1<i; i--) rt=rt*10+vc[i];
        
        return rt;
    }
};

// Runtime: 6 ms	Your runtime beats 0.54 % of cpp submissions.
// Runtime: 3 ms	Your runtime beats 12.54 % of cpp submissions. 
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

