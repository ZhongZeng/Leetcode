
/*
Leetcode 777. Swap Adjacent in LR String

Companies   
Google 
Related Topics 
Brainteaser 

Test Cases:
"X"
"L"
"RXXLRXRXL"
"XRLXXRRLX"

Next challenges: Insert Interval, Design In-Memory File System, Champagne Tower

Runtime: 8 ms
Your runtime beats 98.71 % of cpp submissions.

*/

class Solution {
public:
    bool canTransform(string start, string end) {
        // the sequence of L and R can't be changed; L later in start, R first in start 
        // XL->LX, RX->XR, swap; L can move backward until not X, R can move foreward until not X 
        // O(n) time, O(1) space 
        if(start.size()!=end.size())    return false;
        int i, j, len=end.size();
        for( i=0, j=-1; i<len&&j<len; i++){// end.size() doesn't work 
            if(start[i]=='L'){
                while( ++j<len&&end[j]=='X' ){}
                if(end[j]!='L'||i<j)    return false;
            }else if(start[i]=='R'){
                while( ++j<len&&end[j]=='X' ){}
                if(end[j]!='R'||j<i)    return false;
            }
            //cout<<i<<","<<j<<" ";
        }
        
        if(i<len){
            while( ++i<len )    if(start[i]!='X')   return false;
        }else if(j<len){
            while( ++j<len )    if(end[j]!='X') return false;
        }
        
        return true;
    }
};
