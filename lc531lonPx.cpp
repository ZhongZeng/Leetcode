
/*
Leetcode 531. Lonely Pixel I

Companies 
Google 
Related Topics 
Array, Depth-first Search 

Next challenges: Subsets, Word Ladder II, Shortest Word Distance III

Test Cases:
[["W","W","B"],["W","B","W"],["B","W","W"]]
[["W","B","W"],["W","B","W"],["B","W","W"]]

Runtime: 72 ms
Your runtime beats 13.43 % of cpp submissions.

*/

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        // O(m*n) time; Array 
        if(picture.size()<1||picture[0].size()<1)   return 0;
        int i, j, k, rt=0;
        bool px;
        vector<bool> rows;
        for(i=0; i<picture.size(); i++){
            px=false;
            for(j=0; j<picture[0].size(); j++){
                if(picture[i][j]!='W'){//=='B'
                    if(px){
                        px=false;
                        break;
                    }else{
                        px=true;
                    }
                }
            }
            rows.push_back(px);
        }
        
        for(j=0; j<picture[0].size(); j++){
            px=false;
            for(i=0; i<picture.size(); i++){
                if(picture[i][j]!='W'){
                    if((!px)&&rows[i]){
                        px=true;
                    }else{
                        px=false;
                        break;
                    }
                }  
            }
            if(px)  rt++;
        }
        
        return rt;
    }
};