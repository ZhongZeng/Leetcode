/*
1024. Video Stitching

Companies	Google
Related Topics	Dynamic Programming (Greedy suggedted)

Test Cases:
[[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]
10
[[0,1],[1,2]]
5
[[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]]
9
[[0,4],[2,8]]
5

Runtime: 8 ms
Memory Usage: 9.1 MB
Your runtime beats 36.58 % of cpp submissions.

Next challenges: Create Maximum Number, 
Count Different Palindromic Subsequences, Find the Shortest Superstring
*/

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        // greedy, sort; O(n*log(n)) time; [0,T], clips.size() in [1,100], T in [0,100]
        // each clip will not be cut into >2 pieces; return # of clips not cut pieces 
        if(T==0)    return 0;
        int rt=0, t=0, xt;// xt:next t
        sort( clips.begin(), clips.end(), lessThan);
        
        for( int i=0; i<clips.size()&&t<T; ){// (,T] covered by clips(,i) 
            for( xt=t; i<clips.size(); i++){
                if(clips[i][0]<=t)  xt=clips[i][1]<xt?xt:clips[i][1];// greedy, extend to longest 
                else    break;
            }
            if(xt==t)   return -1;
            
            rt++;
            t=xt;
        }
        
        return T<=t?rt:-1;
    }
    
protected:
    static bool lessThan( vector<int>& c1, vector<int>& c2 ){
        if(c1[0]<c2[0]) return true;
        else if(c2[0]<c1[0])    return false;
        else    return c1[1]>c2[1];
        return true;// won't be triggered 
    }
};