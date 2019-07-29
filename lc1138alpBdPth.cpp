/*
1138. Alphabet Board Path

Test Cases:
"leet"
"code"
"zb"

Runtime: 4 ms
Memory Usage: 8.4 MB
*/

class Solution {
public:
    string alphabetBoardPath(string target) {
        // O(n) time, n=length of returned value; corner case 'z'
        string rt;
        if(target.size()<1) return rt;
        
        findNextLetter( rt, 'a', target[0]);
        for( int i=1; i<target.size(); i++) findNextLetter( rt, target[i-1], target[i]);
        
        return rt;
    }

protected:
    void findNextLetter(string& rt, char a, char b){
        int x=(a-'a')%5-(b-'a')%5, y=(a-'a')/5-(b-'a')/5;
        if(a=='z'){// corner case 'z', move out of board
            findY( rt, y);
            findX( rt, x);
        }else{
            findX( rt, x);
            findY( rt, y);
        }
        rt.push_back('!');
        return ;
    }
    
    void findX(string& rt, int x){
        if(0<x){
            for( int i=0; i<x; i++) rt.push_back('L');
        }else{
            for( int i=0; i>x; i--) rt.push_back('R');
        }
        return ;
    }
        
    void findY(string& rt, int y){
        if(0<y){
            for( int i=0; i<y; i++) rt.push_back('U');
        }else{
            for( int i=0; i>y; i--) rt.push_back('D');
        }
        return ;
    }
};