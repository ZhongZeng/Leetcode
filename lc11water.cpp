
/*
Leetcode 11. Container With Most Water
You are here! 
Your runtime beats 94.55% of cpp submissions. 18 ms 

*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        /* this solution using two pointers is inspired by others' solution
        O(n)time, O(1) space    */
        vector<int>::iterator ib=height.begin(), ie=--height.end();
        int maxw=0, thisw, bar;
        while(ib<ie){
            // cout<<*ib<<" "<<*ie<<endl;
            thisw=(ie-ib)*min(*ie,*ib);
            if(maxw<thisw) {
                maxw=thisw;
                // cout<<maxw<<endl;
            }
            
            if(*ib<*ie){
                bar=*ib;
                while(*ib<=bar && ib<ie){
                    // cout<<"test1"<<endl;
                    ib++;
                }
            }else{
                bar=*ie;
                while(*ie<=bar && ib<ie){
                    // cout<<"test2"<<endl;
                    ie--;
                }
            }
        }
        
        return maxw;
    }
};

