

/*
Leetcode 738. Monotone Increasing Digits

Related Topics 
Greedy
Similar Questions 
Remove K Digits

Next challenges: Best Time to Buy and Sell Stock II, 
4 Keys Keyboard, Best Time to Buy and Sell Stock with Transaction Fee

Test Cases:
10
432
234
12677632

Runtime: 6 ms

*/

class Solution {
public:
    int monotoneIncreasingDigits(int N){
        int num=0;
        bool ne=false;
        vector<int> vc, rt;
        while(N!=0){
            vc.push_back(N%10);
            N=N/10;
        }
        //for(auto ele:vc)    cout<<ele<<" "; cout<<endl;
        
        // perform greedy
        rt.push_back(vc[0]);
        for(int i=1; i<vc.size(); i++){
            if(rt[i-1]<vc[i]){
                rt[i-1]=9;
                rt.push_back(vc[i]-1);                
            }else{
                rt.push_back(vc[i]);
            }
        }
        //for(auto ele:rt)    cout<<ele<<" ";
        
        // change to 9s and convert vector to int
        for(int i=rt.size()-1; -1<i; i--){
            if(ne){
                num=num*10+9;
            }else{
                num=num*10+rt[i];
                if(rt[i]==9)    ne=true;
            }
        }
        
        return num;
    }
};
