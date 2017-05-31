
/*
Leetcode 75. Sort Colors

You are here! 
Your runtime beats 1.58 % of cpp submissions.	6 ms
Your runtime beats 21.45 % of cpp submissions.	3 ms

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            if(*it==0){
                a++;
            }else if(*it==1){
                b++;
            }
        }
        c=nums.size()-a-b;
        
        for(int i=0; i!=a; i++){
            nums[i]=0;
        }
        for(int i=a; i!=a+b; i++){
            nums[i]=1;
        }
        for(int i=a+b; i!=nums.size(); i++){
            nums[i]=2;
        }
        
        
        /*vector<int>::iterator it1=nums.begin(),it=--nums.end();
        while(it1!=it2){
            if()
            
        }*/
        
        
    }
};
