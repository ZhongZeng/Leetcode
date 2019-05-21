/*
1046. Last Stone Weight

Related Topic	Heap, Greedy 

Test Case:
[2,7,4,1,8,1]

Runtime: 4 ms
Memory Usage: 8.3 MB

Rank		Name		Score	Finish Time 	Q1 (3)	Q2 (4)		Q3 (6)	Q4 (6)
2386 / 4091	zhongzeng 	7		1:26:12	 		0:34:03	1:21:12  1	
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // stones.size() in [1,30]; O(n*n) time, O(n) space; heap can achieve O(n*log(n)) 
        sort(stones.begin(),stones.end());
        
        while(1<stones.size()){
            int s=stones.size(), t=stones[s-1]-stones[s-2];
            if(t<0) t=-t;
            stones.pop_back();
            stones.pop_back();
            if(t!=0){
                int i;
                for( i=stones.size()-1; -1<i; i--){
                    if(stones[i]<t){
                        stones.insert( stones.begin()+i+1, t);
                        break;
                    }
                }
                if(i==-1)   stones.insert( stones.begin(), t);
            }
            //for(auto e:stones)  cout<<e<<" ";   cout<<endl;
        }
        
        return stones.size()<1?0:stones[0];
    }
};