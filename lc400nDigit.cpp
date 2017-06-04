

/*

Leetcode 400. Nth Digit

Tag: Math
Next challenges: (M) Integer to Roman(M) Multiply Strings(M) Squirrel Simulation

You are here! 
Your runtime beats 9.59 % of cpp submissions.	 3 ms

Test Cases:
3
13
14
15
1000
1000000000

*/

class Solution {
public:
    int findNthDigit(int n1) {
        // if you use int instead of long, things go wrong at 1000000000
        long n=(long)n1;
        vector<long> v=numDigit(n);
        long num=v[0], sum=v[1], fstEle=v[2], target, dgt, rmd;
        // num (<12) - # of digit, sum-# numbers, fstEle-first element, target-target number, 
        // dgt-dgtth in target, rmd-reminder
        
        rmd=(n-sum)%num;
        if(rmd==0){
            dgt=1;
            target=fstEle+(n-sum)/num-1;
        }else{
            target=fstEle+(n-sum)/num;
            dgt=num+1-rmd;
        }
        
        //cout<<"num:"<<num<<" sum:"<<sum<<" fstEle:"<<fstEle<<" target:"<<target<<\
        //    " dgt:"<<dgt<<" rmd:"<<rmd<<endl;
        
        return nDigit(target, dgt);
    }
    
protected:
    vector<long> numDigit(long n){
        /* 
        # digits before/including (n+1)-digit number. 
        to-return value < 2^31 ~ 10^9*2 <10^12. 
        Derived from eleminating different terms:
		Term	1	2	3	...	n-1					n
		Sum		9	89	289	...	9*10^(n-2)*(n-1)	9*10^(n-1)*n
		10*Sum					9*10^(n-2)*(n-2)	9*10^(n-1)*(n-1)	9*10^n*n
		Sum-10*Sum=-9*Sum		9*10^(n-2)			9*10^(n-1)			-9*10^n*n
		=> Sum=n*10^n-(10^n-1)/9		
        */
        long num=1, m=10;
        while(num*m-(m-1)/9<n){
            num++;
            m=m*10;
        }
        num--;
        m=m/10;
        return {num+1, num*m-(m-1)/9, m}; // 
    }
    
    long nDigit(long target, long dgt){ // dgt-th digit of target
        while(--dgt!=0){
            target=target/10;
        }
        return target%10;
    }
    
};
