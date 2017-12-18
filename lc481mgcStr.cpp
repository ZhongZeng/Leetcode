
/*
Leetcode 481. Magical String

Next challenges: Copy List with Random Pointer, 
Second Minimum Node In a Binary Tree, Partition to K Equal Sum Subsets

Test Cases:
1
6
8
100
101
102


Runtime: 9 ms
Your runtime beats 17.60 % of cpp submissions. 

*/

class Solution {
public:
    int magicalString(int n) {
        switch(n){
            case 0: return 0;
            case 1: return 1;
        }
        
        vector<int> vc={1,2,2};
        int sum=0, i=2, c=1;
        while( vc.size()<n ){
            if(c!=2){
                if(vc[i]!=2){
                    vc.push_back(1);
                }else{
                    vc.push_back(1);
                    vc.push_back(1);
                }                
                c=2;
            }else{
                if(vc[i]!=2){
                    vc.push_back(2);
                }else{
                    vc.push_back(2);
                    vc.push_back(2);
                }                
                c=1;
            }
            i++;
        }
        
        for(int j=0; j<i; j+=2)    sum+=vc[j];
        
        if(n<vc.size()&&vc.back()!=2)   sum--;
        
        return sum;
    }
};
