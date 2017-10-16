
/*

Leetcode 554. Brick Wall

Related Topics 
Hash Table 

Next challenges: Max Points on a Line, Sparse Matrix Multiplication, Top K Frequent Words

Runtime: 39 ms
You are here! 
Your runtime beats 73.11 % of cpp submissions.

*/


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // Condition:The width sum of bricks in different rows are the same and won't exceed INT_MAX.
        int len, mx=0;
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator umi;
        for(int i=0; i!=wall.size(); i++){
            len=0;
            for(int j=0; j!=wall[i].size()-1; j++){// edges of wall don't count
                len+=wall[i][j];
                umi=um.find(len);
                if( umi!=um.end() ){
                    umi->second++;
                }else{
                    um.emplace(len, 1);
                }                
            }            
        }
        
        for( umi=um.begin(); umi!=um.end(); umi++ ){            
            //cout<<umi->first<<' '<<umi->second<<endl;
            mx = mx<umi->second ? umi->second : mx ;                                    
        }
        //cout<<mx<<endl;
        
        return wall.size()-mx;
    }
};
