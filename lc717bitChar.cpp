

/*
Leetcode 717. 1-bit and 2-bit Characters

Related Topics 
Array
Similar Questions 
Gray Code

Next challenges: Gray Code

Test Cases:
[1,0,0]
[1, 1, 1, 0]
[1,1,0,1,1,0]
[1,1,0,0,1,1,0]
[1,0,0,1,1,0]

Next challenges: Median of Two Sorted Arrays, Find K-th Smallest Pair Distance, My Calendar I

Runtime: 3 ms
Your runtime beats 62.85 % of cpp submissions.

*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // 0, 10, 11
        // The given string will always end with a zero. This makes sure the given string can alwasy be decoded. 
        // Given a vaild string, there is only one way to decode it. 
        // Return whether the last character must be a one-bit character or not.
        // DP; O(n) time; could avoid travsing all elements
        if(bits.size()<2)   return true;
        for(int i=bits.size()-2; -1<i; i--){
            if(bits[i]<1){// ==0 [0:i] is&must be a slice 
                return (bits.size()-i)%2!=1;// bits.size()-i-2 to be exact 
            }
        }
        return bits.size()%2!=0;
    }
};
