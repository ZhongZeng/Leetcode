

/*
Leetcode 639. Decode Ways II

Companies 
Facebook 
Related Topics 
Dynamic Programming 
Similar Questions 
Decode Ways

Next challenges: Coin Path, Knight Probability in Chessboard, Cherry Pickup

Test Cases:
"**"
"126"
"12*34**"
"12*34**1237810123*0"
"**********1111111111"

Runtime: 59 ms
Your runtime beats 95.09 % of cpp submissions.

*/

class Solution {
public:
    int numDecodings(string s) {
		// O(n) time, O(1) space 
        // '*'->'1' to '9; mod 1000000007
        if(s.size()<1)  return 0;
        long a=1, b, c;// set a to 1 not 0
        
        if(s[0]=='*')   b=9;
        else if(s[0]=='0')  b=0;
        else    b=1;
        
        for(int i=1; i<s.size(); i++){
            c=a;
            a=b;            
            switch(s[i-1]){
                case '0':
                    if(s[i]=='*')   b=b*9%1000000007;
                    else if(s[i]=='0')  b=0;
                    break;
                case '1':
                    if(s[i]=='*')   b=(b+c)*9%1000000007;
                    else if(s[i]=='0')   b=c;
                    else    b=(b+c)%1000000007;
                    break;
                case '2':
                    if(s[i]=='*')   b=(c*6+b*9)%1000000007; //'1'-'6'
                    else if(s[i]=='0')  b=c;
                    else if(s[i]-'0'<7) b=(b+c)%1000000007;
                    break;
                case '*':
                    if(s[i]=='*')   b=(c*15+b*9)%1000000007;//15=9+6
                    else if(s[i]=='0')  b=c*2%1000000007;
                    else    b=(b+(s[i]-'0'<7?c*2%1000000007:c))%1000000007;
                    break;
                default://3'-'9'
                    if(s[i]=='*')   b=b*9%1000000007;
                    else if(s[i]=='0')  b=0;
                    break;
            }
            //cout<<a<<","<<b<<"; ";
        }
        //cout<<endl;
        
        return b;
    }
};
