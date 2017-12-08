

/*
Leetcode 494. Target Sum

Related Topics 
Dynamic Programming, Depth-first Search 
Similar Questions 
Expression Add Operators 


Test Cases:
[1,1,1,1,1,2]
3
[1,1,1,1,1]
3
[3]
3

Runtime: 92 ms
Your runtime beats 54.06 % of cpp submissions.

*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size()<1)   return 0;
        
        unordered_map<int,int> um1,um2;
        if(nums[0]!=0){
            um1.emplace(nums[0],1);
            um1.emplace(-nums[0],1);
        }else{
            um1.emplace(0,2);
        }
        
        for(int i=1; i!=nums.size(); i++){  
            tra(um2,um1,nums[i]);
            if(++i==nums.size())  return findS(um2,S);
            
            tra(um1,um2,nums[i]);
        }
        
        return findS(um1,S);
    }
protected:
    int findS(unordered_map<int,int> & um1, int S){
        return um1.find(S)!=um1.end()?um1.find(S)->second:0;
    }
    
    void tra(unordered_map<int,int> & um1, unordered_map<int,int> & um2, int k){
        unordered_map<int,int>::iterator ui,fi;
        um1.clear();
        for(ui=um2.begin();ui!=um2.end();ui++){
            fi=um1.find(ui->first+k);
            //cout<<ui->first<<":+"<<k<<":";
            if(fi!=um1.end())   fi->second+=ui->second;
            else    um1.emplace(ui->first+k,ui->second);
            
            //cout<<ui->first<<":-"<<k<<":";
            fi=um1.find(ui->first-k);
            if(fi!=um1.end())   fi->second+=ui->second;
            else    um1.emplace(ui->first-k,ui->second);
        }        
        //cout<<endl;
    }
};
