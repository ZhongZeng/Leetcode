/*
1375. Bulb Switcher IIIs

Companies	Microsoft
Related Topics	Array
Similar Questions	
Bulb Switcher, Bulb Switcher II 

Test Cases:
[2,1,3,5,4]
[3,2,4,1,5]
[4,1,2,3]
[2,1,4,3,6,5]
[1,2,3,4,5,6]

Runtime: 256 ms
Memory Usage: 35.9 MB

https://leetcode.com/problems/bulb-switcher-iii/discuss/532757/on-time-compare-maxright-most-light-with-number-of-turned-on-lights
*/

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        // O(k) time, can reduce to O(n) space by using vec; off-0, on-1, blue-2; return # of 1==# of 2 
        int max=0, sum=0;// max: largest/right-most light
        unordered_set<int> us;// # of unique lights
        
        for( int i=0; i<light.size(); i++){
            unordered_set<int>::iterator usi=us.find(light[i]);
            if(usi==us.end())   us.emplace(light[i]);
            if(max<light[i])    max=light[i];
            
            if(max==us.size())  sum++;
        }
        
        return sum;
    }
};
/*
This solution can be optimized to O(1) space, if we assume there is no duplicates in the vector light. In that case, we use index of element in light instead hash table to count the number of turned-on light.

Runtime: 80 ms, faster than 38.46% of C++ online submissions for Bulb Switcher III.
Memory Usage: 13.3 MB, less than 100.00% of C++ online submissions for Bulb Switcher III.

Next challenges:
Word Ladder II, Sort the Matrix Diagonally, 
The K Weakest Rows in a Matrix
*/
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        // O(n) time, O(1) space; assuming no duplicates in vec light 
        int max=0, sum=0;// max: largest/right-most light
        
        for( int i=0; i<light.size(); i++){
            if(max<light[i])    max=light[i];
            if(max-1==i)	sum++;
        }
        
        return sum;
    }
};