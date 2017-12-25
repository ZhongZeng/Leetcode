

/*
Leetcode 8. String to Integer (atoi)

Related Topics 
MathString
Similar Questions 
Reverse Integer, Valid Number

Next challenges: Divide Two Integers, 
Longest Uncommon Subsequence I, Tag Validator

Test Case:
"+5234"
"-5"
"   -5  "
"+-2"
"+223 abcd"
"+wer"
"2342+243"
"2147483648"
"-2147483648"
"-2147483649"

Runtime: 25 ms
Your runtime beats 26.14 % of cpp submissions.

*/


class Solution {
public:
    int myAtoi(string str) {
        // +/-, 0-9
        // the problem should be more clearly defined
        // how am I supposed to know to return 0 for invalid input 
        int num=0, i, z;// return number, i, 1st non-zero
        // remove 0s at end 
        for(string::reverse_iterator it=str.rbegin(); it!=str.rend(); it++){
            if(*it!=' '){
                break;
            }else{
                str.pop_back();
            }
        }
        
        // remove 0s from begining
        for(z=0; z!=str.size(); z++){
            if(str[z]!=' ') break;
        }
        
        // verify input
        bool  mns=false;
        for(int i=z; i!=str.size(); i++){
            if(str[i]=='-'||str[i]=='+'){
                if(mns) return 0;
                else    mns=true;
            }else if(isNum(str[i])){
                break;
            }else{
                return 0;
            }
        }
        
        // sign
        if(str[z]=='-'){
            i=z;
             // calculate number
            while(++i!=str.size()){
                if(isNum(str[i])){
                    if(num<-214748364||(num<-214748363&&8<str[i]-'0'))  return -2147483648;
                    else    num='0'-str[i]+num*10;
                }else{
                    break;
                }
            }
        }else{
            i=str[z]!='+'?z-1:z;
            // calculate number
            while(++i!=str.size()){
                if(isNum(str[i])){
                    if(214748364<num||(214748363<num&&7<str[i]-'0'))    return 2147483647;
                    else    num=str[i]-'0'+num*10;
                }else{
                    break;
                }
            }
        }
        
        return num;
    }
    
    bool isNum(char & c){
        return -1<c-'0'&&-1<'9'-c;
    }    
    
};

/*
//Runtime: 29 ms
//Your runtime beats 10.58 % of cpp submissions.
//Runtime: 39 ms
//Your runtime beats 2.20 % of cpp submissions.
class Solution {
public:
    int myAtoi(string str) {
        // +/-, 0-9
        // the problem should be more clearly defined
        // how am I supposed to know to return 0 for invalid input 
        int num=0, i, p=1;
        // remove 0s at end 
        for(string::reverse_iterator it=str.rbegin(); it!=str.rend(); it++){
            if(*it!=' '){
                break;
            }else{
                str.pop_back();
            }
        }
        
        // remove 0s from begining
        for(i=0; i!=str.size(); i++){
            if(str[i]!=' ') break;
        }
        if(i!=0)    str=str.substr(i,str.size()-i);        
        
        // verify input
        bool  mns=false;
        for(int i=0; i!=str.size(); i++){
            if(str[i]=='-'||str[i]=='+'){
                if(mns) return 0;
                else    mns=true;
            }else if(isNum(str[i])){
                break;
            }else{
                return 0;
            }
        }
        
        // sign
        if(str[0]=='-'){
            i=0;
             // calculate number
            while(++i!=str.size()){
                if(isNum(str[i])){
                    if(num<-214748364||(num<-214748363&&8<str[i]-'0'))  return -2147483648;
                    else    num='0'-str[i]+num*10;
                }else{
                    break;
                }
            }
        }else{
            i=str[0]!='+'?-1:0;
            // calculate number
            while(++i!=str.size()){
                if(isNum(str[i])){
                    if(214748364<num||(214748363<num&&7<str[i]-'0'))    return 2147483647;
                    else    num=str[i]-'0'+num*10;
                }else{
                    break;
                }
            }
        }
        
        return num*p;
    }
    
    bool isNum(char & c){
        return -1<c-'0'&&-1<'9'-c;
    }    
    
};
*/