

/*
Leetcode 521. Longest Uncommon Subsequence I

Related Topics 
String
Similar Questions 
Longest Uncommon Subsequence II

I looked at the discussion before attempting. 
This is a joke. 

Next challenges: Longest Uncommon Subsequence II

Test Cases:
"aba"
"cdc"
"abacdc"
"cdc"
"cdcabc"
"cdc"
"cdcd"
"cdc"

Runtime: 3 ms
Your runtime beats 1.92 % of cpp submissions.

*/

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size()<b.size()){
            return b.size();
        }else if(b.size()<a.size()){
            return a.size();
        }else{
            for(int i=0; i!=a.size(); i++){
                if(a[i]!=b[i]){
                    return a.size();
                }
            }
            return -1;
        }
    }
};

/*
// Runtime: 3 ms
// Your runtime beats 1.92 % of cpp submissions.
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)    return -1;
        else    return b.size()<a.size()?a.size():b.size();
    }
};
*/