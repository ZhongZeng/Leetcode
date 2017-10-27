
/*
Leetcode 461. Hamming Distance

Related Topics 
Bit Manipulation 
Similar Questions 
Number of 1 Bits, Total Hamming Distance 

Next challenges: Number of 1 Bits, Total Hamming Distance

Runtime: 3 ms
You are here! 
Your runtime beats 26.72 % of cpp submissions.

*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y, sum=0;
        
        while( z!=0 ){
            sum += z-(z>>1<<1);
            //cout<<sum<<endl;
            z = z>>1;
        }
        
        return sum ;
    }
};