

/*
Leetcode 605. Can Place Flowers

Related Topics 
Array
Similar Questions 
Teemo Attacking, Asteroid Collision

Next challenges: Largest Rectangle in Histogram, 
Best Time to Buy and Sell Stock II, Lonely Pixel II

Test Cases:
[1,0,0,0,1]
1
[1,0,0,0,1]
2
[0,0,1,0,1]
1
[0]
1
[1]
0
[0,0,0]
2


Runtime: 28 ms
Your runtime beats 7.22 % of cpp submissions.

*/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // be careful with the first and last
        int c=0, mx=0, i;
        for(i=0; i!=flowerbed.size(); i++){
            if(flowerbed[i]!=1){
                c++;
            }else{
                mx+=c/2;
                c=0;
                break;
            }
        }
        if(c!=flowerbed.size()){
            for( ; i!=flowerbed.size(); i++){
                if(flowerbed[i]!=1){
                    c++;
                }else{
                    mx+=(c-1)/2;
                    c=0;
                }
            }
            mx+=c/2;            
        }else{
            mx=(c+1)/2;
        }
        
        return mx<n?false:true;
    }
};
