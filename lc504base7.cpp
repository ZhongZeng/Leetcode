
/*
Leetcode 504. Base 7

Runtime: 6 ms
Your runtime beats 8.13 % of cpp submissions.

*/

class Solution {
public:
    string convertToBase7(int num) {
        string s;       
        int d;
        char c;
        bool b=false;
        if(num<0){
            num=-num;
            b=true;
        }else if(num==0){
            return "0";
        }
        while(num!=0){
            d=num/7;
            s.append(to_string(num-d*7));
            num=d;
        }
        if(b)   s.push_back('-');
        
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            c=s[i];
            s[i]=s[j];
            s[j]=c;
        }
        
        return s;
    }
};
