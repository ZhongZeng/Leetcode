/*
1296. Divide Array in Sets of K Consecutive Numbers

Companies: Google 
Related Topic:	Array, Greedy 

Test Cases:
[1,2,3]
3
[1,2,3,3,4,4,5,6]
4
[3,2,1,2,3,4,3,4,5,9,10,11]
3
[3,3,2,2,1,1]
3
[1,2,3,4]
3

Runtime: 116 ms	Your runtime beats 99.12 % of cpp submissions.
Memory Usage: 17.6 MB
*/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // greedy; O(n*log(n)) time, O(n) space 
        queue<pair<int,int>> qu;// 2 vectors also work
        
        sort(nums.begin(), nums.end());
        for( int i=0; i<nums.size(); i++){
            if(qu.empty()){
                qu.push(make_pair(nums[i], k-1));
            }else{
                pair<int,int> pr=qu.front();
                if(nums[i]==pr.first){
                    qu.push(make_pair(nums[i], k-1));
                }else if(nums[i]==pr.first+1){
                    qu.pop();
                    if(1<pr.second) qu.push(make_pair(nums[i], pr.second-1));
                }else{
                    return false;
                }
            }
        }
        
        return qu.empty();
    }
};