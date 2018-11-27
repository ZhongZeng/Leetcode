
/*
Leetcode 158. Read N Characters Given Read4 II - Call multiple times

Related Topics
String

Similiar Questions
Read N Characters Given Read4

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Read N Characters Given Read4 II - Call multiple times.
Runtime: 4 ms, faster than 13.26% of C++ online submissions for Read N Characters Given Read4 II - Call multiple times.

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
        int i=0, j, t; 
        
        for( i=0; loc<4&&i<n; i++, loc++)   *(buf+i)=temp[loc];
        
        while(i<n){
            t=read4(buf+i);
            i+=t;
            if(t<4) break;
        }
        
        if(n<i){
            loc=4-(i-n);
            for( j=0; j<i-n; j++)   temp[loc+j]=*(buf+n+j);            
        }
        
        return n<i?n:i;// i<=n
    }
    
protected:
    int loc=4;
    char temp[4];
};
