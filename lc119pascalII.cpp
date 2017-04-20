
/*Leetcode 119. Pascal's Triangle II

Similar Problem: (E) Pascal's Triangle
Next Challenges: 

I use the same code from 118 Pascal's Triangle in this solution. 
This is really no reason why I shouldn't. 

You are here! 
Your runtime beats 2.48% of cpp submissions. 3 ms
My run time is within the majority. 

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> psc={1};
        if(rowIndex!=0){
            psc.push_back(1);
        }else{
            return psc;
        }

        for(int i=1; i!=rowIndex; i++){ //i is row number
            for(vector<int>::reverse_iterator it=psc.rbegin(); it!=--psc.rend(); )  *it = *it + *++it;
            psc.push_back(1);
        }
        return psc;
    }
};
