

/*
Leetcode 42. Trapping Rain Water

Related Topics 
ArrayTwo PointersStack
Similar Questions 
Container With Most Water, Product of Array Except Self, Trapping Rain Water II

Next challenges: Trapping Rain Water II

Test Cases:
[]
[2,1,1,1,3]
[3,1,1,0,1,2]
[0,1,0,2,1,0,1,3,2,1,2,1]

Runtime: 9 ms
Your runtime beats 49.53 % of cpp submissions.

*/

class Solution {
public:
    int trap(vector<int>& height) {
        return rain(height, 0, height.size());
    }
    
protected:
    int rain(vector<int>& height, int bg, int ed){ // [bg,ed)
        // stack, DP
        if(!(bg<ed-2))  return 0;
        
        int rn=0, lh=height[bg], ct; // rain water amount, last highest, this count
        stack<pair<int,int>> st;// height, length
        st.push(make_pair(height[bg],1));
        
        for(int i=bg+1; i!=ed; i++){
            if(lh<height[i]){
                while(!st.empty()){
                    rn+=(lh-st.top().first)*st.top().second;
                    st.pop();
                }
                st.push(make_pair(height[i],1));
                lh=height[i];
            }else{ // lh>=height[i]
                ct=1;
                while(st.top().first<height[i]){ // st is guranteed not to be empty
                    rn+=(height[i]-st.top().first)*st.top().second;
                    ct+=st.top().second;
                    st.pop();
                }
                if(height[i]<st.top().first)    st.push(make_pair(height[i],ct));
                else    st.top().second+=ct;
            }
            //cout<<rn<<" ";
        }
        
        return rn;
    }
    
};

