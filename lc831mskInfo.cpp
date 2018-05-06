

/*
Leetcode 831. Masking Personal Information

Test Cases:
"LeetCode@LeetCode.com"
"AB@qq.com"
"1(234)567-890"
"86-(10)12345678"
"+86(88)1513-7-74"
"+(501321)-50-23431"

Runtime: 6 ms

*/


class Solution {
public:
    string maskPII(string S) {
        string rt;
        int i;
        bool em=false;
        for(int i=0; i<S.size(); i++){//'+', '-', '(', ')', ' '
            if((!isNum(S[i]))&&S[i]!='+'&&S[i]!='-'&&S[i]!='('&&S[i]!=')'&&S[i]!=' '){
                em=true;
                break;
            }
        }
        
        if(em){// email; We define a name to be a string of length ≥ 2 consisting of only lowercase letters a-z or uppercase letters A-Z.
            if(isUpper(S[0]))   rt.push_back((char)(S[0]+32));
            else    rt.push_back(S[0]);
            rt.append("*****");
            
            for( i=0; i<S.size()&&S[i]!='@'; i++){}
            
            if(isUpper(S[i-1])) rt.push_back((char)(S[i-1]+32));
            else    rt.push_back(S[i-1]);
            
            rt.push_back('@');
            
            for( i++; i<S.size(); i++){
                if(isUpper(S[i]))   rt.push_back((char)(S[i]+32));
                else    rt.push_back(S[i]);
            }
        }else{// phone number: return "***-***-1111" || "+***-***-***-1111"
            int p=0;
            string l4;
            for( i=S.size()-1; p<4; i--){
                if(isNum(S[i])){
                    l4.push_back(S[i]);
                    p++;
                }
            }
            
            for( ; -1<i; i--)   if(isNum(S[i])) p++;
            
            if(p<11){
                rt="***-***-";
            }else if(p<12){
                rt="+*-***-***-";
            }else if(p<13){
                rt="+**-***-***-";
            }else{
                rt="+***-***-***-";
            }
            
            for(int i=3; -1<i; i--) rt.push_back(l4[i]);
            //cout<<p<<endl;
        }
        
        return rt;
    }
    
    bool isUpper(char& c){
        int t=c-'A';
        return -1<t&&t<26;
    }
    
    bool isNum(char& c){
        int t=c-'0';
        return -1<t&&t<10;
    }
};
