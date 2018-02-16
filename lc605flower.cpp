
/*
Leetcode 605. Can Place Flowers

Tag: Array

Next challenges: (H) Word Ladder II(M) 3Sum Smaller(M) Game of Life

You are here! 
Your runtime beats 36.92 % of cpp submissions.	19 ms

Test Cases:
[1,0,0,0,1,0,0]
2
[0,0,1,1]
1
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

*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c=0, t=1; 
		// c - total capacity, t - temporary zeros
		for(int i=0; i!=flowerbed.size(); i++){
			if( flowerbed[i] == 1 ){
				c += (t-1)/2; 
				t=0; 
			}else{ // flowerbed[i] == 0
				t++;
			}
			
		}
		c += t/2; 
		
		return n <= c;
    }
};

/*

//Runtime: 28 ms
//Your runtime beats 7.22 % of cpp submissions.

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
*/