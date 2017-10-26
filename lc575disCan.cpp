
/*
Leetcode 575. Distribute Candies

Related Topics 
Hash Table 

Next challenges: Valid Sudoku, Sudoku Solver, H-Index

Runtime: 352 ms
You are here! 
Your runtime beats 25.50 % of cpp submissions.

*/

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator umi;
        for(vector<int>::iterator it=candies.begin(); it!=candies.end(); it++){
            umi = um.find(*it);
            if( umi!=um.end() ){
                umi->second++;
                
            }else{
                um.emplace( *it, 1 );
                
            }
            
        }
                        
        return um.size() < candies.size()/2 ? um.size() : candies.size()/2 ;
    }
};
