
/*
Leetcode 889. Spiral Matrix III

Companies   
Dataminr
Related Topics 
Math 

Test Cases:
1
4
0
0

Runtime: 40 ms

*/

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        // O(n) time
        vector<int> vc={r0,c0};
        vector<vector<int>> rt;
        rt.push_back(vc);
        int pos, len=0, dc=0, sz=R*C, r=r0, c=c0;// dc:0E(len++),1S,2W(len++),3N 
        
        while( rt.size()<sz){
            //cout<<r<<","<<c<<":"<<rt.size()<<"; ";
            switch(dc){
                case 0:// E 
                    len++;
                    for( pos=0; pos<len; pos++){
                        c++;
                        if(-1<r&&r<R&&-1<c&&c<C){
                            vc[0]=r;
                            vc[1]=c;
                            rt.push_back(vc);
                        }
                    }
                    break;
                case 1:// S 
                    for( pos=0; pos<len; pos++){
                        r++;
                        if(-1<r&&r<R&&-1<c&&c<C){
                            vc[0]=r;
                            vc[1]=c;
                            rt.push_back(vc);
                        }
                    }
                    break;
                case 2:// W 
                    len++;
                    for( pos=0; pos<len; pos++){
                        c--;
                        if(-1<r&&r<R&&-1<c&&c<C){
                            vc[0]=r;
                            vc[1]=c;
                            rt.push_back(vc);
                        }
                    }
                    break;
                case 3:// N 
                    for( pos=0; pos<len; pos++){
                        r--;
                        if(-1<r&&r<R&&-1<c&&c<C){
                            vc[0]=r;
                            vc[1]=c;
                            rt.push_back(vc);
                        }
                    }
                    break;
            }
            if(dc!=3)   dc++;
            else    dc=0;
        }
        
        return rt;
    }
};
