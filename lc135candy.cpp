
/*
Leetcode 135. Candy

Related Topics 
Greedy

Next challenges: Jump Game II, Rearrange String k Distance Apart, 
Best Time to Buy and Sell Stock with Transaction Fee

Test Cases:
[1,2,2]
[1,2,3,4,5,2,1]
[5,4,3,2,6,7]

Runtime: 30 ms
Your runtime beats 26.36 % of cpp submissions.

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        // O(n) time, greedy
        if(ratings.size()<1)    return 0;
        if(ratings.size()<2)    return 1;
        
        int sum=0, i;
        vector<int> vc={1};
        
        for(i=1; i<ratings.size(); i++){
            if(ratings[i-1]<ratings[i]){
                vc.push_back(vc.back()+1);
            }else{
                vc.push_back(1);
            }
        }
        
        for(i=ratings.size()-2; -1<i; i--){
            if(ratings[i+1]<ratings[i]){
                vc[i]=vc[i]<vc[i+1]+1?vc[i+1]+1:vc[i];
            }
        }
        
        for(vector<int>::iterator it=vc.begin(); it!=vc.end(); it++){
            sum+=*it;
        }
        
        return sum;
    }
};
