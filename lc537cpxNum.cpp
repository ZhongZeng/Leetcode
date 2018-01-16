
/*
Leetcode 537. Complex Number Multiplication

This should be Easy. 

Related Topics 
Math, String

Test Cases:
"1+1i"
"1+1i"
"1+-1i"
"1+-1i"

Next challenges: Group Shifted Strings, Self Crossing, Squirrel Simulation

Runtime: 4 ms
Your runtime beats 1.90 % of cpp submissions. which is within majority. 

*/

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1=0, b1=0, a2=0, b2=0, a0, b0;
        string s1, s2;
        getNum(a, a1, b1);
        getNum(b, a2, b2);
        //cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
        
        a0=a1*a2-b1*b2;
        b0=a1*b2+a2*b1;
        //cout<<a0<<" "<<b0<<endl;
        
        toStr(a0, s1);
        toStr(b0, s2);
        
        s1.push_back('+');
        s1.append(s2);
        s1.push_back('i');
        
        return s1;
    }

protected:    
    void getNum(string& a, int& a1, int& b1){
        int i=0, ng1=1, ng2=1;
        if(a[0]=='-'){
            ng1=-1;
            i=1;
        }
        for( ; i<a.size(); i++){
            if(a[i]!='+')   a1=a1*10+a[i]-'0';
            else    break;
        }
        a1=a1*ng1;
        
        if(a[++i]=='-'){
            ng2=-1;
            i++;
        }
        for( ; i<a.size(); i++){
            if(a[i]!='i')   b1=b1*10+a[i]-'0';
        }
        b1=b1*ng2;
        
        return ;
    }
    
    void toStr(int& a0, string& s1){
        bool ng=false;
        if(a0<0){
            ng=true;
            a0=0-a0;
        }else if(a0==0){
            s1="0";
            return ;            
        }
        
        while(a0!=0){
            s1.push_back((char)(a0%10+'0'));
            a0=a0/10;
        }
        
        if(ng)  s1.push_back('-');
        
        reverse(s1.begin(), s1.end());
        
        return ;
    }
};
