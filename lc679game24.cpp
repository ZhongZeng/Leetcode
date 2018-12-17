
/*
679. 24 Game

Related Topics: Depth-first Search 

Test Cases:
[3,3,8,8]
[2,2,6,5]
[3,4,6,7]
[4,1,8,7]
[1, 2, 1, 2]

Runtime: 8 ms, faster than 37.67% of C++ online submissions for 24 Game.

*/

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> vc;
        for( int i=0; i<nums.size(); i++)   vc.push_back(nums[i]);
        return dfs(vc);
    }
    
    bool dfs( vector<double> nums ){
        if(nums.size()==1)  return abs(nums[0]-24)<0.001;// 8/(3-8/3)
        
        for( int i=0; i<nums.size(); i++){
            //if(nums[i]==24) return true;// need to use all cards 
            for( int j=i+1; j<nums.size(); j++){
                vector<double> vc={0};
                for( int k=0; k<nums.size(); k++)
                    if(k!=i&&k!=j)  vc.push_back(nums[k]);
                vc[0]=nums[i]+nums[j];
                if(dfs(vc)) return true;
                vc[0]=nums[i]*nums[j];
                if(dfs(vc)) return true;
                vc[0]=nums[i]-nums[j];
                if(dfs(vc)) return true;
                vc[0]=nums[j]-nums[i];
                if(dfs(vc)) return true;
                if(nums[j]!=0){
                    vc[0]=nums[i]*1.0/nums[j];
                    if(dfs(vc)) return true;                    
                }
                if(nums[i]!=0){
                    vc[0]=nums[j]*1.0/nums[i];
                    if(dfs(vc)) return true;                    
                }
            }
        }
        
        return false;
    }
};
