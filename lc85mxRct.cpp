

/*
85. Maximal Rectangle

Related Topics 
Array, Hash Table, Dynamic Programming, Stack 
Similar Questions 
Largest Rectangle in Histogram, Maximal Square

Next challenges: Largest Divisible Subset, 
Sentence Screen Fitting, Longest Line of Consecutive One in Matrix

Test Case:
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]

Runtime: 25 ms
Your runtime beats 31.44 % of cpp submissions.

*/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // O(m*n) time; use the method from Max Rectangle in Histogram 
        if(matrix.size()<1||matrix[0].size()<1) return 0;
        int mx=0, len;
        vector<int> st, sl, vc(matrix[0].size(), 0);
        vector<vector<int>> mt(matrix.size(), vc);
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0]=='1')   mt[i][0]=1;
            for(int j=1; j<matrix[i].size(); j++){
                if(matrix[i][j]!='0')   mt[i][j]=mt[i][j-1]+1;
                //cout<<mt[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        for(int j=0; j<mt[0].size(); j++){
            st={mt[0][j]};
            sl={1};
            for(int i=1; i<mt.size(); i++){
                if(mt[i][j]<st.back()){
                    for(len=0; !st.empty()&&mt[i][j]<st.back(); st.pop_back(),sl.pop_back()){
                        len+=sl.back();
                        sl.back()=len;
                        mx=mx<st.back()*sl.back()?st.back()*sl.back():mx;
                    }
                    sl.push_back(len+1);
                }else{
                    sl.push_back(1);
                }
                st.push_back(mt[i][j]);
            }
            for(len=0; !st.empty(); st.pop_back(),sl.pop_back()){
                len+=sl.back();
                sl.back()=len;
                mx=mx<st.back()*sl.back()?st.back()*sl.back():mx;
            }             
        }
        
        return mx;
    }
};

/*
// Wrong Solution 
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int area=0,ca;
        vector<vector<char>> vc=matrix;
        
        // 1st row - matrix:horizontaly consecutive
        for(int j=1; j!=matrix[0].size(); j++){
            if(matrix[0][j]!='0')   matrix[0][j]=matrix[0][j-1]+1;
        }
        
        // 1st column - - vc:verticaly consecutive
        for(int i=1; i!=vc.size(); i++){
            if(vc[i][0]!='0')   vc[i][0]=vc[i-1][0]+1;
        }        
        
        for( int i=1; i!=matrix.size(); i++){
            for( int j=1; j!=matrix[0].size(); j++){
                if(matrix[i][j]!='0'){
                    matrix[i][j]=matrix[i-1][j]<matrix[i][j] ? matrix[i-1][j]:matrix[i][j];
                    matrix[i][j]=matrix[i][j-1]+1<matrix[i][j] ? matrix[i][j-1]+1:matrix[i][j];
                    matrix[i][j]=matrix[i-1][j-1]+1<matrix[i][j] ? matrix[i-1][j-1]+1:matrix[i][j];
                    vc[i][j]=vc[i-1][j]+1<vc[i][j] ? vc[i-1][j]+1:vc[i][j];
                    vc[i][j]=vc[i][j-1]<vc[i][j] ? vc[i][j-1]:vc[i][j];
                    vc[i][j]=vc[i-1][j-1]+1<vc[i][j] ? vc[i-1][j-1]+1:vc[i][j];       
                    ca=(matrix[i][j]-'0')*(vc[i][j]-'0');
                    area=area<ca ? ca:area;
                }
            }
        }
                
        return area;
    }
};
*/