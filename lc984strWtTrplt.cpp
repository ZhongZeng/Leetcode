/*
Leetcode 984. String Without AAA or BBB

Related Topic: Greedy 

Test Cases:
1
2
4
1

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

If there will be more 'a', we append "aab". If there will be more 'b', we append "bba". If there will be equal numbers of 'a' and 'b', we append "ab". Since we reduce the difference between the numbers of 'a' and 'b' by at most 1 in each iteration, "bba" ("aab") is guranteed not to be followed by "aab"("bba"). 

*/

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        // S exits guranteed 
        string rt;
        
        while( 0<A||0<B ){
            if(A<B){
                if(0<B--)   rt.push_back('b');
                if(0<B--)   rt.push_back('b');
                if(0<A--)   rt.push_back('a');                    
            }else if(B<A){
                if(0<A--)   rt.push_back('a');
                if(0<A--)   rt.push_back('a');
                if(0<B--)   rt.push_back('b');
            }else{
                if(0<A--)   rt.push_back('a');
                if(0<B--)   rt.push_back('b');                
            }
        }
        
        return rt;
    }
};