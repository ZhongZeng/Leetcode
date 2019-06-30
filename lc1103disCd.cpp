/*
1103. Distribute Candies to People

Tags: Vector, Binary Search (suggested)

Test Cases:
7
4
10
3

Runtime: 0 ms
Memory Usage: 8.5 MB

Ranking of Weekly Contest 143  
Rank	Name	Score	Finish Time 	Q1 (4)	Q2 (4)	Q3 (6)	Q4 (6)
559 / 4272	zhongzeng 	14	1:19:38	 0:04:24	 0:37:18		 1:14:38  1
*/

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        // brute force
        vector<int> vc(num_people, 0);
        
        for( int i=0; 0<candies; i++){
            for( int j=0; j<vc.size(); j++){
                int t=i*num_people+j+1;
                if(t<candies){
                    vc[j]+=t;
                    candies-=t;
                }else{
                    vc[j]+=candies;
                    return vc;
                }
            }
        }
        
        return vc;
    }
};