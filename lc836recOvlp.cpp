
/*
Leetcode 836. Rectangle Overlap


Test Cases:
[0,0,2,2]
[1,1,3,3]
[0,0,1,1]
[1,0,2,1]
[7,8,13,15]
[10,8,12,20]
[4,4,14,7]
[4,3,8,8]

Runtime: 4 ms

*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // [x1, y1, x2, y2]
        // any of vertex in rec1 is in rec2 
        int x1, x2, y1, y2, x3, x4, y3, y4;

        rec(x1, x2, y1, y2, rec1);
        rec(x3, x4, y3, y4, rec2);
        //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
        //cout<<x3<<" "<<x4<<" "<<y3<<" "<<y4<<endl;
        
        if((x1<x3&&x3<x2)||(x1<x4&&x4<x2)||(x3<x1&&x1<x4)||(x3<x2&&x2<x4)||x1==x3||x2==x4){
            if((y1<y3&&y3<y2)||(y1<y4&&y4<y2)||(y3<y1&&y1<y4)||(y3<y2&&y2<y4)||y1==y3||y2==y4)  return true;
        }
        
        return false;
    }
    
    void rec(int& x1, int& x2, int& y1, int& y2, vector<int>& rec1){
        if(rec1[0]<rec1[2]){
            x1=rec1[0];
            x2=rec1[2];
        }else{
            x1=rec1[2];
            x2=rec1[0];
        }
        
        if(rec1[1]<rec1[3]){
            y1=rec1[1];
            y2=rec1[3];
        }else{
            y1=rec1[1];
            y2=rec1[3];
        }        
        return ;
    }
};
