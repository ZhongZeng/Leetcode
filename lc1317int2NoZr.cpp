/*
1317. Convert Integer to the Sum of Two No-Zero Integers

Ranking of Weekly Contest 171  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
3626 / 7189	zhongzeng 	7	1:30:00	 1:09:39  2	 1:20:00	

Company	HRT
Related Topics	Math

Test Cases:
2
11
10000
69
1010
1501
2218

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 8.3 MB
*/

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        // O(log(n)) time&space; 1 is invalid 
        int a=n/2, b=n-a;// b-a==0,1; ex. 9,10
        
        for( int i=1; (0<a/i)&&(0<b/i); i=i*10 ){// # digits of a and b a/t mutation diff at most 1
            if((a/i)%10==0){
                if((b/i)%10==9){
                    a+=i;
                    b-=i;
                }else{
                    a-=i;
                    b+=i;
                }
            }else if((b/i)%10==0){// a/i!=0
                if((a/i)%10==1){
                    a+=i;
                    b-=i;
                }else{
                    a-=i;
                    b+=i;
                }
            }
        }
        
        return {a,b};
    }
};
/*
vector<int> vn;
        int a=0, b=0;
        
        for( int m=0; 0<m; m=m/10)  vn.push_back(n%10);
        
        for( int i=vn.size()-1; -1>i; i--){
            int t=vn[i]+c;
            if(t==0||t==1){
                a=a*10;
                b=b*10;
                c=t+1;
            }else{// t=
                a=a*10+2;
                b=b*10+t-2;
                c=0;
            }
        }
        
        return {a, b};
*/