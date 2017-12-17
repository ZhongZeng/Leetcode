

/*
Leetcode 345. Reverse Vowels of a String

Related Topics 
Two Pointers, String
Similar Questions 
Reverse String
Next challenges: Scramble String,
Construct String from Binary Tree, Add Bold Tag in String

Test Cases；
"hello"
"leetcode"

Runtime: 9 ms
Your runtime beats 53.43 % of cpp submissions.

*/

class Solution {
public:
    string reverseVowels(string s) {
        char t;
        for(int i=0, j=s.size()-1; i<j; i++){
            if(isV(s[i])){
                while(!isV(s[j]))   j--;
                t=s[j];
                s[j]=s[i];
                s[i]=t;
                j--;
                //cout<<s[i]<<"-"<<s[j]<<" ";
            }
        }
        return s;
    }
    
protected:
    bool isV(char & c){
        switch(c){
            case 'a': return true;
            case 'e': return true;
            case 'i': return true;
            case 'o': return true;
            case 'u': return true;
            case 'A': return true;
            case 'E': return true;
            case 'I': return true;
            case 'O': return true;
            case 'U': return true;
            default: return false;                
        }
    }
    
};