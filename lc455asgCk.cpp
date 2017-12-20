

/*

Leetcode 455. Assign Cookies


Related Topics 
Greedy

Next challenges: Wildcard Matching, Best Time to Buy and Sell Stock II, 4 Keys Keyboard

Test Cases:
[1,2,3]
[1,1]
[2,4,2,5,1,5,8,2,1]
[9,29,3,1,2,3,1]

Runtime: 39 ms
Your runtime beats 69.64 % of cpp submissions.

*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort, 2-pointer
        int sum=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        for(int i=0, j=0; i!=g.size()&&j!=s.size(); j++){
            if(s[j]<g[i]){
                
            }else{
                i++;
                sum++;
            }
        }
        
        return sum;
    }
};
