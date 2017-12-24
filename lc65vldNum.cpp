


/*

Leetcode 65. Valid Number

Related Topics 
Math, String
Similar Questions 
String to Integer (atoi)

Next challenges: String to Integer (atoi)

Test Cases:
"3"
".3"
"3."
"3.32"
"4e3"
"3e1e3"
"."
" "
"e3"
"0e"
". 1"
" 1 e 3"
" 1 . "
"1 "
"-1"
"- 1"
"+.8"
" 005047e+6"

Runtime: 6 ms
Your runtime beats 15.64 % of cpp submissions.

*/


class Solution {
public:
    bool isNumber(string s) {
        // valid chars +/-, ' ','.','e',0-9
        // this problem should be more clearly defined 
        for(int i=s.size()-1; i!=-1; i--){// pop trailing spaces
            if(s[i]==' ')   s.pop_back();
            else    break;
        }
        
        bool  mns=false, dot=false, e=false, eNum=false, num=false;
        for(int i=0; i!=s.size(); i++){
            if(s[i]=='-'||s[i]=='+'){
                if(e){
                    if(eNum||mns)   return false;
                    else    mns=true;
                }else{
                    if(mns||dot||num)    return false;
                    else    mns=true;
                }
            }else if(s[i]==' '){
                if(mns||dot||e||num) return false;
            }else if(s[i]=='.'){
                if(e||dot)   return false;
                else    dot=true;
            }else if(s[i]=='e'){
                if(!num||e)    return false;
                e=true;
                eNum=false;
                mns=false;
            }else if(isNum(s[i])){
                num=true;
                eNum=true;
            }else{
                return false;
            }
        }
        
        if(!num)   return false;
        if(e&&!eNum)    return false;
        
        return true;
    }
    
    bool isNum(char & c){
        return -1<c-'0'&&-1<'9'-c;
    }
};