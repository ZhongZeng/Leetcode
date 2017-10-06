
/*
Leetcode 202. Happy Number

Related Topics 
Hash Table Math 
Similar Questions 
Add Digits Ugly Number 

Next challenges: Logger Rate Limiter, Longest Harmonious Subsequence, Smallest Range

Runtime: 3 ms
You are here! 
Your runtime beats 9.64 % of cpp submissions.

*/


class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        unordered_set<int>::iterator usi;
        while( n!=1 ){            
            usi = us.find(n);            
            if( usi!=us.end() ){
                return false;
            }else{
                us.emplace(n);
            }            
            n = nextNum(n);            
        }
        return true;        
    }
    
    int nextNum(int n){
        int sum=0, r;
        while( n!=0 ){
            r = n%10;
            sum += r*r ;
            n = n/10;            
        }
        return sum;
    }
    
};
