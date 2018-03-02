
/*
Leetcode 640. Solve the Equation

Companies 
Amazon
Related Topics 
String, Math 
Similar Questions 
Fraction Addition and Subtraction

Next challenges: Basic Calculator, Smallest Good Base, Super Washing Machines 

Test Cases:
"x+5-3+x=6+x-2"
"x=x"
"2x=x"
"2x+3x-6x=x+2"
"x=x+2"

Runtime: 2 ms
Your runtime beats 66.92 % of cpp submissions.

*/

class Solution {
public:
    string solveEquation(string equation) {
        // 1 unknown, 1 time; '+','-','=','x',#
        int i, x1=0, num1=0, x2=0, num2=0, sg=1;
        string rt="x=";
        
        for(i=0; equation[i]!='='; i++){
            if(isNum(equation[i]))  fdNum(equation, i, x1, num1, sg);
            else if(equation[i]=='x')   x1+=sg;
            else if(equation[i]=='+')   sg=1;
            else if(equation[i]=='-')   sg=-1;
        }
        
        for( sg=1; ++i<equation.size(); ){
            if(isNum(equation[i]))  fdNum(equation, i, x2, num2, sg);
            else if(equation[i]=='x')   x2+=sg;
            else if(equation[i]=='+')   sg=1;
            else if(equation[i]=='-')   sg=-1;
        }
        
        //cout<<x1<<" "<<num1<<" "<<x2<<" "<<num2<<endl;
        x1-=x2;
        num2-=num1;
        if(x1!=0){
            rt.append(to_string(num2/x1));
            return rt;
        }else{
            return num2!=0?"No solution":"Infinite solutions";
        }
    }
    
protected:     
    void fdNum(string& equation, int& i, int& x, int& num, int& sg){
        int t=0;
        for( ; i<equation.size()&&isNum(equation[i]); i++)   t=t*10+equation[i]-'0';
        
        if(equation[i]=='x'){
            x+=t*sg;
        }else{
            num+=t*sg;
            i--;
        }    
        
        return ;
    }
    
    bool isNum(char c){
        return -1<c-'0'&&c-'0'<10;
    }
};
