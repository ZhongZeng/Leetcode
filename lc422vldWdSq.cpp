
/*
Leetcode 422. Valid Word Square

Companies 
Google
Similar Questions 
Word Squares, Toeplitz Matrix

Next challenges: Word Squares

Test Cases:
["abcd","bnrt","crmy","dtye"]
[  "abcd",  "bnrt",  "crm",  "dt"]
[  "ball",  "area",  "read",  "lady"]
["ball","asee","let","lep"]

Runtime: 16 ms
Your runtime beats 23.73 % of cpp submissions.

*/
 

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                if(words.size()-1<j||words[j].size()-1<i||words[i][j]!=words[j][i]){
                    //cout<<i<<","<<j<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};

/*
// This should fail, but it passes.
// Runtime: 18 ms
// Your runtime beats 23.73 % of cpp submissions.
 
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                if(words.size()-1<j||words[j].size()<i||words[i][j]!=words[j][i]){
                    //cout<<i<<","<<j<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};
*/

/*
// Runtime: 24 ms
// Your runtime beats 6.78 % of cpp submissions.
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int i, j;
        for( i=0; i<words.size(); i++){
            for( j=0; j<i&&j<words[i].size(); j++){
                if(words.size()-1<j||words[j].size()-1<i){
                    //cout<<i<<","<<j<<endl;
                    return false;
                }
            }
            while( ++j<words[i].size() ){
                if(words.size()-1<j||words[j].size()<i||words[i][j]!=words[j][i]){
                    //cout<<i<<","<<j<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};
*/