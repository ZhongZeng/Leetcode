
/*
Leetcode 408. Valid Word Abbreviation

Companies 
Google
Related Topics 
String
Similar Questions 
Minimum Unique Word Abbreviation, Word Abbreviation

Next challenges: Minimum Unique Word Abbreviation, Word Abbreviation

Test Cases:
"intern"
"i4n"
"internationalization"
"i12iz4n"
"a"
"01"
"abbreviation"
"a10n"

Runtime: 10 ms
Your runtime beats 6.07 % of cpp submissions.

*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        // Assume s contains only lowercase letters and abbr contains only lowercase letters and digits. 
        // '0' in abbr is not valid 
        int i, j, num;
        for( i=0, j=0; i<word.size()&&j<abbr.size(); ){
            if(isNum(abbr[j])){
                if(abbr[j]=='0')    return false;
                for( num=0; j<abbr.size()&&isNum(abbr[j]); j++) num=num*10+abbr[j]-'0';
                i+=num;
            }else{
                if(word[i]!=abbr[j]){
                    //cout<<i<<","<<j<<endl;
                    return false;
                }else{
                    i++;
                    j++;
                }    
            }
        }

        return i==word.size()&&j==abbr.size();
    }
    
    bool isNum(char& c){
        return -1<c-'0'&&c-'0'<10;
    }
};
