
/*
Leetcode 157. Read N Characters Given Read4

Companies   
Facebook 
Related Topics 
String 
Similar Questions 
Read N Characters Given Read4 II - Call multiple times

Test Cases:
"ab"
1
"abc"
4
"abcde"
5 

Next challenges: Read N Characters Given Read4 II - Call multiple times

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions. 

*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sum=0, i, t;
        
        for( i=0; i<n; i+=t){
            t=read4(buf);
            buf+=t;
            sum+=t;
            if(t<4) break;
        }
        
        return sum<n?sum:n;
    }
};
