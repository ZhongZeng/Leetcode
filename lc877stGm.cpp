
/*
877. Stone Game

Companies  

Related Topics 
Math, Dynamic Programming 

Test Case:
[5,3,4,5]

Runtime: 4 ms 

*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // DP, O(n*n) time&space
        vector<int> vc(piles.size()+1,0);
        vector<vector<int>> vv(piles.size(),vc);// Alex's score when piel is [row:begin,col:end) 
        
        int sum=0, win, s1, s2;
        for( int i=0; i<piles.size(); i++)  sum+=piles[i];
        win=sum/2;
        
        for( int j=piles.size()-1; -1<j; j--){// i=0, [0,j) 
            if(j%2!=0)  vv[0][j]=vv[0][j+1]+piles[j];// Alex's turn drawing pile[j] 
            else    vv[0][j]=vv[0][j+1];// Lee's turn drawing pile[j] 
        }
        
        for( int i=1; i<piles.size(); i++){// j=piles.size(), [i,piles.size())
            if(i%2!=0)  vv[i][piles.size()]=vv[i-1][piles.size()]+piles[i-1];// Alex's turn drawing pile[j] 
            else    vv[i][piles.size()]=vv[i-1][piles.size()];// Lee's turn drawing pile[j]             
        }
        
        for( int i=1; i<piles.size(); i++){
            
            for( int j=piles.size(); i<=j; j--){// [i,j) from [i-1,j) or [i,j+1) 
                if((j-i)%2!=0){// Alex's turn 
                    s1=vv[i-1][j]+piles[i];
                    s2=vv[i][j+1]+piles[j];                    
                    vv[i][j]=s1<s2?s2:s1;
                }else{// Lee's turn 
                    s1=vv[i-1][j];
                    s2=vv[i][j+1];
                    vv[i][j]=s1<s2?s2:s1;
                }
            }
        }
        
        //for(auto e:vv){   for(auto f:e)   cout<<f<<" ";   cout<<endl;}
        
        for( int i=0; i<piles.size(); i++){
            if(win<vv[i][i])    return true;
        }
        
        return false;
    }
};
