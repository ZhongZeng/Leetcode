/*
1052. Grumpy Bookstore Owner

Companies	Nutanix 
Related Topics	Array, Sliding Window

Test Cases:
[4,10,10]
[1,1,0]
2
[1,0,1,2,1,1,7,5]
[0,1,0,1,0,1,0,1]
3
[1]
[0]
1

Next challenges: Lonely Pixel II, Maximum Average Subarray II, Sum of Subarray Minimums

Runtime: 40 ms	Your runtime beats 60.29 % of cpp submissions.
Memory Usage: 11.4 MB	
*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        // O(n) time, queue 
        int mx=0, cr=0;
        for( int i=0; i<X; i++) cr+=customers[i];
        for( int i=X; i<customers.size(); i++)  cr+=grumpy[i]==0?customers[i]:0;
        mx=cr;// 1st X minutes not grumpy 
        
        for( int i=X; i<customers.size(); i++){// sliding window 
            if(grumpy[i]==1)    cr+=customers[i];
            if(grumpy[i-X]==1)  cr-=customers[i-X];
            mx=mx<cr?cr:mx;
        }
        
        return mx;
    }
};