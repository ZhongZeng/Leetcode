/*
1079. Letter Tile Possibilities

Companies	Google
Related Topics	Backtracking

Test Cases:
"AAB"
"AAABBC"

Runtime: 120 ms	Your runtime beats 20.09 % of cpp submissions.
Memory Usage: 41.8 MB

*/

class Solution {
public:
    int numTilePossibilities(string tiles) {
        // DFS; title.size() in [1,7] 
        int sum=0;
        unordered_map<char,int> um;
        for( int i=0; i<tiles.size(); i++){
            unordered_map<char,int>::iterator umi=um.find(tiles[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(tiles[i], 1);
        }
        dfs( um, tiles.size(), sum);
        return sum-1;// minus ""
    }

protected:
    void dfs( unordered_map<char,int> um, int t, int& sum){
        sum++;
        if(t==0) return ;
        for( unordered_map<char,int>::iterator umi=um.begin(); umi!=um.end(); umi++){
            if(0<umi->second){
                umi->second-=1;
                dfs( um, t-1, sum);
                umi->second+=1;
            }
        }
        return ;
    }
};