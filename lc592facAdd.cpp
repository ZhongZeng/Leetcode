

/*

Leetcode 592. Fraction Addition and Subtraction

Related Topics 
Math
Similar Questions 
Solve the Equation

Next challenges: Solve the Equation

Test Cases:
"3/8-3/6"
"3/8+1/6"
"3/8-1/6"
"-3/8-1/6"
"+3/8-1/6"

Runtime: 3 ms
Your runtime beats 15.42 % of cpp submissions.

*/


class Solution {
public:
    string fractionAddition(string expression) {
        // The input string only contains '0' to '9', '/', '+' and '-'. 
        // the numerator and denominator of each fraction will always be in the range [1,10]
        // the least common divisor of 1 thru 10 is 25200=5*7*8*9*10
        
        vector<int> vn, vd;
        int sum=0, i=-1, p=1, num=0;
        if(expression[0]=='+'||expression[0]=='-'){
            i=0;
        }else{
            while(expression[++i]!='/')
                num=num*10+expression[i]-'0';
            vn.push_back(num*p);
            
            num=0;
            while(++i<expression.size()&&expression[i]!='+'&&expression[i]!='-')
                num=num*10+expression[i]-'0';
            vd.push_back(num);            
        }
        
        while( i!=expression.size()){
            num=0;
            if(expression[i]!='-')  p=1;
            else    p=-1;
            while(expression[++i]!='/')
                num=num*10+expression[i]-'0';
            vn.push_back(num*p);
            
            num=0;
            while(++i<expression.size()&&expression[i]!='+'&&expression[i]!='-')
                num=num*10+expression[i]-'0';
            vd.push_back(num);
        }
        //for(auto ele:vn)    cout<<ele<<" "; cout<<endl;
        //for(auto ele:vd)    cout<<ele<<" "; cout<<endl;
        
        for(int i=0; i<vn.size(); i++)
            sum+=vn[i]*25200/vd[i];
        
        return reduced(sum);
    }

protected:
    string reduced(int sum){
        // 2, 3, 5, 7
        int p=1;
        if(sum==0){
            return "0/1";
        }else if(sum<0){
            p=-1;
            sum=0-sum;
        }
        
        int d=25200;
        char c;
        string s;
        vector<int> vc={2,3,5,7};
        for(vector<int>::iterator it=vc.begin(); it!=vc.end(); it++){
            while(sum%*it==0&&d%*it==0){
                sum/=*it;
                d/=*it;
            }            
        }
        
        // push_back digits
        while(d!=0){
            s.push_back((char)(d%10+'0'));
            d/=10;
        }
        s.push_back('/');
        while(sum!=0){
            s.push_back((char)(sum%10+'0'));
            sum/=10;
        }        
        if(p!=1)    s.push_back('-');
        
        // reverse string
        for(int i=0, j=s.size()-1; i<j; i++, j--){
            c=s[i];
            s[i]=s[j];
            s[j]=c;
        }
        
        return s;
    }
    
};