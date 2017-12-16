
/*

Leetcode 740. Delete and Earn

Related Topics 
Dynamic Programming
Similar Questions 
House Robber

Next challenges: Split Array Largest Sum, 
Can I Win, Longest Palindromic Subsequence

Test Cases:
[3,4,2]
[2, 2, 3, 3, 3, 4]

Runtime: 6 ms
Sorry. We do not have enough accepted submissions to show runtime distribution chart.

*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // DP, O(n*lg(n)) time
        // greedy: delete the largest first (define largest as can earn most points)
        // Each element nums[i] is an integer in the range [1, 10000]; count sort
        if(nums.size()<1)   return 0;
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> vc;// value, # occurance
        vc.push_back(make_pair(nums[0],1));
        for(int i=1; i!=nums.size(); i++){
            if(nums[i]!=nums[i-1])  vc.push_back(make_pair(nums[i],1));
            else    vc.back().second+=1;            
        }

        int mt=vc[0].first*vc[0].second, ml=0, t;
        for(int i=1; i!=vc.size(); i++){
            if(vc[i].first!=vc[i-1].first+1){
                ml=mt;
                mt=mt+vc[i].first*vc[i].second;
            }else{
                t=ml+vc[i].first*vc[i].second;
                ml=mt;
                mt=t<mt?mt:t;
            }   
            //cout<<ml<<" "<<mt<<endl;
        }
        
        return mt;
    }
};
