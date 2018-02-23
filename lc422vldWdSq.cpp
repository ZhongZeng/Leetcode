
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

Runtime: 18 ms
Your runtime beats 23.73 % of cpp submissions.

*/

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