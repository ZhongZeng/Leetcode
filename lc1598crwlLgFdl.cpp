/*
1598. Crawler Log Folder

Companies:	Mercari 
Related Topics:	Stack
Similar Questions: Baseball Game, Backspace String Compare

Runtime: 12 ms	Your runtime beats 5.52 % of cpp submissions.
Memory Usage: 10.5 MB	Your memory usage beats 31.68 % of cpp submissions.
*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        
        for( int i=0; i<logs.size(); i++){
            if(logs[i][0]=='.'&&logs[i][1]=='.'){
                if(0<depth) depth--;
            }else if(logs[i][0]=='.'&&logs[i][1]=='/'){
            }else{
                depth++;
            }
        }
        
        return depth;
    }
};