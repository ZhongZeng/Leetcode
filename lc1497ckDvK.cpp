/*
1497. Check If Array Pairs Are Divisible by k

Medium
Companies	Quble
Related Topics	Array, Math, Greedy

Test Cases:
[1,2,3,4,5,10,6,7,8,9]
5
[1,2,3,4,5,6]
7
[1,2,3,4,5,6]
10
[-10,10]
2
[-1,1,-2,2,-3,3,-4,4]
3

Runtime: 316 ms
Memory Usage: 61.6 MB
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // O(n+k) time; O(k) space; k in [1,10**5]
        vector<int> vc(k,0);// remainder of k
        for( int i=0; i<arr.size(); i++){
            int r=arr[i]%k;
            vc[r<0?r+k:r]+=1;
        }
        
        if(vc[0]%2!=0)  return false;
        if(k%2==0&&vc[k/2]%2!=0)    return false;
        for( int i=1, j=vc.size()-1; i<j; i++, j--)
            if(vc[i]!=vc[j])    return false;
        return true;
    }
};