
/*
Leetcode 84. Largest Rectangle in Histogram

Test Cases:
[2,1,5,6,2,3]
[1,2,4,6,7,9]
[9,5,3,2,1]
[]

Related Topics 
Array, Stack 
Similar Questions 
Maximal Rectangle

Runtime: 12 ms
Your runtime beats 48.24 % of cpp submissions.

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // monocity case->forward&backward won't help inverse V shape->ascending?descending stack 
        // similar to Trapping Rain Water 
        // O(n) time
        if(heights.size()<1)    return 0;
        int mx=0, len;
        vector<int> st={heights[0]},sl={1};// st:ascending vector of heights; sl:length of heights
        
        for(int i=1; i<heights.size(); i++){
            if(heights[i]<st.back()){ // pop until equal||smaller              
                for( len=0; !st.empty()&&heights[i]<st.back(); st.pop_back(),sl.pop_back()){
                    len+=sl.back();
                    sl.back()=len;                    
                    mx=mx<st.back()*sl.back()?st.back()*sl.back():mx;
                }
                st.push_back(heights[i]);
                sl.push_back(len+1);//len+this heights[i]
            }else{ // push
                st.push_back(heights[i]);
                sl.push_back(1);
            }
        }
        
        for( len=0; !st.empty(); st.pop_back(),sl.pop_back()){
            len+=sl.back();
            sl.back()=len;                    
            mx=mx<st.back()*sl.back()?st.back()*sl.back():mx;
        }
        
        return mx;
    }
};

/*
// Submission Result: Time Limit Exceeded
// 95 / 96 test cases passed.
// Last executed input:
// [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,...

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		// O(n^2) time
        if( heights.size()<1 )  return 0;
        int mh, ma=0, ca; // min height, max area, current area
        for(int i=0; i!=heights.size(); i++){
            mh = heights[i] ;
            for(int j=i; j!=heights.size(); j++){
                if( heights[j]<mh ){
                    mh = heights[j] ;
                }
                ca = (j-i+1)*mh ;
                if( ma<ca ){
                    ma = ca ;
                }
            }            
        }        
        return ma;
    }
};

*/


