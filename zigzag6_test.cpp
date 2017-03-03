/* zigzag6
*/
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        int inc=2*numRows-2; //increment
        if ( len<=numRows || numRows==1) return s;
        int  oddRow= len % inc - 1;
        string str="";
        int j, inc1, inc2;
        for (int i=0; i< numRows;i++){
            inc2 = i*2;
            inc1 = inc - inc2;
            if (i==0 || i==numRows - 1) {
                 for (j=i; j<len; j=j+inc){
                    str.push_back(s[j]);
                 }
            }else if( i<=oddRow && i!=0 ){
                str.push_back(s[i]);
                for (j=i+inc1; j<len; j=j+inc){
                    str.push_back(s[j]);
                    str.push_back(s[j+inc2]);
                }
            }else{
                for (j=i; j<len; j=j+inc){
                    str.push_back(s[j]);
                    str.push_back(s[j+inc1]);
                 }
            }   
        }
    return str;
    }
};

int main(){
string str1 = "abcde";	
Solution s;
cout << s.convert("PAYPALISHIRING", 3) << endl;
cout << s.convert("ABCDE", 4) << endl;
cout << str1[8] << endl;
cout << (5%6-4) << endl;
cout << s.convert("AB", 1) << endl;


/*
string a = "";
string b = "abc";
b.append("d");
b.push_back(b[3]);
cout << a << endl;	
cout << b[0]<< b[1] << b[3]<< b[4]<< endl;	
*/	

return 0;	
}

//Time limit exceeded
/*
class Solution {
public:
    string convert(string s, int numRows) {
        string str="";
        int len = s.length();
        int inc=2*numRows-2; //increment
        int j;
        for (int i=0; i< numRows;i++){
            if (i==0 || i==numRows - 1) {
                 for (j=i; j<len; j=j+inc){
                    str.push_back(s[j]);
                 }
            }else{
                for (j=i; j<len; j=j+inc){
                    str.push_back(s[j-i]);
                    str.push_back(s[j]);
                 }
            }   
        }
    return str;
    }
};
*/