

/*Leetcode 118. Pascal's Triangle

You are here! 
Your runtime beats 8.70% of cpp submissions. 3 ms
My run time is within the majority. 

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> psc={1};
        if(numRows!=0) res.push_back(psc);
        else return res;
        
        if(numRows!=1){
            psc.push_back(1);
            res.push_back(psc);
        }else{
            return res;
        }

        for(int i=2; i!=numRows; i++){ //i is row number
            for(vector<int>::reverse_iterator it=psc.rbegin(); it!=--psc.rend(); )  *it = *it + *++it;
            psc.push_back(1);
            res.push_back(psc);
        }
        return res;
    }
};