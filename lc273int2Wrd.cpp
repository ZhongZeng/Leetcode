
/*
Leetcode 273. Integer to English Words

Companies 
Facebook, Microsoft 
Related Topics 
Math, String 
Similar Questions 
Integer to Roman

Next challenges: Integer to Roman

Test Cases:
50868
0
100000
102
123
1000
10000
1000000
12345
123456
2147483647
111111

The implementation is not hard, but it's difficult to consider all cases. 

Runtime: 6 ms
Your runtime beats 1.88 % of cpp submissions. which is within majority 

*/ 

class Solution {
public:
    string numberToWords(int num) {
        // 2,147,483,647
        if(num==0)  return "Zero";
        string rt; 
        vector<int> vc;
        vector<string> one, ten, ele, hu;
        one={"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
        ten={"Invalid","Invalid","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
        ele={"Ten ", "Eleven ", "Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ", "Eighteen ","Nineteen "};
        hu={"","Thousand ","Million ","Billion "};
        
        for( ; num!=0; num=num/10)  vc.push_back(num%10);
        
        for(int i=vc.size()-1; -1<i; i--){
            switch(i%3){
                case 0: // largest digit only 
                    rt.append(one[vc[i]]);
                    rt.append(hu[i/3]);
                    break;
                case 1: 
                    if(vc[i]!=0){
                        if(vc[i]==1){
                            rt.append(ele[vc[--i]]);
                        }else{ // not 0,1 
                            rt.append(ten[vc[i]]); 
                            rt.append(one[vc[--i]]); 
                        }
                        rt.append(hu[i/3]);
                    }
                    break;
                case 2: 
                    if(vc[i]!=0){
                        rt.append(one[vc[i]]);
                        rt.append("Hundred ");
                    }else{// 000
                        if(vc[i-1]==0&&vc[i-2]==0)  i-=2;
                    }
                    break;
            }
        }
        
        rt.pop_back();
        return rt;
    }
};
