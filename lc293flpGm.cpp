
/*
Leetcode 293. Flip Game

Companies 
Google 
Related Topics 
String 
Similar Questions 
Flip Game II

Test Cases:
"++++"
"---+++-+++-+"
""

Runtime: 3 ms
Your runtime beats 0.00 % of cpp submissions. which is with in majority 

*/


class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        // after one valid move
        vector<int> vc;
        int sum=0;
        string t;
        for(int i=1; i<s.size(); i++){
            if(s[i-1]=='+'&&s[i]=='+'){
                sum++;
                vc.push_back(i);
            }
        }
        
        vector<string> vs(sum, s);
        
        for(int i=0; i<vc.size(); i++){
            vs[i][vc[i]]='-';
            vs[i][vc[i]-1]='-';
        }
        
        return vs;
    }
};

/*
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        // after one valid move
        vector<string> vs;
        string t;
        for(int i=1; i<s.size(); i++){
            if(s[i-1]=='+'&&s[i]=='+'){
                t.clear();
                for(int j=0; j<s.size(); j++)   t.push_back(s[j]);
                t[i-1]='-';
                t[i]='-';
                vs.push_back(t);
            }
        }
        return vs;
    }
};
*/