
/*

Leetcode 204. Count Primes

Related Topics 
Hash Table, Math 
Similar Questions 
Ugly Number, Ugly Number II, Perfect Squares 

Next challenges: Ugly Number IIPerfect Squares

Test Cases:
0
1
20
80

after improvement:
Runtime: 46 ms
You are here! 
Your runtime beats 35.04 % of cpp submissions.

before improvement:
Runtime: 82 ms
You are here! 
Your runtime beats 17.52 % of cpp submissions.
Runtime: 72 ms
You are here! 
Your runtime beats 18.92 % of cpp submissions.

*/

class Solution {
public:
    int countPrimes(int n) {
        // travse from 2 to n, delete the multiplier of each element
        vector<int> vc;
        int num=0;
        for(int i=1; i<n; i++) vc.push_back(i);
        for(int i=1; i<n/i+1; i++){// improved from i<n/2+1 after looking at discussion
            if( vc[i]!=0 ){
                for(int j=i*2+1; j<n; j+=i+1){
                    vc[j] = 0;                
                }
            }            
        }
        
        for(int i=1; i<vc.size(); i++ ){
            if(vc[i]!=0)    ++num;
        }
        return num;        
    }
};

