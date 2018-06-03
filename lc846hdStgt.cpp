
/*
Leetcode 846. Hand of Straights

Test Cases:
[1,2,3,6,2,3,4,7,8]
3
[1,2,3,4,5]
4

Runtime: 71 ms

*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        // greedy; O(n*log(n)) time 
        int t;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi;
        
        for(int i=0; i<hand.size(); i++){// record occurance
            umi=um.find(hand[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(hand[i],1);
        }
        
        sort(hand.begin(), hand.end());
        
        for(int i=0; i<hand.size(); i++){
            umi=um.find(hand[i]);
            if(0<umi->second){
                t=umi->second;
                umi->second=0;
                for(int j=1; j<W; j++){
                    umi=um.find(hand[i]+j);
                    if(umi!=um.end()){
                        if(umi->second<t)   return false;
                        else    umi->second-=t;
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};