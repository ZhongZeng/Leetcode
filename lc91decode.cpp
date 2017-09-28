
/*
Leetcode 91. Decode Ways

Related Topics 
String Dynamic Programming 
Similar Questions 
Decode Ways II 

Test Cases: 
"12120"
"12211212"
"12321132123"
"68456747"
"0"
"10"
"100"
"60"
"12823430"
""

Runtime: 3 ms
You are here! 
Your runtime beats 13.67 % of cpp submissions.

*/

class Solution {
public:
    int numDecodings(string s) {
        if( s.size()<1 )    return 0;
        return numDec( s.begin(), s.end(), 1 ) ;
    }

protected:
    int numDec(string::iterator b, string::iterator e, int num0){ 
        if( !(b<e) ) return num0;        
        if( *b=='0' ){
            return 0;
        }
        
        int c1=*b-'0', c2, n1=0, n2=1, temp;
        while( b!=e ){
            c2 = *b-'0' ;             
            if( c2==0 ) {
                return (c1==1 || c1==2) ? numDec( ++b, e, n1) : 0 ;
            }else{
                if( c1==1 || (c1==2 && c2<7) ){
                    temp = n2 ;
                    n2 += n1 ; 
                    n1 = temp ;                       
                }else{
                    n1 = n2 ; 
                }            
                c1 = c2 ;   
                // cout<<n1<<' '<<n2<<endl;
            }
            b++;
        }        
        return n2*num0;
    }    
    
};
