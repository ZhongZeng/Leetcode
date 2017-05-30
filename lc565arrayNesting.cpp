

/*
Leetcode 565. Arrat Nesting

Tag: Array
Similar Problems:  (E) Nested List Weight Sum (M) Flatten Nested List Iterator (M) Nested List Weight Sum II
Next challenges: (E) Nested List Weight Sum(M) Flatten Nested List Iterator(M) Nested List Weight Sum II

You are here! 
Your runtime beats 31.73 % of cpp submissions.
Runtime: 59 ms

*/


class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        // inspired by others' DFS solution
        // we can prove that each element points to an unique position
        // if you want to reach an element, you need to reach all its previous elements
        vector<int> lab(nums.size(), 0);//1-visited,0-unvisited
        int lenm=0, len, j;
        for(int i=0; i!=nums.size(); i++){
            if(lab[i]==0){
                j=i;
                len=0;
                while(lab[j]==0){
                    lab[j]=1;
                    j=nums[j];
                    len++;
                }
                lenm = lenm<len ? len :lenm;
            }
            
        }
        
        return lenm;
    }
};


