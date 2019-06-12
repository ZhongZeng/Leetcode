/*
1078. Occurrences After Bigram

Related Topic	Hash Table

Test Cases:
"alice is a good girl she is a good student"
"a"
"good"
"we will we will rock you"
"we"
"will"

Next challenges: Sudoku Solver, Design HashSet, Maximum Frequency Stack

Runtime: 0 ms
Memory Usage: 8.7 MB
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        // O(m+n+k) time, m, n, k being the sizes of text, first, second 
        vector<string> rt;
        vector<bool> vb={false,false,false,false};// 2nd last: match first, match second; last: match first, match second
        text.push_back(' ');// for convenience 
        for( int i=0, j; i<text.size(); i=j+1){// [i,j) 
            for( j=i; text[j]!=' '; j++){}
            if(vb[0]==true&&vb[3]==true){// append word
                rt.push_back("");
                for( int k=i; k<j; k++) rt.back().push_back(text[k]);
            }
            // above code needs to placed before the following code 
            vb[0]=vb[2];
            vb[1]=vb[3];
            vb[2]=matchWord( text, i, j, first);
            vb[3]=matchWord( text, i, j, second);
        }
        return rt;
    }
    
protected:
    bool matchWord(string& text, int b, int e, string& first){
        int k, l;
        for( k=b, l=0; k<e&&l<first.size(); k++, l++){
            if(text[k]!=first[l])   return false;
        }
        return k==e&&l==first.size();
    }
};