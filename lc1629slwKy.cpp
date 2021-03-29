/*
1629. Slowest Key

Easy 

Companies:	Amazon
Related Topics:	Array

Runtime: 12 ms	Your runtime beats 26.77 % of cpp submissions.
Memory Usage: 10.9 MB	Your memory usage beats 8.64 % of cpp submissions.
*/

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int max_duration=releaseTimes[0];
        char c=keysPressed[0];
        for( int i=1; i<releaseTimes.size(); i++){
            if(max_duration<releaseTimes[i]-releaseTimes[i-1]){
                max_duration=releaseTimes[i]-releaseTimes[i-1];
                c=keysPressed[i];
            }else if(max_duration==releaseTimes[i]-releaseTimes[i-1]){
                c=c<keysPressed[i]?keysPressed[i]:c;
            }
        }
        return c;
    }
};