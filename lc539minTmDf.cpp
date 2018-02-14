
/*
Leetcode 539. Minimum Time Difference

Related Topics 
String


Test Cases:
["23:59","00:00"]
["1:40","1:20","02:01"]

Next challenges: Simplify Path, Word Ladder II, Repeated Substring Pattern

Runtime: 17 ms
Your runtime beats 76.76 % of cpp submissions.

*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int mn=1441;
        vector<int> vc;
        for(int i=0; i<timePoints.size(); i++){
            vc.push_back(toTime(timePoints[i]));
            //cout<<vc.back()<<" ";
        }
        
        sort(vc.begin(), vc.end());
        
        for(int i=1; i<vc.size(); i++)  mn=vc[i]-vc[i-1]<mn?vc[i]-vc[i-1]:mn;
        
        mn=vc[0]+1440-vc.back()<mn?vc[0]+1440-vc.back():mn;
        
        return mn;
    }
    
    int toTime(string& s){
        int h=0 , m=0, i=-1;
        while(s[++i]!=':')  h=h*10+s[i]-'0';
        while(++i<s.size()) m=m*10+s[i]-'0';
        
        return h*60+m;
    }
};