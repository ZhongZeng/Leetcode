/*
1415. The k-th Lexicographical String of All Happy Strings of Length n

Companies	Microsoft
Related Topics	Backtracking

Test Cases:
1
3
7
64
1
4
3
9
10
100

Runtime: 0 ms, faster than 100.00% of C++ online submissions for The k-th Lexicographical String of All Happy Strings of Length n.
Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for The k-th Lexicographical String of All Happy Strings of Length n.
Next challenges: Word Search II, Stickers to Spell Word, Number of Squareful Arrays

https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/discuss/594658/C%2B%2B-O(n)-Space-and-Time-Beats-100
*/

class Solution {
public:
    string getHappyString(int n, int k) {
        int rank=pow(2,n-1);
        string str;
        if(rank*3<k){
            return str;
        }else if(rank*2<k){
            k-=rank*2;
            str.push_back('c');
        }else if(rank<k){
            k-=rank;
            str.push_back('b');
        }else{
            str.push_back('a');
        }
        rank=rank>>1;
        // str.push_back((char)('a'+(k-1)/rank));
        // k=(k%rank!=0)?(k%rank):rank; rank=rank>>1;
        
        for( int i=0; i<n-1; i++, rank=rank>>1){// equivalent to 1<rank
            if(rank<k){
                k-=rank;
                str.push_back(getChar(str,true));
            }else{
                str.push_back(getChar(str,false));
            }
        }
        
        return str;
    }
    
protected:
    char getChar(string & str, bool greatThan){
        switch(str.back()){
            case 'a':
                return greatThan?'c':'b';
                break;
            case 'b':
                return greatThan?'c':'a';
                break;
            case 'c':
                return greatThan?'b':'a';
                break;
        }
        return ' ';
    }
};