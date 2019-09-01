/*
Ranking of Weekly Contest 152  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
452 / 5331	zhongzeng 	12	1:00:58	 0:17:21	 0:29:44  1	 0:55:58	

1175. Prime Arrangements

Companies	Amazon
Related Topics	Math

Test Cases:
5
100

Runtime: 4 ms
Memory Usage: 8.3 MB
*/

class Solution {
public:
    int numPrimeArrangements(int n) {
        // O(n**1.5) time; permuation; n in [1,100] 
        int p=0;
        long ans=1;
        for( int i=2; i<=n; i++)    p+=isPrime(i)?1:0;
        for( int i=p; 1<i; i--) ans=ans*i%1000000007;
        for( int i=n-p; 1<i; i--)   ans=ans*i%1000000007;
        return ans;
    }
    
protected:
    bool isPrime( int num){
        for( int i=sqrt(num); 1<i; i--)
            if(num%i==0)    return false;
        return true;
    }
};