
/*

Leetcode 67. Add Binary 

Related Topics 
Math String 
Similar Questions 
Add Two Numbers, Multiply Strings, Plus One 

Next challenges: Multiply Strings, Plus One

Test Cases: 
"0"
"0"
"100"
"111"
"1011"
"11"

Runtime: 3 ms
You are here! 
Your runtime beats 21.60 % of cpp submissions. 

*/


class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size()<a.size())   return addBinary(b, a);
        string s;
        int i=-1;
        bool k=false;        
        reverse( a.begin(), a.end());
        reverse( b.begin(), b.end());
        
        while( ++i != a.size() ){
            if( k ){
                if(b[i]!='0'){
                    if(a[i]!='0'){
                        s.push_back('1');
                    }else{
                        s.push_back('0');                        
                    }
                }else{
                    if(a[i]!='0'){
                        s.push_back('0');
                    }else{
                        s.push_back('1');
                        k=false;
                    }                    
                }
            }else{
                if(b[i]!='0'){
                    if(a[i]!='0'){
                        s.push_back('0');
                        k=true;
                    }else{
                        s.push_back('1');
                    }
                }else{
                    if(a[i]!='0'){
                        s.push_back('1');
                    }else{
                        s.push_back('0');
                    }                    
                }                
            }            
        }
        
        --i;
        while( ++i != b.size() ){
            if( k ){
                if(b[i]!='0'){
                    s.push_back('0');      
                }else{
                    s.push_back('1');
                    k=false;
                }
            }else{
                if(b[i]!='0'){
                    s.push_back('1');
                }else{
                    s.push_back('0');
                }
            }        
        }        
        
        if( k ) s.push_back('1');
            
        reverse(s.begin(),s.end());
        
        return s;
    }
};

