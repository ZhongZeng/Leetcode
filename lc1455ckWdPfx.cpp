/*
1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

Ranking of Weekly Contest 190  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
2744 / 11873	zhongzeng 	12	0:27:32	 0:10:20	 0:14:15	 0:27:32

Company	Yelp
Related Topics	String

Test Cases:
"i love eating burger"
"burg"
"this problem is an easy problem"
"pro"
"i am tired"
"you"
"i use triple pillow"
"pill"
"hello from the other side"
"they"

Runtime: 0 ms
Memory Usage: 6.2 MB
*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // O(n) time
        int i, b, idx;
        for( i=0, b=0, idx=1; i<sentence.size(); i++){
            if(sentence[i]==' '){
                if(isPrefix(sentence, searchWord, b, i))    return idx;
                idx++;
                b=i+1;
            }
        }
        if(isPrefix(sentence, searchWord, b, i))    return idx;
        return -1;
    }
    
protected:
    int isPrefix(string & sentence, string & searchWord, int b, int e){
        if(e-b<searchWord.size())   return false;
        for( int i=b, j=0; j<searchWord.size(); i++, j++){
            if(sentence[i]!=searchWord[j])  return false;
        }
        return true;
    }
};