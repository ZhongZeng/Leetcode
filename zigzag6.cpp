//You are here! Your runtime beats 37.13% of cpp submissions.

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        int inc=2*numRows-2; //increment
        if ( len<=numRows || numRows==1) return s;
        int  oddRow= len % inc ;
        string str="";
        int j, inc1, inc2;
        for (int i=0; i< numRows;i++){
            inc2 = i*2;
            inc1 = inc - inc2;
            if (i==0 || i==numRows - 1) {
                 for (j=i; j<len; j=j+inc){
                    str.push_back(s[j]);
                 }
            }/*else if( i<oddRow ){
                str.push_back(s[i]);
                for (j=i+inc1; j<len; j=j+inc){
                    str.push_back(s[j]);
                    str.push_back(s[j+inc2]);
                }
            }*/else{
                for (j=i; j<len; j=j+inc){
                    str.push_back(s[j]);
                    if (j+inc1<len) str.push_back(s[j+inc1]);
                 }
                 /*if (j<len) str.push_back(s[j]); //sudstituting j<len as j<len-inc
                 if (j+inc1<len) str.push_back(s[j+inc1]);
                 */
            }   
        }
    return str;
    }
};