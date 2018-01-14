

/*

Leetcode 764. Largest Plus Sign

Weekly Contest 67

Test Cases: 
5
[[4,2]]
2
[]
1
[[0,0]]

*/

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        // O(N*N) time&space
        int am=0, cm;
        vector<int> vc(N,1);
        vector<vector<int>> mt(N,vc);
        for(int i=0; i<mines.size(); i++){
            mt[mines[i][0]][mines[i][1]]=0;
        }
        
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                if(mt[r][c]!=0){
                    cm=1;
                    for(int i=1; -1<r-i&&r+i<N&&-1<c-i&&c+i<N; i++){
                        if(mt[r+i][c]!=1||mt[r-i][c]!=1||mt[r][c+i]!=1||mt[r][c-i]!=1){
                            break;
                        }else{
                            cm++;
                        }
                    }
                    // if(am<cm)   cout<<r<<","<<c<<":"<<cm<<" ";
                    am=am<cm?cm:am;                   
                }
            }
        }
        
        return am;
    }
};
