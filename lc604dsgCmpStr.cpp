
/*
Leetcode 604. Design Compressed String Iterator

Companies 
Google
Related Topics 
Design 
Similar Questions 
LRU Cache, String Compression

Next challenges: LRU Cache

Test Cases:
["StringIterator","next","next","next","hasNext","next","next","next","next","next","next","next","hasNext","next","next","next","next","next","hasNext","next","next","next","next","next","hasNext","next","next","next","next","hasNext","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","next","hasNext","next","hasNext","next","next","next","next","next","next","hasNext","next","next","next","next","next","next","next","next","next","next","next","next","next","next","hasNext","next","next","next","hasNext","next","next","hasNext","next","next","next","next","next"]
[["x6"],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]
["StringIterator","next","next","next","next","next","next","hasNext","next","hasNext"]
[["L1e2t1C1o1d1e1"],[],[],[],[],[],[],[],[],[]]
["StringIterator","hasNext"]
[[""],[]]

Runtime: 14 ms
Your runtime beats 33.51 % of cpp submissions.

*/

class StringIterator {
public:
    StringIterator(string compressedString) {
        i=0;
        r=0;
        s=compressedString; 
    }
    
    char next() {
        if(1<r--){// 1st time used in else
            return c;
        }else{
            if(s.size()-1<i)    return ' ';
            c=s[i];
            r=0;
            while(++i<s.size()&&isNum(s[i])){
                r=r*10+s[i]-'0';
            }
            return c;
        }
    }
    
    bool hasNext() {
        return 1<r||i<s.size();
    }
    
    int i, r;
    char c;
    string s;
    
    bool isNum(char ch){
        return (-1<ch-'0')&&(ch-'0'<10);
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

/*
// Runtime: 29 ms
// Your runtime beats 0.53 % of cpp submissions.
class StringIterator {
public:
    StringIterator(string compressedString) {
        i=0;
        r=0;
        s=compressedString; 
    }
    
    char next() {
        if(hasNext()){
            if(1<r--){// 1st time used in else
                return c;
            }else{
                c=s[i];
                r=0;
                while(++i<s.size()&&isNum(s[i])){
                    r=r*10+s[i]-'0';
                }
                return c;
            }            
        }else{
            return ' ';
        }
    }
    
    bool hasNext() {
        return 1<r||i<s.size();
    }
    
    int i, r;
    char c;
    string s;
    
    bool isNum(char ch){
        return (-1<ch-'0')&&(ch-'0'<10);
    }
};

*/